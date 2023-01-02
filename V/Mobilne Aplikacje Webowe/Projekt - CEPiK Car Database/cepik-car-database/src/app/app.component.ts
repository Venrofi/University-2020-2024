import { Component, OnInit } from '@angular/core';
import axios from 'axios';
import{ Constants } from './config/constants';
import { ApiHttpService } from './services/api-http.service';
import { DataService } from './services/data.service';
@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss'],
  providers: [ApiHttpService, DataService]
})
export class AppComponent{}

/*
  java -jar swagger-codegen-cli.jar generate -i https://api.cepik.gov.pl -l typescript-angular -o /Desktop/Programmin'/2022/WEB DEV/Angular/CEPiK Car Database 30.10.2022/cepik-car-database/src/app/API --additional-properties npmName=@gov/cepik-api,snapshot=true,ngVersion=13.0.0

  java -jar swagger-codegen-cli.jar generate -i https://api.cepik.gov.pl -l typescript-angular -o /cepik-car-database/src/app/API --additional-properties npmName=@gov/cepik-api,snapshot=true,ngVersion=13.0.0

  java -jar swagger-codegen-cli.jar generate -i https://api.angular.schule/swagger.json -l typescript-angular -o /test-api --additional-properties npmName=@angular-schule/book-monkey-api,snapshot=true,ngVersion=5.0.0

  java -jar swagger-codegen-cli.jar generate -i https://api.cepik.gov.pl -l typescript-angular -o /test-api --additional-properties npmName=@gov/cepik-api,snapshot=true
*/
