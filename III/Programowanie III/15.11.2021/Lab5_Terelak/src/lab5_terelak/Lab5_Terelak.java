/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package lab5_terelak;

import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class Lab5_Terelak {

    public static void zad1(){
        for(int i=0; i <= 50; i++)
        {
            System.out.println(i);
        }
    }
    
    public static void zad2(){
        System.out.println("Tabliczka mnożenia: ");
        for(int i=1; i <= 10; i++)
        {
            System.out.println(i + " * 1 = "+ i*1);
            System.out.println(i + " * 2 = "+ i*2);
            System.out.println(i + " * 3 = "+ i*3);
            System.out.println(i + " * 4 = "+ i*4);
            System.out.println(i + " * 5 = "+ i*5);
            System.out.println(i + " * 6 = "+ i*6);
            System.out.println(i + " * 7 = "+ i*7);
            System.out.println(i + " * 8 = "+ i*8);
            System.out.println(i + " * 9 = "+ i*9);
            System.out.println(i + " * 10 = "+ i*10);
            System.out.print("\n");
        }
    }
    
    public static void zad3(int n){
        if (n < 2) throw new IllegalArgumentException("Należy podać wielkość przynajmniej 2, podana wielkość to: " + n);
        int tablica_liczb[] = new int[n];
        int minimum = 0;
        int maksimum = 0;
        Scanner scan = new Scanner(System.in);
        
        System.out.println("Podaj " + n + " liczb: ");
        for(int i=0; i<tablica_liczb.length; i++){
            tablica_liczb[i] = scan.nextInt();
            
            //tablica_liczb[i] = i;
            if(i == 0)
            {
                minimum = tablica_liczb[0];
                maksimum = tablica_liczb[0];
            }
            else
            {
                if(tablica_liczb[i] > maksimum)
                {
                    maksimum = tablica_liczb[i];
                }
                
                if(tablica_liczb[i] < minimum)
                {
                    minimum = tablica_liczb[i];
                }
            }
        }
        System.out.println("Min: " + minimum + "\nMaks: " + maksimum);
    }
    
    public static void zad4(int n){
        if (n < 2) throw new IllegalArgumentException("Należy podać wielkość przynajmniej 2, podana wielkość to: " + n);
        int tablica_liczb[] = new int[n];
        Scanner scan = new Scanner(System.in);
        
        System.out.println("Podaj " + n + " liczb: ");
        for(int i=0; i<tablica_liczb.length; i++){
            tablica_liczb[i] = scan.nextInt();
        }
        
        Algorytm alg = new Algorytm();
        
        System.out.println("Indeks najmniejszej wartości: " + alg.min(tablica_liczb));
        System.out.println("Średnia arytmetyczna: " + alg.sr(tablica_liczb));
    }
    
    public static void zad5(int n){
        if (n < 2) throw new IllegalArgumentException("Należy podać wielkość przynajmniej 2, podana wielkość to: " + n);
        int tablica_liczb[] = new int[n];
        Scanner scan = new Scanner(System.in);
        
        System.out.println("Podaj " + n + " liczb: ");
        for(int i=0; i<tablica_liczb.length; i++){
            tablica_liczb[i] = scan.nextInt();
        }
        Arrays.sort(tablica_liczb);
        
        for(int i=0; i<tablica_liczb.length; i++){
            System.out.print(tablica_liczb[i]+", ");
        }
        
    }
    
    public static void zad6(int n){
        if (n < 2) throw new IllegalArgumentException("Należy podać wielkość przynajmniej 2, podana wielkość to: " + n);
        Number tablica_liczb[] = new Number[n];
        Scanner scan = new Scanner(System.in);
        
        System.out.println("Podaj " + n + " liczb: ");
        for(int i=0; i<tablica_liczb.length; i++){
            tablica_liczb[i] = scan.nextInt();
        }
        Arrays.sort(tablica_liczb, Collections.reverseOrder());
        
        for(int i=0; i<tablica_liczb.length; i++){
            System.out.print(tablica_liczb[i]+", ");
        }
        
    }
    
    public static void zad7(String nazwa_pliku) throws FileNotFoundException{
        File file = new File(nazwa_pliku);
        Scanner in = new Scanner(file);
        int liczba_linii = 0;
        while(in.hasNextLine())
        {
            liczba_linii++;
            in.nextLine();
        }
        in.close();
        in = null;
        
        in = new Scanner(file);
        
        int[] liczby = new int[liczba_linii];
        int i = 0;
        while(in.hasNextLine())
        {
            String liczba = in.nextLine();
            liczby[i] = Integer.parseInt(liczba);
            i++;
        }
        Arrays.sort(liczby);
        
        for(int j=0; j<liczby.length; j++){
            System.out.print(liczby[j]+", ");
        }
    }
    
    public static void zad8(int n){
        if (n < 2) throw new IllegalArgumentException("Należy podać wielkość przynajmniej 2, podana wielkość to: " + n);
        int tablica_liczb[] = new int[n];
        Scanner scan = new Scanner(System.in);
        
        System.out.println("Podaj " + n + " liczb: ");
        for(int i=0; i<tablica_liczb.length; i++){
            tablica_liczb[i] = scan.nextInt();
        }
        
        Algorytm alg = new Algorytm();
        
        System.out.println("Indeks największej wartości z przedziału <" +1+", "+3+">: "+ alg.maks(tablica_liczb, 1, 3) +" wartość: "+ tablica_liczb[alg.maks(tablica_liczb, 1, 3)]);
    }
    
    public static void zad9(int n){
        if (n < 2) throw new IllegalArgumentException("Należy podać wielkość przynajmniej 2, podana wielkość to: " + n);
        int tablica_liczb[] = new int[n];
        Scanner scan = new Scanner(System.in);
        
        System.out.println("Podaj " + n + " liczb: ");
        for(int i=0; i<tablica_liczb.length; i++){
            tablica_liczb[i] = scan.nextInt();
        }
        
        Algorytm alg = new Algorytm();
        
        int posortowana_tablica_liczb[] = new int[n];
        int maks = tablica_liczb[0];
        for(int i = 0; i < tablica_liczb.length; i++){
            if(tablica_liczb[alg.maks(tablica_liczb,0,n-1)] != 0)
            {
                maks = tablica_liczb[alg.maks(tablica_liczb,0,n-1)];
                posortowana_tablica_liczb[i] = maks;
                tablica_liczb[alg.maks(tablica_liczb,0,n-1)] = 0;
            }
        }
        
        for(int j=0; j<posortowana_tablica_liczb.length; j++){
            System.out.print(posortowana_tablica_liczb[j]+", ");
        }
    }
    
    public static void zad10(int n){
        if (n < 2) throw new IllegalArgumentException("Należy podać wielkość przynajmniej 2, podana wielkość to: " + n);
        int tablica_liczb[] = new int[n];
        Scanner scan = new Scanner(System.in);
        
        System.out.println("Podaj " + n + " liczb: ");
        for(int i=0; i<tablica_liczb.length; i++){
            tablica_liczb[i] = scan.nextInt();
        }
        
        for (int j = 1; j < n; j++) {  
            int temp = tablica_liczb[j];  
            int i = j-1;  
            while ( (i > -1) && ( tablica_liczb [i] > temp ) ) {  
                tablica_liczb [i+1] = tablica_liczb [i];  
                i--;  
            }  
            tablica_liczb[i+1] = temp;  
        }
        for(int j=0; j<tablica_liczb.length; j++){
            System.out.print(tablica_liczb[j]+", ");
        }
    }
    
    
    
    public static void main(String[] args) throws FileNotFoundException{
        //zad1();
        //zad2();
        //zad3(5);
        //zad4(5);
        //zad5(5);
        //zad6(5);
        //zad7("liczby.txt");
        //zad8(5);
        //zad9(5);
        zad10(5);
    }
    
}
