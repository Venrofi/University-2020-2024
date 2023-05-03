import { FormBuilder, FormGroup } from '@angular/forms';
import { genres } from './../../data/genres';
import { Component, OnInit } from '@angular/core';
import { MatDialogRef } from '@angular/material/dialog';
import { MoviesService } from '../movies.service';
import { Movie } from '../movie.model';

@Component({
  selector: 'app-add-edit-movie',
  templateUrl: './add-edit-movie.component.html',
  styleUrls: ['./add-edit-movie.component.scss']
})
export class AddEditMovieComponent implements OnInit {

  movieGenres = genres;

  currentYear = new Date().getFullYear();

  movieForm: FormGroup;

  constructor(private fb: FormBuilder, private movieService: MoviesService, private dialogRef: MatDialogRef<AddEditMovieComponent>) {
    this.movieForm = this.fb.group({
      title: '',
      year: parseInt(''),
      genre: '',
      director: '',
      watched: false,
    } as Movie);
  }

  ngOnInit(): void {
  }

  onSubmit() {
    if(this.movieForm.valid) {
      console.log('Movie sent: ', this.movieForm.value);
      this.movieService.addMovie(this.movieForm.value).catch(error => console.log('Error occured when adding a movie: ', error));
      this.dialogRef.close();
    }
  }

}
