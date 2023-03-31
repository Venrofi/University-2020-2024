import { Component, OnInit } from '@angular/core';
import { Observable, of } from 'rxjs';
import { CityGroup, citySuggestions } from 'src/app/city-suggestions';
import { WeatherService } from '../weather.service';

@Component({
  selector: 'app-simple-display',
  templateUrl: './simple-display.component.html',
  styleUrls: ['./simple-display.component.scss']
})
export class SimpleDisplayComponent implements OnInit {

  fontSize = 24;
  speechSynthesis = window.speechSynthesis;

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
        this.readAloudWeather(this.weatherData);
      }, error => {
        console.error(error);
        this.searchMessage = "No data found for specified city.";
        this.weatherData = {};
        this.weatherIcon = '';
      });
    }
  }

  // Speech synthesis
  readAloudWeather(weatherData: any) {
    let speech = new SpeechSynthesisUtterance();

    speech.lang = 'en-US';
    speech.text = `Current weather in ${weatherData?.name} is ${weatherData?.weather[0].description}.
    Temperature is ${weatherData?.main.temp} degrees ${this.toggleImperialUnits ? 'Fahrenheit' : 'Celsius'}.
    Humidity is ${weatherData?.main.humidity} percent.
    Wind speed is ${weatherData?.wind.speed} ${this.toggleImperialUnits ? 'miles per hour' : 'meters per second'}.`;

    // speech.lang = 'pl-PL';
    // speech.text = `Aktualna pogoda w ${weatherData?.name} to ${weatherData?.weather[0].description}.
    // Temperatura wynosi ${weatherData?.main.temp} stopni ${this.toggleImperialUnits ? 'Fahrenheita' : 'Celsjusza'}.
    // Wilgotność wynosi ${weatherData?.main.humidity} procent.
    // Prędkość wiatru wynosi ${weatherData?.wind.speed} ${this.toggleImperialUnits ? 'mil na godzinę' : 'metrów na sekundę'}.`;

    speech.volume = 1;
    speech.rate = 1;
    speech.pitch = 1;
    this.speechSynthesis.speak(speech);
  }
}
