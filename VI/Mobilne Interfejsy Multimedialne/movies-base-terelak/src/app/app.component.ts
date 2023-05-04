import { MatDialog, MatDialogConfig } from '@angular/material/dialog';
import { Component } from '@angular/core';
import { AddEditMovieComponent } from './add-edit-movie/add-edit-movie.component';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent {
  title = 'movies-base-terelak';

  constructor(private dialog: MatDialog) {}

  openAddMovieDialog() {
    const dialogConfig = new MatDialogConfig();
    dialogConfig.data = {
      operation: 'ADD'
    };
    this.dialog.open(AddEditMovieComponent, dialogConfig);
  }
}
