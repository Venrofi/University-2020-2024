export interface Movie {
  title: string;
  year: number;
  genre: string;
  director: string;
  watched?: boolean;
}

export interface MovieWithId extends Movie {
  id: string;
}

export function movieMapper(movie: Movie) {
  return {
    ...movie,
    watched: movie.watched || false
  }
}
