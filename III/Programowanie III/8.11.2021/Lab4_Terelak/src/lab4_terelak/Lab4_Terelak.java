package lab4_terelak;
import java.io.*;
import java.util.Locale;
import java.text.*;

public class Lab4_Terelak {

    public static void zad1() throws IOException{
        Locale locale = new Locale("eng", "ENG");
        NumberFormat eng = NumberFormat.getInstance(locale);
        System.out.println("Enter two numbers separated with a space: ");
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String tekst=br.readLine();
        StringBuffer strbfr=new StringBuffer(tekst);
        
        double suma = 0;
        
        System.out.print("Wprowadzone liczby: ");
        tekst = tekst.trim();
        for(String s :tekst.split(" ")){ 
            if(!s.equals(""))
            {
                System.out.print(s + ", "); 
                suma += Double.parseDouble(s);
            }
            
        } 
        System.out.println("\nSuma: "+ suma);
        
    }
    
    public static void zad2() throws IOException{
        Locale locale = new Locale("eng", "ENG");
        NumberFormat eng = NumberFormat.getInstance(locale);
        System.out.println("Enter numbers separated with a space: ");
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String tekst=br.readLine();
        StringBuffer strbfr=new StringBuffer(tekst);
        
        int suma = 0;
        
        System.out.print("Wprowadzone liczby: ");
        tekst = tekst.trim();
        for(String s :tekst.split(" ")){ 
            if(!s.equals(""))
            {
                System.out.print(s + ", "); 
                suma += Integer.parseInt(s);
            }
            
        } 
        System.out.println("\nSuma: "+ suma);
        
    }
    
    public static void zad3() throws IOException{
        
        System.out.println("Podaj tekst: ");
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String tekst=br.readLine();
        StringBuffer strbfr=new StringBuffer(tekst);
        while(!tekst.equals("exit"))
        {
            tekst = tekst.trim();
            for(String s :tekst.split(" ")){ 
                if(s.equals("Radek") || s.equals("Radzio"))
                {
                    System.out.println("Wprowadzony tekst: ");
                    System.out.println(tekst); 
                }
            }    
            tekst=br.readLine();
        }  
    }
    
    public static void zad4() throws IOException{
        System.out.println("Podaj tekst: ");
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String tekst=br.readLine();
        StringBuffer strbfr=new StringBuffer(tekst);
        
        String[] slowa = tekst.split("[\\p{P}\\s&&[^']]+"); // \p{P} - jakikolwiek znak interpunkcyjny, \s - jakikolwiek znak biały, && - oraz, [^'] - jakikolwiek znak prócz apostrofu
        System.out.println("Liczba słów: " + slowa.length);
    }
    
    public static void zad5() throws IOException{
        System.out.println("Podaj datę (dd-mm-yyyy): ");
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String tekst=br.readLine();
        StringBuffer strbfr=new StringBuffer(tekst);
        
        if (tekst.matches("\\d{2}-\\d{2}-\\d{4}")) { // \d - jakakolwiek cyfra, \d{4} - cztery jakiekolwiek cyfry
            System.out.println("Podano prawidłową datę :)");
        }
        else{
            System.out.println("Data w nieprawidłowym formacie..");
        }
    }
    
    public static void zad6() throws IOException{
        
        System.out.println("Podaj szukane słowo: ");
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String slowo=br.readLine();
        StringBuffer strbfr_slowo=new StringBuffer(slowo);
        
        System.out.println("Podawaj linie tekstu, wprowadzenie slowa 'exit' kończy proces..");
        String tekst=br.readLine();
        StringBuffer strbfr_tekst=new StringBuffer(tekst);
        
        String caly_tekst = "";
        while(!tekst.equals("exit"))
        {
            caly_tekst += "\n" + tekst;
            tekst=br.readLine();
        } 
        caly_tekst = caly_tekst.trim();
        String[] linie_tekstu = caly_tekst.split("\n");
        
        System.out.println("Ilość linii tekstu: " + linie_tekstu.length + "\n" + linie_tekstu + "\n" + caly_tekst);
        
        
        /*
        for(String s :linie_tekstu.split(" ")){ 
                if(s.equals(slowo))
                {
                    System.out.println("Wprowadzona linia zawiera slowo kluczowe: ");
                    System.out.println(caly_tekst); 
                }
        } 
*/
    }
    
    public static void zad7() throws IOException{
      int count = 0;
      for(int i = 0; i < 100; i++)
      {
          double x = Math.random();
          if(x < 20)
          {
              System.out.println(x + " ");
              count++;
          }
          if(count == 10)
              break;
      }
    }
    public static void zad8() throws IOException{
        int tab[][] = new int[5][0];
        int l = 10;
        for(int i = 0; i<5;i++) tab[i] = new int[i+1];

        for(int i = 0;i<tab.length;i++)
        {
            for(int j = 0;j<tab[i].length;j++)
            {
                tab[i][j] = l;
                l += 2;
            }
        }
        for(int i = 0;i<tab.length;i++)
        {
            for(int j = 0;j<tab[i].length;j++)
            {
                System.out.print(tab[i][j]+" ");
            }
            System.out.println();
        }
    }
    
    public static void main(String[] args) throws IOException{
        //zad1();
        //zad2();
        //zad3();
        //zad4();
        //zad5();
        //zad6();
        //zad7();
        zad8();
    }
    
    
    
}
