import { Component, OnChanges, OnInit, SimpleChanges } from '@angular/core';
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

  constructor(private weatherService: WeatherService) { }

  ngOnInit(): void {}

  onToggleChange() {
    console.log('Toggle value changed:', this.toggleImperialUnits);
    if(this.inputValue !== '') {
      this.searchWeather(this.inputValue);
    }
  }

  isWeatherDataEmpty() {
    return Object.keys(this.weatherData).length === 0;
  }

  getTime(date: any) {
    return new Date(date * 1000).toLocaleTimeString();
  }

  getDate(date: any) {
    return new Date(date * 1000).toLocaleDateString();
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
