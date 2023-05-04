import { FormBuilder, FormGroup } from '@angular/forms';
import { genres } from './../../data/genres';
import { Component, Inject, OnInit } from '@angular/core';
import { MAT_DIALOG_DATA, MatDialogRef } from '@angular/material/dialog';
import { MoviesService } from '../movies.service';
import { Movie, MovieWithId } from '../movie.model';
import { MatSnackBar } from '@angular/material/snack-bar';
import { OperationInfoSnackComponent } from '../operation-info-snack/operation-info-snack.component';

@Component({
  selector: 'app-add-edit-movie',
  templateUrl: './add-edit-movie.component.html',
  styleUrls: ['./add-edit-movie.component.scss']
})
export class AddEditMovieComponent implements OnInit {

  movieGenres = genres;

  currentYear = new Date().getFullYear();

  movieForm: FormGroup;

  constructor(
    @Inject(MAT_DIALOG_DATA) public data: { operation: string, movie: MovieWithId },
    private fb: FormBuilder,
    private movieService: MoviesService,
    private dialogRef: MatDialogRef<AddEditMovieComponent>,
    private snackBar: MatSnackBar) {
      this.movieForm = this.fb.group({
        title: '',
        year: parseInt(''),
        genre: '',
        director: '',
        watched: false,
      } as Movie);
  }

  ngOnInit(): void {
    if(this.data.operation === 'EDIT') {
      this.movieForm.patchValue(this.data.movie);
    }
  }

  onSubmit() {
    if(this.movieForm.valid && this.data.operation === 'ADD') {
      console.log('Movie sent: ', this.movieForm.value);
      this.movieService.addMovie(this.movieForm.value).catch(error => console.log('Error occured when adding a movie: ', error));
      this.dialogRef.close();
      this.snackBar.openFromComponent(OperationInfoSnackComponent, {
        duration: 2000,
        data: { message: 'Movie has been successfully added!' }
      });
    }
    else if(this.movieForm.valid && this.data.operation === 'EDIT') {
      console.log('Movie edited: ', this.movieForm.value);
      this.movieService.updateMovie(this.data.movie?.id, this.movieForm.value).catch(error => console.log('Error occured when editing a movie: ', error));
      this.dialogRef.close();
      this.snackBar.openFromComponent(OperationInfoSnackComponent, {
        duration: 2000,
        data: { message: 'Movie has been successfully edited!' }
      });
    }
  }

  deleteMovie() {
    console.log('Movie deleted: ', this.movieForm.value);
    this.movieService.deleteMovie(this.data.movie?.id).catch(error => console.log('Error occured when deleting a movie: ', error));
    this.dialogRef.close();
    this.snackBar.openFromComponent(OperationInfoSnackComponent, {
      duration: 2000,
      data: { message: 'Movie has been successfully deleted!' }
    });
  }
}
