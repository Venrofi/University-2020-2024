import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Constants } from '../config/constants';

@Injectable()
export class ApiHttpService {
  constructor( private http: HttpClient ){};

  public get(url: string, options?: any){
    return this.http.get(Constants.API_PROXY_ENDPOINT + url, options);
  }
}
