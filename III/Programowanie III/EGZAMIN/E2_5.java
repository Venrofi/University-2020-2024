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

class Punkt3D extends Punkt2D {
    protected double z;

    public Punkt3D(double x, double y, double z) {
        super(x, y);
        this.z = z;
    }

    @Override
    public String toString() {
        return "Punkt3D{" + "x=" + x + ", y=" + y + ", z=" + z + "}";
    }
}

public class E2_5 {
    public static void main(String[] args) {
        Punkt2D pkt2D_1 = new Punkt2D(2, 2);
        Punkt3D pkt3D_1 = new Punkt3D(1, 2, 3);
        System.out.println(pkt2D_1.toString());
        System.out.println(pkt3D_1.toString());

        // Do poprawnego działania wymagany jest przynajmniej jeden konstruktor w klasie
        // Punkt2D oraz Punkt3D
        // Dodatkowo można by zaimplementować konstruktory domyślne, jak i metody
        // pozwalające nadpisać którąś współrzędną.
        // Metody toString() pozwalają na odczyt danych, które zostały wprowadzone przy
        // tworzeniu obiektu.
    }
}