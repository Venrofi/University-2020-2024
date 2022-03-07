import java.io.*;
import java.util.ArrayList;
import java.util.*;

public class E4_2 {
    public static void main(String[] args) throws FileNotFoundException {
        try {
            File plik = new File("zadanie2.txt");
            Scanner scan = new Scanner(plik);
            Algorytm alg = new Algorytm();
            ArrayList<Integer> dane = new ArrayList<>();

            while (scan.hasNextInt()) {
                dane.add(scan.nextInt());
            }
            scan.close();

            System.out.println("Dane:");
            for (int liczba : dane) {
                System.out.println(liczba);
            }

            alg.quickSort(dane, 0, dane.size());

            File wynik = new File("zadanie2_wynik.txt");
            FileWriter zapisz = new FileWriter("zadanie2_wynik.txt");
            wynik.createNewFile();

            System.out.println("Posortowane dane: ");
            for (int liczba : dane) {
                System.out.println(liczba);
                zapisz.write(String.valueOf(liczba) + '\n');
            }
            zapisz.close();

        } catch (Exception e) {
            System.out.print("Wystąpił błąd! \n" + e);
        }
    }
}

class Algorytm {
    static int partition(ArrayList<Integer> dane, int low, int high) {
        int pivot = dane.get(high);
        int i = (low - 1);

        for (int j = low; j < high; j++) {
            if (dane.get(j) <= pivot) {
                i++;
                int a = dane.get(i);
                int b = dane.get(j);
                dane.set(i, b);
                dane.set(j, a);
            }

        }
        int a = dane.get(i + 1);
        int b = dane.get(high);
        dane.set(i + 1, b);
        dane.set(high, a);

        return (i + 1);
    }

    static void quickSort(ArrayList<Integer> dane, int low, int high) {
        if (low < high) {
            int pi = partition(dane, low, high);
            quickSort(dane, low, pi - 1);
            quickSort(dane, pi + 1, high);
        }
    }
}