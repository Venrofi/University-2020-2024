import { Component, OnInit } from '@angular/core';
import { Observable, of } from 'rxjs';
import { CityGroup, citySuggestions } from 'src/app/city-suggestions';
import { WeatherService } from '../weather.service';

@Component({
  selector: 'app-normal-display',
  templateUrl: './normal-display.component.html',
  styleUrls: ['./normal-display.component.scss']
})
export class NormalDisplayComponent implements OnInit {

  inputValue = '';
  searchMessage = 'Check the latest weather in your city!';
  weatherData: any = {};
  weatherIcon: any;
  toggleImperialUnits = false;

  citySuggestions: CityGroup[] = citySuggestions;
  filteredCities$: Observable<CityGroup[]> = of(citySuggestions);

  constructor(private weatherService: WeatherService) { }

  ngOnInit(): void { }

  // City input
  inputValueChange(value: string) {
    this.filteredCities$ = of(this.filter(value));
  }

  onKeyPress(event: any) {
    if(event.key === 'Enter' && this.inputValue !== '') {
      this.searchWeather(this.inputValue);
    }
  }

  // Suggestions filtering
  private filterCities(cities: string[], filterValue: string) {
    return cities.filter(optionValue => optionValue.toLowerCase().includes(filterValue));
  }

  private filter(value: string): CityGroup[] {
    const filterValue = value.toLowerCase();
    return this.citySuggestions
      .map(cityGroup => {
        return {
          name: cityGroup.name,
          cities: this.filterCities(cityGroup.cities, filterValue),
        }
      })
      .filter(group => group.cities.length);
  }

  trackByName(index: any, item: any) {
    return item.name;
  }

  // Weather data units toggle
  onUnitsToggleChange() {
    if(this.inputValue !== '') {
      this.searchWeather(this.inputValue);
    }
  }

  // Check if weather data HTML elements should be displayed
  isWeatherDataEmpty() {
    return Object.keys(this.weatherData).length === 0;
  }

  // Time & Data formatting with timezone adjustment
  getLocalTime(date: number, timezone: number) {
    return new Date((date + timezone) * 1000).toUTCString().slice(-12, -4);
  }

  getDate(date: number) {
    return new Date(date * 1000).toLocaleDateString();
  }

  // Switch to accessibility mode
  accessibilityMode() {
    console.log('Accessibility mode activated!');
  }

  // Call API to get weather data
  searchWeather(cityQuery: string) {
    if(cityQuery.length > 0) {
      this.searchMessage = "Searching for weather in " + cityQuery + "...";

      let unitType = this.toggleImperialUnits ? 'imperial' : 'metric';

      this.weatherService.getWeather(cityQuery, unitType).subscribe(data => {
        this.weatherData = data
        console.log('Weather found: ', this.weatherData);
        this.searchMessage = "Weather in " + cityQuery + " is " + this.weatherData?.weather[0].description;
        this.weatherIcon = `http://openweathermap.org/img/wn/${this.weatherData?.weather[0]?.icon}@2x.png`
      }, error => {
        console.error(error);
        this.searchMessage = "No data found for specified city.";
        this.weatherData = {};
        this.weatherIcon = '';
      });
    }
  }
}
