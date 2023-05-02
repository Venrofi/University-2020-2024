import { MoviesService } from './movies.service';
import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent implements OnInit {
  title = 'movies-base-terelak';

  initialMovies = [  {    "id": "tt1375666",    "title": "Inception",    "year": 2010,    "genre": "Action, Adventure, Sci-Fi",    "director": "Christopher Nolan"  },  {    "id": "tt0468569",    "title": "The Dark Knight",    "year": 2008,    "genre": "Action, Crime, Drama",    "director": "Christopher Nolan"  },  {    "id": "tt6751668",    "title": "Parasite",    "year": 2019,    "genre": "Comedy, Drama, Thriller",    "director": "Bong Joon Ho"  },  {    "id": "tt1201607",    "title": "Harry Potter and the Deathly Hallows: Part 2",    "year": 2011,    "genre": "Adventure, Drama, Fantasy",    "director": "David Yates"  },  {    "id": "tt0477348",    "title": "No Country for Old Men",    "year": 2007,    "genre": "Crime, Drama, Thriller",    "director": "Ethan Coen, Joel Coen"  },  {    "id": "tt1392190",    "title": "Mad Max: Fury Road",    "year": 2015,    "genre": "Action, Adventure, Sci-Fi",    "director": "George Miller"  },  {    "id": "tt0266697",    "title": "Kill Bill: Vol. 1",    "year": 2003,    "genre": "Action, Crime, Thriller",    "director": "Quentin Tarantino"  },  {    "id": "tt0816692",    "title": "Interstellar",    "year": 2014,    "genre": "Adventure, Drama, Sci-Fi",    "director": "Christopher Nolan"  },  {    "id": "tt0372784",    "title": "Batman Begins",    "year": 2005,    "genre": "Action, Adventure",    "director": "Christopher Nolan"  },  {    "id": "tt1345836",    "title": "The Dark Knight Rises",    "year": 2012,    "genre": "Action, Thriller",    "director": "Christopher Nolan"  }]

  constructor(private moviesService: MoviesService) {}

  ngOnInit() {
    // this.initialMovies.forEach(movie => {
    //   this.moviesService.addMovie(movie);
    //   console.log('Movie added: ', movie);
    // });

    this.moviesService.getMovies().subscribe(movies => {
      console.log('Movies: ', movies);
    });
  }

}
