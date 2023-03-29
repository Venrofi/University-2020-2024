import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Observable } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class WeatherService {

  API_KEY: string  = '5414f34b79703f9e625a6cfce7cc3eab';
  API_KEY_BACKUP: string  = 'b31c2399a91bd7f2a5019bbe3fa1e049';

  constructor(private http: HttpClient) { }

  getWeather(city: string): Observable<any> {
    const url = `https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${this.API_KEY}&units=metric}`;
    return this.http.get(url);
  }
}
