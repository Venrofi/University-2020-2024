import { Component, OnInit } from '@angular/core';
import axios from 'axios';
import { Constants } from 'src/app/config/constants';
import { ApiHttpService } from 'src/app/services/api-http.service';
import { DataService } from 'src/app/services/data.service';

@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.scss']
})
export class HomeComponent implements OnInit {
    title = Constants.TitleOfSite;
    tempCarsData: any;
    listaWojewodztw: any;
    queryDate: string = '';

    constructor(private api: ApiHttpService, private dataService: DataService) { }

    getCarsData(wojID: string, wojName: string) {
      this.dataService.wojName = wojName;

      axios.get(Constants.API_PROXY_ENDPOINT + '/pojazdy', {params: {wojID: wojID, dataOd: this.queryDate}}).then(data =>{
        this.tempCarsData = data;
        this.tempCarsData = this.tempCarsData.data.data;
        this.dataService.setCarsData(this.tempCarsData);
      })
    }

    getRandomQueryDate(){
      let date = new Date();

      function randomNumber(min: number, max: number) {
        return Math.random() * (max - min) + min;
      }

      date.setFullYear( date.getFullYear() - randomNumber(0,2));
      date.setMonth(randomNumber(1, 13));
      date.setDate(randomNumber(1, 29));

      this.queryDate = date.toISOString().split('T')[0];
      this.queryDate = this.queryDate.split('-').join('');
    }

    ngOnInit() {
        this.getRandomQueryDate();

        this.api.get('/slowniki/wojewodztwa').subscribe(data =>{
          this.listaWojewodztw = data;
          this.listaWojewodztw = this.listaWojewodztw.data.attributes['dostepne-rekordy-slownika']
            .filter((wojewodztwo: any) => wojewodztwo['klucz-slownika'] !== 'XX');
        });
    }
}
