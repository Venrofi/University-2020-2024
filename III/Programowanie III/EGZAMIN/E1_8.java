import java.io.*;
import java.util.ArrayList;
import java.util.*;

public class E1_8 {
    public static void main(String[] args) throws FileNotFoundException {
        try {
            Scanner scan = new Scanner(System.in);
            Algorytm alg = new Algorytm();
            ArrayList<Integer> dane = new ArrayList<>();

            System.out.println("Podaj dane: ");
            while (scan.hasNextInt()) {
                dane.add(scan.nextInt());
            }
            scan.close();
            System.out.println("Średnia arytmetyczna: " + alg.sredniaArytmetyczna(dane));

        } catch (Exception e) {
            System.out.print("Wystąpił błąd! \n" + e);
        }
    }
}

class Algorytm {
    public double sredniaArytmetyczna(ArrayList<Integer> dane) {
        double srednia = 0;
        int suma = 0;
        for (int liczba : dane) {
            suma += liczba;
        }
        srednia = suma / dane.size();
        return srednia;
    }
}