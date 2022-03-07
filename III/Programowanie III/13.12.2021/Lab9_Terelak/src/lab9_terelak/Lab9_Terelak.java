package lab9_terelak;

import java.util.*;
import java.io.*;

public class Lab9_Terelak {
    public static void zad1(){
     Locale locale = new Locale("pl", "PL");
        double x1=0.0, y1=0.0, x2=0.0, y2=0.0;
       try{
            try (FileReader fin = new FileReader("dane.txt")){
                BufferedReader fr = new BufferedReader(fin);
                Scanner src = new Scanner(fr);
                src.useLocale(locale);
                x1 = src.nextDouble();
                x2 = src.nextDouble();
            }
            catch (FileNotFoundException e){
                System.out.println(e.getMessage());
                return;
            }
           }
           catch(Exception e){
               System.out.println(e.getMessage());
           }
       
       double dx = x2 - x1;
       double dy = y2 - y1;
       double d = Math.sqrt(dx*dx + dy*dy);
       
       System.out.println(d); 
       
    }
    public static void main(String[] args) {
        zad1();
    }   
}
