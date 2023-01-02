import { Injectable } from '@angular/core';
import { BehaviorSubject, Observable } from 'rxjs';

@Injectable()
export class DataService {
  constructor(){};

  private _carsData: BehaviorSubject<any> = new BehaviorSubject<any>(null);
  private _carData: any = [];
  wojName: string = '';

  public setCarsData(data: any){
    this._carsData.next(data);
  }
  public getCarsData(): Observable<any> {
      return this._carsData.asObservable();
  }

  public setCarData(data: any){
    this._carData = data;
  }
  public getCarData(): Observable<any> {
    return this._carData;
  }
}
