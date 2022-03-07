package lab8_terelak;

import java.util.*;

public class Lab8_Terelak {
    public static void zad1(){
        System.out.print("Podaj dwie liczby rzeczywiste: ");
        Scanner scan = new Scanner (System.in);
        
        double a = scan.nextDouble();
        double b = scan.nextDouble();
        
        Algorytm alg = new Algorytm();
        System.out.print("Swap: " + alg.swap(a, b));
    }
    
    public static void zad2(){
        Scanner scan = new Scanner (System.in);
        double[] a = new double[2];
        double[] b = new double[2];
        
        System.out.print("Podaj dwie wartości wektora a: ");
        a[0] = scan.nextDouble();
        a[1] = scan.nextDouble();
        
        System.out.print("Podaj dwie wartości wektora b: ");
        b[0] = scan.nextDouble();
        b[1] = scan.nextDouble();
        
        Algorytm alg = new Algorytm();
        System.out.print("\nIloczyn skalarny: " + alg.iloczyn_skalarny(a, b));
    }
    
    public static void zad3(){
        int n;
        Scanner scan = new Scanner (System.in);
        System.out.print("Podaj wymiar macierzy: ");
        
        n = scan.nextInt();
        double[][] macierz;
        macierz = new double[n][n];
        
        double[] wektor = new double[n]; 
        
        double[] wynik = new double[wektor.length];
        System.out.print("Podaj wektor ["+n+"]: ");
        for(int i=0; i<n;i++){
            wektor[i] = scan.nextDouble();
        }
        
        for(int i=0; i<n;i++){
            for(int j=0; j<n; j++){
                System.out.print("Macierz["+i+"]["+j+"]: ");
                macierz[i][j] = scan.nextDouble();
            }
        }
        double suma = 0;
        for(int i=0; i<n;i++){
            for(int j=0; j<n; j++){
              suma += macierz[i][j] * wektor[j];
            }
            wynik[i] = suma;
            suma = 0;
            System.out.print("\nWynik["+i+"] = " + wynik[i]);
        }
        
    }
    public static void main(String[] args) {
        //zad1();
        //zad2();
        zad3();
    }  
}

class Algorytm{
    public double swap(double a, double b){
        double temp = a;
        a = b;
        b = temp;
        
        return a;
    }
    
    public double iloczyn_skalarny(double[] wektor_a, double[] wektor_b){
        return wektor_a[0]*wektor_b[0] + wektor_a[1]*wektor_b[1];
    }
}
