package lab6_terelak;

import java.util.*;
import java.text.*;
import java.util.Arrays;
import java.util.Collections;

class Dane implements Comparable{
    private String nazwisko, telefon;
    public Dane(){};
    public Dane(String nazwisko, String telefon){
        this.nazwisko = nazwisko;
        this.telefon = telefon;
    }
    
    void ustawNazwisko(String nazwisko){
        this.nazwisko = nazwisko;
    }
    void ustawTelefon(String telefon){
        this.telefon = telefon;
    }
    void wypiszDane(){
        System.out.printf("Numer telefonu: " + this.telefon + "\nNazwisko właściciela: " + this.nazwisko);
    }
    @Override
    public String toString(){
        return String.format("%s %s", nazwisko, telefon);
    }
    
    private int compareIgnoreCase(String a1, String a2){
        Locale locale = new Locale("pl","PL");
        Collator col = Collator.getInstance(locale);
        col.setStrength(Collator.PRIMARY);
        return col.compare(a1.toUpperCase(locale), a2.toUpperCase(locale));
    }
    
    public int compareTo(Object obj){
        if(this == obj) return 0;
        if(this.getClass()!= obj.getClass()) return 1;
        Dane e = (Dane) obj;
        int t = compareIgnoreCase(this.nazwisko, e.nazwisko);
        return t;
    }  
}

class Pracownik implements Comparable{
    private int id_pracownika;
    private String nazwisko, stanowisko;
    public Pracownik(){};
    public Pracownik(int id, String nazwisko, String stanowisko){
        this.id_pracownika = id;
        this.nazwisko = nazwisko;
        this.stanowisko = stanowisko;
    }
    
    void ustawNazwisko(String nazwisko){
        this.nazwisko = nazwisko;
    }
    void ustawStanowisko(String stanowisko){
        this.stanowisko = stanowisko;
    }
    void wypiszDane(){
        System.out.printf("Nazwisko: " + this.nazwisko + "\nObejmowane stanowisko: " + this.stanowisko);
    }
    @Override
    public String toString(){
        return String.format("%d %s %s", id_pracownika ,nazwisko, stanowisko);
    }
    
    private int compareIgnoreCase(String a1, String a2){
        Locale locale = new Locale("pl","PL");
        Collator col = Collator.getInstance(locale);
        col.setStrength(Collator.PRIMARY);
        return col.compare(a1.toUpperCase(locale), a2.toUpperCase(locale));
    }
    
    public int compareTo(Object obj){
        if(this == obj) return 0;
        if(this.getClass()!= obj.getClass()) return 1;
        Pracownik e = (Pracownik) obj;
        int t = compareIgnoreCase(this.nazwisko, e.nazwisko);
        return t;
    }
}

public class Lab6_Terelak {

    public static void zad1(){
        Dane telefon = new Dane("Terelak", "692012537");
        telefon.wypiszDane();
    }
    
    public static void zad2(){
        Dane spis[] = new Dane[5];
        
        spis[0] = new Dane ("Terelak", "692012537");
        spis[1] = new Dane ("Tutaj", "692555017");
        spis[2] = new Dane ("Mendala", "947342112");
        spis[3] = new Dane ("Garbacz", "220691748");
        spis[4] = new Dane ("Zegan", "901759228");
        
        Arrays.sort(spis);
        for(Dane kontent: spis){
            System.out.println(kontent);
        }
    }
    public static void zad3(){
        Dane spis[] = new Dane[5];
        
        spis[0] = new Dane ("Terelak", "692012537");
        spis[1] = new Dane ("Tutaj", "692555017");
        spis[2] = new Dane ("Mendala", "947342112");
        spis[3] = new Dane ("Garbacz", "220691748");
        spis[4] = new Dane ("Zegan", "901759228");
        
        Arrays.sort(spis, Collections.reverseOrder());
        for(Dane kontent: spis){
            System.out.println(kontent);
        }
    }
    public static void zad4(){
        Pracownik spis[] = new Pracownik[5];
        
        spis[0] = new Pracownik (1, "Terelak", "Web Developer");
        spis[1] = new Pracownik (2, "Tutaj", "Copywriter");
        spis[2] = new Pracownik (3, "Mendala", "Backend Developer");
        spis[3] = new Pracownik (4, "Garbacz", "Secretary");
        spis[4] = new Pracownik (5, "Zegan", "CEO");
        
        Arrays.sort(spis);
        for(Pracownik kontent: spis){
            System.out.println(kontent);
        }
    }
    
    public static void main(String[] args) {
        //zad1();
        //zad2();
        //zad3();
        zad4();
    }
    
}
