// Projekt zaliczeniowy Radosław Terelak 4G
// Algorytmion 2011 - Zadanie 1 "Monety"

package projekt_terelak;

import java.util.*;
import java.io.*;

public class Projekt_Terelak {
    
    public static void wczytajDane() throws FileNotFoundException, IOException{
        System.out.println("Wczytuje dane..");
        File folder_in = new File("IN");
        Scanner scan = new Scanner(System.in);
        
        FilenameFilter textFilter = new FilenameFilter() {
            public boolean accept(File dir, String name) {
                return name.toLowerCase().endsWith(".txt");
            }
        };
        
        File[] dane = folder_in.listFiles(textFilter);
        for (File plik : dane) {
            System.out.println("\nOtwieram plik: " + plik.getCanonicalPath());
            scan = new Scanner(plik);
            
            try{
                char nr_pliku = plik.getName().charAt(5);
                int ile_workow = Integer.parseInt(scan.nextLine());
                String[] monety = scan.nextLine().split(";");
                int waga = Integer.parseInt(scan.nextLine());

                System.out.println("Nr pliku: " + nr_pliku + " Liczba worków: " + ile_workow + " Waga: " + waga);
                System.out.print("Ilość wyciągniętych monet: ");
                for (String moneta : monety) {
                    System.out.print(moneta + ", ");
                }
                if(monety.length == ile_workow){
                    sprawdzDane(ile_workow, monety, waga, nr_pliku);
                }
                else{
                    System.out.print("\nPodano złe dane! \n");
                } 
            }
            catch(Exception e){
                System.out.print("Podano złe dane! " + e + "\n");
            }
        }
    }
    
    public static void sprawdzDane(int ile_workow, String[] monety, int waga, char nr_pliku) throws FileNotFoundException {
        try{
            System.out.println("\nSprawdzam dane..");
            int suma_wag = 0;
            boolean znaleziono = false;

            for (String moneta : monety) {
                if(Integer.parseInt(moneta) <= 0){
                    System.out.println("Podano nieprawidłowe dane!");
                    return;
                }
                else{
                    suma_wag += Integer.parseInt(moneta) * 3;
                }
            }

            if(suma_wag == waga){
                System.out.println("Nie ma worka z fałszywymi monetami!");
                zapiszWynik("Nie ma worka z fałszywymi monetami!", nr_pliku);
                return;
            }

            for(int i=0; i<ile_workow; i++){
                int waga_falsz = Integer.parseInt(monety[i]) * 2;
                int waga_pozostale = 0;
                int nr_worka = i + 1;

                for(int j=0; j<ile_workow; j++){
                    if(j != i){
                        waga_pozostale += Integer.parseInt(monety[j]) * 3;
                    }
                }
                if(waga_falsz + waga_pozostale == waga){
                    znaleziono = true;
                    System.out.println("Fałszywym jest worek o numerze: " + nr_worka);
                    zapiszWynik("Fałszywym jest worek o numerze: " + nr_worka, nr_pliku);
                    return;
                }
            }
            if(znaleziono == false){
                System.out.println("Dokonaj wyciągnięcia monet jeszcze raz!");
            }
        }
        catch(Exception e){
            System.out.println("Podano nieprawidłowe dane! " + e);
        }
    }
    
    public static void zapiszWynik(String komunikat, char nr_pliku) throws FileNotFoundException{
        try{
            System.out.println("Wynik..");
            new File("OUT").mkdir();
            String plik_wynikowy = "wynik_" + nr_pliku + ".txt";
            File wynik = new File("OUT\\" + plik_wynikowy);
            FileWriter zapisz = new FileWriter("OUT\\" + plik_wynikowy);
            wynik.createNewFile();
            zapisz.write(komunikat);
            zapisz.close();
            System.out.println("Wynik zapisano w pliku: " + wynik.getAbsolutePath());
        }
        catch(IOException e){
            System.out.println("\nNie udało się zapisać wyniku do pliku :(");
            System.out.println(e);
        }
    }
    
    public static void main(String[] args) throws FileNotFoundException, IOException{
        wczytajDane();
    }
}