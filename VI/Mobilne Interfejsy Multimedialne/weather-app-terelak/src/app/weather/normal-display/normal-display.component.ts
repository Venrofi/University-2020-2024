import { Component, OnChanges, OnInit, SimpleChanges } from '@angular/core';
import { Observable, of } from 'rxjs';
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

  citySuggestions: CityGroup[] = [];
  filteredCities$: Observable<CityGroup[]> = of([]);

  constructor(private weatherService: WeatherService) { }

  ngOnInit(): void {
    this.citySuggestions = [
      {
        name: 'Poland',
        cities: ["Bydgoszcz", "Gdańsk", "Gliwice", "Katowice", "Kielce", "Kraków", "Łódź", "Lublin", "Olsztyn", "Opole", "Płock", "Poznań", "Rzeszów", "Sopot", "Szczecin", "Toruń", "Warszawa", "Wrocław", "Zabrze", "Zakopane", "Zielona Góra"],
      },
      {
        name: 'Europe',
        cities: ["Amsterdam", "Athens", "Barcelona", "Berlin", "Brussels", "Budapest", "Copenhagen", "Dublin", "Edinburgh", "Florence", "Frankfurt", "Istanbul", "Lisbon", "London", "Madrid", "Milan", "Munich", "Paris", "Prague", "Rome", "Stockholm", "Vienna", "Zurich"],
      },
      {
        name: 'America',
        cities: ["New York", "Los Angeles", "Chicago", "Houston", "Toronto", "Montreal", "Vancouver", "Mexico City", "Monterrey", "Guadalajara", "Calgary", "Edmonton", "Ottawa", "Washington, D.C.", "San Francisco", "Boston", "Seattle", "Miami", "Atlanta", "Dallas", "São Paulo", "Rio de Janeiro", "Buenos Aires", "Lima", "Santiago", "Bogotá", "Caracas", "La Paz", "Quito", "Montevideo", "Asunción", "Sucre", "Córdoba", "Rosario", "Salvador", "Recife", "Fortaleza", "Curitiba", "Medellín", "Belém"],
      },
      {
        name: 'Asia',
        cities: ["Tokyo", "Beijing", "Shanghai", "Seoul", "Mumbai", "Delhi", "Bangkok", "Jakarta", "Manila", "Hong Kong", "Singapore", "Taipei", "Hanoi", "Ho Chi Minh City", "Kuala Lumpur", "Dubai", "Tel Aviv", "Mumbai", "Osaka", "Kyoto", "Busan"],
      }
  ];

    this.filteredCities$ = of(this.citySuggestions);
    console.log(this.filteredCities$, this.citySuggestions);
  }

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

  trackByFn(index: any, item: any) {
    return item.name;
  }

  onModelChange(value: string) {
    this.filteredCities$ = of(this.filter(value));
  }

  onKeyPress(event: any) {
    if(event.key === 'Enter' && this.inputValue !== '') {
      this.searchWeather(this.inputValue);
    }
  }

  onToggleChange() {
    console.log('Toggle value changed:', this.toggleImperialUnits);
    if(this.inputValue !== '') {
      this.searchWeather(this.inputValue);
    }
  }

  isWeatherDataEmpty() {
    return Object.keys(this.weatherData).length === 0;
  }

  getLocalTime(date: number, timezone: number) {
    return new Date((date + timezone) * 1000).toUTCString().slice(-12, -4);
  }

  getDate(date: number) {
    return new Date(date * 1000).toLocaleDateString();
  }

  accessibilityMode() {
    console.log('Accessibility mode activated!');
  }

  searchWeather(cityQuery: string) {
    if(cityQuery.length > 0) {
      console.log("Searching for weather in " + cityQuery + "...");
      this.searchMessage = "Searching for weather in " + cityQuery + "...";

      let unitType = this.toggleImperialUnits ? 'imperial' : 'metric';

      this.weatherService.getWeather(cityQuery, unitType).subscribe(data => {
        this.weatherData = data
        console.log(this.weatherData);
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

export interface CityGroup {
  name: string;
  cities: string[];
}
