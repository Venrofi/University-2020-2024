import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent {
  title = 'weather-app-terelak';

  simpleMode: boolean = false;

  displayModeChange() {
    this.simpleMode = !this.simpleMode;
  }
}
