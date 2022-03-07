/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package lab3_terelak;

import java.util.Scanner;
        
/**
 *
 * @author Radosław Terelak
 */
public class Lab3_Terelak {

    public static void zad1(){
        Scanner scan = new Scanner (System.in);
        String tekst = "";
        
        System.out.println("Wpisuj tekst, słowo 'exit' kończy proces");
        
        while(!scan.hasNext("exit")){
            tekst += scan.next();
        }
        
        System.out.println("Oto cały podany tekst: ");
        System.out.println(tekst);
    }
    
    public static void zad2(){
        Scanner scan = new Scanner (System.in);
        String tekst = "";
        
        System.out.println("Podaj tekst, a ja policzę liczbę występujących w nim 'a' :)");
        tekst = scan.next();
        
        int ile_a = 0;
        char temp;
        for(int i = 0; i < tekst.length(); i++){
            temp = tekst.charAt(i);
            if(temp == 'a'){
                ile_a++;
            }
        }
        
        System.out.println("W podanym tekście występuje: " + ile_a + " liter 'a' :)");
    }
    
    public static void zad3(){
        Scanner scan = new Scanner (System.in);
        
        System.out.println("Podaj tekst, a ja usunę niepotrzebne spacje :)");
        String tekst = scan.nextLine();
        
        System.out.println(tekst.replaceAll(" +"," "));
    }
    
    public static void zad4(){
        Scanner scan = new Scanner (System.in);
        String tekst = "";
        
        System.out.println("Podaj tekst, a ja policzę liczbę występujących w nim 'ab' :)");
        tekst = scan.nextLine();
        
        int ile_ab = 0;
        char temp, temp2;
        for(int i = 0; i < tekst.length()-1; i++){
            temp = tekst.charAt(i);
            temp2 = tekst.charAt(i + 1);
            if(temp == 'a' && temp2 == 'b'){
                ile_ab++;
            }
        }
        
        System.out.println("W podanym tekście występuje: " + ile_ab + " dwuznaków 'ab' :)");
    }
    
    public static void zad5(){
        Scanner scan = new Scanner (System.in);
        String tekst = "";
        
        System.out.println("Podaj tekst, a ja policzę ile jest w nim słów :)");
        tekst = scan.nextLine();
                
        tekst = tekst.trim();
        int ile_slow = tekst.split("\\s+").length;
        System.out.println("W podanym tekście występuje: " + ile_slow + " słów :)");
    }
    
    public static void zad6(){
        Scanner scan = new Scanner (System.in);
        String tekst = "";
        
        System.out.println("Podaj tekst, a ja wypiszę go słowo po słowie :)");
        tekst = scan.nextLine();
        
        //String str="hello world"; 
        for(String s :tekst.split(" ")){ 
     
        System.out.println(s); 
        } 
    }
    
    public static void zad7(){
        Scanner scan = new Scanner (System.in);
        String tekst = "";
        System.out.println("Podaj tekst, a ja usunę znaki spacji z tabulacji z początku :)");
        tekst = scan.nextLine();
        
        //tekst = tekst.replaceAll("\\s+","");
        
        System.out.println("Tekst przed usunięciu spacji i tabulacj: ");
        System.out.println(tekst);
        
        tekst = tekst.trim();
        
        System.out.println("Tekst po usunięciu spacji i tabulacj: ");
        System.out.println(tekst);
    }
    public static void main(String[] args) {
        //zad1();
        //zad2();
        //zad3();
        //zad4();
        //zad5();
        //zad6();
        //zad7();        
    }
    
}
