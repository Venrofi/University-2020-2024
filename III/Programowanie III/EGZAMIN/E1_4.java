import java.text.Collator;
import java.util.Arrays;
import java.util.Locale;

class Ksiazka implements Comparable {
    private String tytul;

    public Ksiazka(String tytul) {
        this.tytul = tytul;
    }

    public String getTytul() {
        return tytul;
    }

    private int compareIgnoreCase(String a1, String a2) {
        Locale locale = new Locale("pl", "PL");
        Collator col = Collator.getInstance(locale);
        col.setStrength(Collator.PRIMARY);
        return col.compare(a1.toUpperCase(locale), a2.toUpperCase(locale));
    }

    @Override
    public int compareTo(Object obj) {
        if (this == obj)
            return 0;
        if (this.getClass() != obj.getClass())
            return 1;
        return compareIgnoreCase(this.tytul, ((Ksiazka) obj).tytul);
    }
}

public class E1_4 {
    public static void main(String[] args) {
        Ksiazka[] ksiazki = new Ksiazka[5];
        ksiazki[0] = new Ksiazka("Niezniszczalny");
        ksiazki[1] = new Ksiazka("Wizjoner z Maranello");
        ksiazki[2] = new Ksiazka("Wieczny Ayrton Senna");
        ksiazki[3] = new Ksiazka("How to Build a Car");
        ksiazki[4] = new Ksiazka("Rywalizacja Totalna");

        Arrays.sort(ksiazki);

        for (Ksiazka kontent : ksiazki) {
            System.out.println(kontent.getTytul());
        }
    }
}