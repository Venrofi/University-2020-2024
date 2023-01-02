import { Component, OnInit } from '@angular/core';
import { DataService } from 'src/app/services/data.service';

@Component({
  selector: 'app-pojazd',
  templateUrl: './pojazd.component.html',
  styleUrls: ['./pojazd.component.scss']
})
export class PojazdComponent implements OnInit {
  carName: string = '';
  carAttributes: any = [];

  constructor(private dataService: DataService) { }

  ngOnInit(): void {
    this.carAttributes = this.dataService.getCarData();
    this.carName = this.carAttributes.marka + " " + this.carAttributes.model;
  }

  resetData(){
    this.dataService.setCarData(null);
  }
}
