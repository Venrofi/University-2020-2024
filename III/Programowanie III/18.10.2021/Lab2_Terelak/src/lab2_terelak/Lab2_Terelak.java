/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package lab2_terelak;

import java.util.Scanner;
/**
 *
 * @author Radosław Terelak
 */
public class Lab2_Terelak {
    
    
    public static void zad1(){
        Scanner scan = new Scanner (System.in);
        
        System.out.print("Podaj liczbę A: ");
        while(!scan.hasNextDouble()) scan.next();
        
        double a = scan.nextDouble();
        double b;
        
        do {
            System.out.print("Podaj liczbę B: ");
            while (!scan.hasNextDouble()) {
                System.out.println("To nie jest liczba!");
                scan.next();
            }
            b = scan.nextDouble();
        } while (b == 0);
        
        System.out.println("Wynik dodawania A+B: " + (a+b));
        System.out.println("Wynik dzielenia A/B: " + (a/b));
    }
    
    public static void zad2(){
        Scanner scan = new Scanner (System.in);
        int a,b;
        
        do {
            System.out.print("Podaj współczynnik a różny od zera: ");
            while (!scan.hasNextInt()) {
                System.out.println("To nie jest liczba!");
                scan.next();
            }
            a = scan.nextInt();
        } while (a == 0);
        
        System.out.print("Podaj współczynnik b: ");
        while(!scan.hasNextInt()) scan.next();
        b = scan.nextInt();
        
        System.out.println("Miejsce zerowe funkcji y = " + a +"x + " + b + " to: " + (-b/a));
    }
    
    public static void zad3(){
        Scanner scan = new Scanner (System.in);
        int r,h;
        
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
        
        System.out.println("Pole powierzchni bocznej walca o promieniu " + r + " oraz wysokości " + h + " wynosi: " + Math.round(2*Math.PI*r*h));
        System.out.println("Objętość walca o promieniu " + r + " oraz wysokości " + h + " wynosi: " + Math.round(Math.PI*r*r*h));
    }
    
    public static void zad4(){
        Scanner scan = new Scanner (System.in);
        double a,b,c;
        
        do {
            System.out.print("Podaj współczynnik a różny od zera: ");
            while (!scan.hasNextDouble()) {
                System.out.println("To nie jest liczba!");
                scan.next();
            }
            a = scan.nextDouble();
        } while (a == 0);
        
        System.out.print("Podaj współczynnik b: ");
        while(!scan.hasNextDouble()) scan.next();
        b = scan.nextDouble();
        
        System.out.print("Podaj współczynnik c: ");
        while(!scan.hasNextDouble()) scan.next();
        c = scan.nextDouble();
        
        double delta,x1,x2;
        
        delta = b*b - 4*a*c;
        
        if(delta > 0)
        {
            x1 = (-b-Math.sqrt(delta))/2*a;
            x2 = (-b+Math.sqrt(delta))/2*a;
            if(a == 1)
            {
                if(c >= 0) System.out.println("Miejsca zerowe równania x^2 + " + b + "x + " + c + " to: " + x1 + ", " + x2);
                else System.out.println("Miejsca zerowe równania x^2 + " + b + "x " + c + " to: " + x1 + ", " + x2);
            }
            else if(a == -1)
            {
                if(c >= 0) System.out.println("Miejsca zerowe równania -x^2 + " + b + "x + " + c + " to: " + x1 + ", " + x2);
                else System.out.println("Miejsca zerowe równania -x^2 + " + b + "x " + c + " to: " + x1 + ", " + x2);
            }
            else
            {
                if(c >= 0) System.out.println("Miejsca zerowe równania " + a + "x^2 + " + b + "x + " + c + " to: " + x1 + ", " + x2);
                else System.out.println("Miejsca zerowe równania " + a + "x^2 + " + b + "x " + c + " to: " + x1 + ", " + x2);
            }
        }
        else if(delta == 0)
        {
            x1 = -b / (2*a);
            
            if(a == 1)
            {
                if(c >= 0) System.out.println("Miejsce zerowe równania x^2 + " + b + "x + " + c + " to: " + x1);
                else System.out.println("Miejsce zerowe równania x^2 + " + b + "x " + c + " to: " + x1);
            }
            else if(a == -1)
            {
                if(c >= 0) System.out.println("Miejsce zerowe równania -x^2 + " + b + "x + " + c + " to: " + x1);
                else System.out.println("Miejsce zerowe równania -x^2 + " + b + "x " + c + " to: " + x1);
            }
            else
            {
                if(c >= 0) System.out.println("Miejsce zerowe równania " + a + "x^2 + " + b + "x + " + c + " to: " + x1);
                else System.out.println("Miejsce zerowe równania " + a + "x^2 + " + b + "x " + c + " to: " + x1);
            }
        }
        else System.out.println("Brak miejsc zerowych!");
        
        
    }
    
    public static double Zad5(double a1, double a2, double b1, double b2){
        double det = a1 * b2 - a2 * b1;        
        return det;
    }
    
    public static double Zad6(double a1, double a2, double a3, double b1, double b2, double b3, double c1, double c2, double c3){
        double det = (a1*b2*c3 + a2*b3*c1 + a3*b1*c2) - (a3*b2*c1 + a1*b3*c2 + a2*b1*c3);        
        return det;
    }
    
    public static void main(String[] args) {
        //zad1();
        //zad2();
        //zad3();
        //zad4();
               
        System.out.println("Wyznacznik 2x2: " + Zad5(2, 3, -1, 7));
        System.out.println("Wyznacznik 3x3: " + Zad6(2, 3, 5, -1, 4, 6, 3, -2, 7));
    }
    
    
    
}
