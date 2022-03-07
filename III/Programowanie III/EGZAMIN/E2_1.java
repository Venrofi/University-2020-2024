import java.util.*;

public class E2_1 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int r, h;

        do {
            System.out.print("Podaj promień r: ");
            while (!scan.hasNextInt()) {
                System.out.println("To nie jest liczba!");
                scan.next();
            }
            r = scan.nextInt();
        } while (r <= 0);

        do {
            System.out.print("Podaj wysokość h: ");
            while (!scan.hasNextInt()) {
                System.out.println("To nie jest liczba!");
                scan.next();
            }
            h = scan.nextInt();
        } while (h <= 0);
        scan.close();

        System.out.println("Pole powierzchni bocznej walca o promieniu " + r + " oraz wysokości " + h + " wynosi: "
                + Math.round(2 * Math.PI * r * h));
        System.out.println("Objętość walca o promieniu " + r + " oraz wysokości " + h + " wynosi: "
                + Math.round(Math.PI * r * r * h));
    }
}