import java.io.*;
import java.util.ArrayList;
import java.util.*;

public class E1_2 {
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
            dane = alg.bubbleSort(dane);

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
    public ArrayList<Integer> bubbleSort(ArrayList<Integer> dane) {
        for (int i = 0; i < dane.size() - 1; i++) {
            for (int j = 0; j < dane.size() - i - 1; j++) {
                int a = dane.get(j);
                int b = dane.get(j + 1);
                if (a > b) {
                    dane.set(j, b);
                    dane.set(j + 1, a);
                }
            }
        }

        return dane;
    }
}