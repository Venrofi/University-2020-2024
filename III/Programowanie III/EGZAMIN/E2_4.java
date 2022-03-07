import java.text.Collator;
import java.util.Arrays;
import java.util.Locale;

class Plytoteka implements Comparable {
    private String album;

    public Plytoteka(String album) {
        this.album = album;
    }

    public String getAlbum() {
        return album;
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
        return compareIgnoreCase(this.album, ((Plytoteka) obj).album);
    }
}

public class E2_4 {
    public static void main(String[] args) {
        Plytoteka[] plyty = new Plytoteka[5];
        plyty[0] = new Plytoteka("Electric Ladyland");
        plyty[1] = new Plytoteka("Hotel California");
        plyty[2] = new Plytoteka("Bubba");
        plyty[3] = new Plytoteka("Circles");
        plyty[4] = new Plytoteka("Abbey Road");

        Arrays.sort(plyty);

        for (Plytoteka kontent : plyty) {
            System.out.println(kontent.getAlbum());
        }
    }
}