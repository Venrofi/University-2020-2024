import java.util.*;

public class E1_1 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int a, h;

        do {
            System.out.print("Podaj krawędź a: ");
            while (!scan.hasNextInt()) {
                System.out.println("To nie jest liczba!");
                scan.next();
            }
            a = scan.nextInt();
        } while (a <= 0);

        do {
            System.out.print("Podaj wysokość h: ");
            while (!scan.hasNextInt()) {
                System.out.println("To nie jest liczba!");
                scan.next();
            }
            h = scan.nextInt();
        } while (h <= 0);
        scan.close();

        System.out.println(
                "Pole powierzchni bocznej prostopadłościana o krawędzi " + a + " oraz wysokości " + h + " wynosi: "
                        + Math.round(4 * a * h));
        System.out.println("Objętość prostopadłościana o promieniu " + a + " oraz wysokości " + h + " wynosi: "
                + Math.round(a * a * h));
    }
}