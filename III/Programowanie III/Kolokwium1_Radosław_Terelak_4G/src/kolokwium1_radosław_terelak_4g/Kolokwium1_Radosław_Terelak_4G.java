package kolokwium1_radosław_terelak_4g;

import java.util.*;

public class Kolokwium1_Radosław_Terelak_4G {
    public static void main(String[] args){
        Dane spis[] = new Dane[5];
        
        spis[0] = new Dane (1, "Terelak", 3500);
        spis[1] = new Dane (2, "Tutaj", 5000);
        spis[2] = new Dane (3, "Mendala", 3200);
        spis[3] = new Dane (4, "Garbacz", 4200);
        spis[4] = new Dane (5, "Zegan", 3000);
        
        System.out.println("Dane przed sortowaniem: ");
        for(Dane kontent: spis){
            System.out.println(kontent);
        }
        Arrays.sort(spis);
        System.out.println("Dane po sortowaniu: ");
        for(Dane kontent: spis){
            System.out.println(kontent);
        }
    }
}

class Dane implements Comparable{
    private int id, wynagrodzenie;
    private String nazwisko; 

    public Dane(){};
    public Dane(int id, String nazwisko, int wynagrodzenie){
        this.id = id;
        this.nazwisko = nazwisko;
        this.wynagrodzenie = wynagrodzenie;
    }
    @Override
    public String toString(){
        return String.format("#%d %10s  %szł", id, nazwisko, wynagrodzenie);
    }

    public int compareTo(Object obj){
        if(this == obj) return 0;
        if(this.getClass()!= obj.getClass()) return 1;
        Dane e = (Dane) obj;
        return (this.wynagrodzenie - e.wynagrodzenie);
    }
}