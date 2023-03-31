export const citySuggestions = [
  {
    name: 'Poland',
    cities: ["Bydgoszcz", "Gdańsk", "Gliwice", "Katowice", "Kielce", "Kraków", "Łódź", "Lublin", "Olsztyn", "Opole", "Płock", "Poznań", "Rzeszów", "Sopot", "Szczecin", "Toruń", "Warszawa", "Wrocław", "Zabrze", "Zakopane", "Zielona Góra"],
  },
  {
    name: 'Europe',
    cities: ["Amsterdam", "Athens", "Barcelona", "Berlin", "Brussels", "Budapest", "Copenhagen", "Dublin", "Edinburgh", "Florence", "Frankfurt", "Istanbul", "Lisbon", "London", "Madrid", "Milan", "Munich", "Paris", "Prague", "Rome", "Stockholm", "Vienna", "Zurich"],
  },
  {
    name: 'America',
    cities: ["New York", "Los Angeles", "Chicago", "Houston", "Toronto", "Montreal", "Vancouver", "Mexico City", "Monterrey", "Guadalajara", "Calgary", "Edmonton", "Ottawa", "Washington, D.C.", "San Francisco", "Boston", "Seattle", "Miami", "Atlanta", "Dallas", "São Paulo", "Rio de Janeiro", "Buenos Aires", "Lima", "Santiago", "Bogotá", "Caracas", "La Paz", "Quito", "Montevideo", "Asunción", "Sucre", "Córdoba", "Rosario", "Salvador", "Recife", "Fortaleza", "Curitiba", "Medellín", "Belém"],
  },
  {
    name: 'Asia',
    cities: ["Tokyo", "Beijing", "Shanghai", "Seoul", "Mumbai", "Delhi", "Bangkok", "Jakarta", "Manila", "Hong Kong", "Singapore", "Taipei", "Hanoi", "Ho Chi Minh City", "Kuala Lumpur", "Dubai", "Tel Aviv", "Mumbai", "Osaka", "Kyoto", "Busan"],
  }
];


export interface CityGroup {
  name: string;
  cities: string[];
}
