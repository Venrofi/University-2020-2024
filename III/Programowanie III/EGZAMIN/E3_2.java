import java.io.*;
import java.util.ArrayList;
import java.util.*;

public class E3_2 {
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
            alg.mergeSort(dane, 0, dane.size());

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
    void merge(ArrayList<Integer> dane, int p, int q, int r) {
        int n1 = q - p + 1;
        int n2 = r - q;

        int L[] = new int[n1];
        int M[] = new int[n2];

        for (int i = 0; i < n1; i++)
            L[i] = dane.get(p + i);
        for (int j = 0; j < n2; j++)
            M[j] = dane.get(q + 1 + j);

        int i, j, k;
        i = 0;
        j = 0;
        k = p;

        while (i < n1 && j < n2) {
            if (L[i] <= M[j]) {
                dane.set(k, L[i]);
                i++;
            } else {
                dane.set(k, M[i]);
                j++;
            }
            k++;
        }

        while (i < n1) {
            dane.set(k, L[i]);
            i++;
            k++;
        }

        while (j < n2) {
            dane.set(k, M[j]);
            j++;
            k++;
        }
    }

    void mergeSort(ArrayList<Integer> dane, int l, int r) {
        if (l < r) {
            int m = (l + r) / 2;

            mergeSort(dane, l, m);
            mergeSort(dane, m + 1, r);
            merge(dane, l, m, r);
        }
    }
}