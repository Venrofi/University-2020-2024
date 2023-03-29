import { Component, OnInit } from '@angular/core';
import { Subscription, Observable } from 'rxjs';
import { WeatherService } from '../weather.service';

@Component({
  selector: 'app-normal-display',
  templateUrl: './normal-display.component.html',
  styleUrls: ['./normal-display.component.scss']
})
export class NormalDisplayComponent implements OnInit {

  inputValue = '';
  searchMessage = '';
  weatherData: any = {};

  constructor(private weatherService: WeatherService) { }

  ngOnInit(): void { }

  searchWeather(cityQuery: string) {
    if(cityQuery.length > 0) {
      console.log("Searching for weather in " + cityQuery + "...");
      this.searchMessage = "Searching for weather in " + cityQuery + "...";

      this.weatherService.getWeather(cityQuery).subscribe(data => {
        this.weatherData = data
        console.log(this.weatherData);
        this.searchMessage = "Weather in " + cityQuery + " is " + this.weatherData.weather[0].description;
      });
    }
  }
}
