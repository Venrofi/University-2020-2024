import { MatDialog, MatDialogConfig } from '@angular/material/dialog';
import { MoviesService } from './movies.service';
import { Component, OnInit } from '@angular/core';
import { AddEditMovieComponent } from './add-edit-movie/add-edit-movie.component';
import { initialMovies } from 'src/data/initial-movies';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent {
  title = 'movies-base-terelak';

  constructor(private dialog: MatDialog) {}

  openAddEMovieDialog() {
    const dialogConfig = new MatDialogConfig();
    dialogConfig.data = {
      operation: 'ADD'
    };
    this.dialog.open(AddEditMovieComponent, dialogConfig);
  }
}
