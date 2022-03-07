class Punkt2D {
    protected double x, y;

    public Punkt2D(double x, double y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public String toString() {
        return "Punkt2D{" + "x=" + x + ", y=" + y + "}";
    }
}

class Punkt2DKolor extends Punkt2D {
    protected int R, G, B;

    public Punkt2DKolor(double x, double y, int r, int g, int b) {
        super(x, y);
        if ((r >= 0 && r <= 255) && (g >= 0 && g <= 255) && (b >= 0 && b <= 255)) {
            this.R = r;
            this.G = g;
            this.B = b;
        } else {
            System.out.println("Wartość spoza zakresu!");
        }
    }

    @Override
    public String toString() {
        return "Współrzędne (x,y):" + x + " " + y + "  Kolor:" + R + " " + G + " " + B;
    }
}

public class E1_5 {
    public static void main(String[] args) {
        Punkt2D pkt2D_1 = new Punkt2D(2, 2);
        Punkt2DKolor pkt2Dkolor_1 = new Punkt2DKolor(4, 4, 0, 558, 128);
        System.out.println(pkt2D_1.toString());
        System.out.println(pkt2Dkolor_1.toString());

        // Do poprawnego działania wymagany jest przynajmniej jeden konstruktor w klasie
        // Punkt2D oraz Punkt2DKolor
        // Dodatkowo można by zaimplementować konstruktory domyślne, jak i metody
        // pozwalające nadpisać którąś współrzędną, bądź kolor.
        // Metody toString() pozwalają na odczyt danych, które zostały wprowadzone przy
        // tworzeniu obiektu.
    }
}