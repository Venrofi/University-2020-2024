import { MatDialog } from '@angular/material/dialog';
import { MoviesService } from './movies.service';
import { Component, OnInit } from '@angular/core';
import { AddEditMovieComponent } from './add-edit-movie/add-edit-movie.component';
import { initialMovies } from 'src/data/initial-movies';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent implements OnInit {
  title = 'movies-base-terelak';

  constructor(private moviesService: MoviesService, private dialog: MatDialog) {}

  ngOnInit() {
    // initialMovies.forEach(movie => {
    //   this.moviesService.addMovie(movie);
    //   console.log('Movie added: ', movie);
    // });

    this.moviesService.getMovies().subscribe(movies => {
      console.log('Movies: ', movies);
    });
  }

  openAddEditMovieDialog() {
    this.dialog.open(AddEditMovieComponent);
  }

}
