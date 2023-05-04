import { Component, OnInit, ViewChild } from '@angular/core';
import { MatTableDataSource } from '@angular/material/table';
import { MatPaginator } from '@angular/material/paginator';
import { MatSort } from '@angular/material/sort';
import { AddEditMovieComponent } from '../add-edit-movie/add-edit-movie.component';
import { MoviesService } from '../movies.service';
import { MatDialog, MatDialogConfig } from '@angular/material/dialog';
import { Movie } from '../movie.model';

@Component({
  selector: 'app-movie-list',
  templateUrl: './movie-list.component.html',
  styleUrls: ['./movie-list.component.scss']
})

export class MovieListComponent implements OnInit {
  displayedColumns: string[] = ['title', 'year', 'director', 'watched'];
  dataSource: MatTableDataSource<Movie>;

  @ViewChild(MatPaginator) paginator!: MatPaginator;
  @ViewChild(MatSort) sort!: MatSort;

  constructor(private moviesService: MoviesService, private dialog: MatDialog) {
    this.dataSource = new MatTableDataSource();
    this.dataSource.paginator = this.paginator;
    this.dataSource.sort = this.sort;
  }

  ngOnInit() {
    // initialMovies.forEach(movie => {
    //   this.moviesService.addMovie(movie);
    //   console.log('Movie added: ', movie);
    // });

    this.moviesService.getMovies().subscribe(movies => {
      console.log('Movies: ', movies);
      this.dataSource = new MatTableDataSource(movies);
      this.dataSource.paginator = this.paginator;
      this.dataSource.sort = this.sort;
    });
  }

  openEditMovieDialog(movie: Movie) {
    const dialogConfig = new MatDialogConfig();
    dialogConfig.data = {
      operation: 'EDIT',
      movie: movie
    };
    this.dialog.open(AddEditMovieComponent, dialogConfig);
  }

  applyFilter(event: Event) {
    const filterValue = (event.target as HTMLInputElement).value;
    this.dataSource.filter = filterValue.trim().toLowerCase();

    if (this.dataSource.paginator) {
      this.dataSource.paginator.firstPage();
    }
  }
}
