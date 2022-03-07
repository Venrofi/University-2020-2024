import java.io.*;
import java.util.ArrayList;
import java.util.*;

public class E2_2 {
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

            dane = alg.insertionSort(dane);

            System.out.println("Posortowane dane: ");
            for (int liczba : dane) {
                System.out.println(liczba);
            }

        } catch (Exception e) {
            System.out.print("Wystąpił błąd! \n" + e);
        }
    }
}

class Algorytm {
    public ArrayList<Integer> insertionSort(ArrayList<Integer> dane) {
        for (int step = 1; step < dane.size(); step++) {
            int key = dane.get(step);
            int j = step - 1;
            while (j >= 0 && key < dane.get(j)) {
                int temp = dane.get(j);
                dane.set(j + 1, temp);
                --j;
            }
            dane.set(j + 1, key);
        }

        return dane;
    }
}