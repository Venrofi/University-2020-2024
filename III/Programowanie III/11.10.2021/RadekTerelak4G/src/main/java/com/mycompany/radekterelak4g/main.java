/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package com.mycompany.radekterelak4g;

import java.util.Scanner;
/**
 *
 * @author Student
 */
public class main {

    public static void zad1(){
        System.out.println("Radosław Terelak, Wiek: 21");
    }
    public static void zad2() {
            System.out.println("X X");
            System.out.println(" X ");
            System.out.println("X X");
        }
    public static void zad3() {
        Scanner scan = new Scanner(System.in);
        System.out.println("Podaj pierwsza liczbe: ");
        double a = scan.nextDouble();
        System.out.println("Podaj druga liczbe:");
        double b = scan.nextDouble();
        
        System.out.println(a+ " + " +b+ " = " +(a+b));
        System.out.println(a + " - " + b + " = " + (a-b) );
        System.out.println(a + " * " + b + " = " + (a*b) );
        if(b != 0)
        {
            System.out.println(a + " / " + b + " = " + (a/b) );
        }    
    }
    public static void zad4() {
        Scanner scan = new Scanner(System.in);
        System.out.println("Podaj promien: ");
        double r = scan.nextDouble();
        double pole_kola = Math.PI*r*r;
        
        System.out.println("Powierzchnia kola wynosi: " + pole_kola);
    }
    public static void zad5(){
        Scanner scan = new Scanner(System.in);
        System.out.println("Podaj wartość kąta w stopniach:");
        double kat_stopnie = scan.nextDouble();
        System.out.println("Kat w radianach wynosi: " + Math.toRadians(kat_stopnie));
    }
    
    public static void zad6() {
        Scanner scan = new Scanner(System.in);
        System.out.println("Podaj wartość x:");
        double x = scan.nextDouble();
        double a = 1;
        double b = 1;
        double c = 1;
        double d = 1;
        double wynik1 = (a*x*x) + (b*x) + c;
        double wynik2 = (a*x*x*x) + (b*x*x) + (c*x) + d;
        System.out.println("Wartość wielomianu A(x)=ax^2+bx+c wynosi: " + wynik1);
        System.out.println("Wartość wielomianu B(x)=ax^3+bx^2+cx+d wynosi: " + wynik2);
    }
    
    public static void zad7() {
        Scanner scan = new Scanner(System.in);
        System.out.println("Podaj wartość x:");
        double x = scan.nextDouble();
        double a = 1;
        double b = 1;
        double c = 1;
        double d = 1;
        double wynik1 = x*(x*a+b)+c;
        double wynik2 = x*(x*(x*a+b)+c)+d;
        System.out.println("Wartość wielomianu HORNER A(x)=ax^2+bx+c wynosi: " + wynik1);
        System.out.println("Wartość wielomianu HORNER B(x)=ax^3+bx^2+cx+d wynosi: " + wynik2);
    }
    
    public static void zad8(){
        Scanner scan = new Scanner(System.in);
        System.out.println("Podaj promien:");
        double r = scan.nextDouble();
        System.out.println("Podaj wysokosc:");
        double h = scan.nextDouble();
        
        
        System.out.println("Pole powierzchni bocznej: " + (2*Math.PI*r*h));
        System.out.println("Objetosc: " + (Math.PI*r*r*h) );
    }
    
    public static void main(String[] args) {
        //zad1();
        //zad2();
        //zad3();
        //zad4();
        //zad5();
        //zad6();
        //zad7();
        //zad8();
    }
    
}
