import java.io.*;
import java.util.Scanner;

public class E2_7 {
    public static void main(String[] args) throws IOException {
        try {
            File wynik = new File("Zadanie7.txt");
            FileWriter zapisz = new FileWriter("Zadanie7.txt", true);
            Scanner scan = new Scanner(System.in, "Cp1250");
            wynik.createNewFile();
            String wiersz = "";

            System.out.println("Podaj dane ('quit' by zakończyć): ");
            while (!scan.hasNext("quit")) {
                wiersz = scan.nextLine();
                zapisz.write(wiersz + '\n');
            }
            scan.close();
            zapisz.close();

        } catch (IOException e) {
            System.out.println("Coś się popsuło.." + e);
            return;
        }
    }
}