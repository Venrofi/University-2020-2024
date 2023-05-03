import { AngularFirestore, AngularFirestoreCollection } from '@angular/fire/compat/firestore';
import { Injectable } from '@angular/core';
import { Observable } from 'rxjs';
import { map } from 'rxjs/operators';
import { Movie } from './movie.model';

@Injectable({
  providedIn: 'root'
})
export class MoviesService {
  private moviesCollection: AngularFirestoreCollection<Movie>;
  movies: Observable<Movie[]>;

  constructor(private firestore: AngularFirestore) {
    this.moviesCollection = this.firestore.collection<Movie>('movies-collection');
    this.movies = this.moviesCollection.snapshotChanges().pipe(
      map(actions => {
        return actions.map(a => {
          const id = a.payload.doc.id;
          const data = a.payload.doc.data() as Movie;
          return { id, ...data };
        });
      })
    );
  }

  getMovies(): Observable<Movie[]> {
    return this.movies;
  }

  getMovie(id: string): Observable<Movie | undefined> {
    return this.moviesCollection.doc<Movie>(id).valueChanges();
  }

  addMovie(movie: Movie): Promise<void> {
    const id = this.firestore.createId();
    return this.moviesCollection.doc(id).set(movie);
  }

  updateMovie(id: string, movie: Movie): Promise<void> {
    return this.moviesCollection.doc(id).update(movie);
  }

  deleteMovie(id: string): Promise<void> {
    return this.moviesCollection.doc(id).delete();
  }
}
