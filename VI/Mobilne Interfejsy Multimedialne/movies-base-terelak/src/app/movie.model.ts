export interface Movie {
  title: string;
  year: number;
  genre: string;
  director: string;
  watched?: boolean;
}

export function movieMapper(movie: Movie) {
  return {
    ...movie,
    watched: movie.watched || false
  }
}
