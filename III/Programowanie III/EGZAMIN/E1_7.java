import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class E1_7 {
    public static void main(String[] args) throws FileNotFoundException {
        try {
            File plik = new File("Zadanie7.txt");
            Scanner scan = new Scanner(plik, "Cp1250");
            while (scan.hasNextLine()) {
                System.out.println(scan.nextLine());
            }
            scan.close();
        } catch (FileNotFoundException e) {
            System.out.println("Podana ścieżka jest niepoprawna lub plik nie istnieje!" + e);
            return;
        }
    }
}