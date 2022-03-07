/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab5_terelak;

public class Algorytm{
    //Zad4
    public int min(int[] a){
        int index = 0;
        for(int i = 1; i < a.length; i++){
            if(a[i] < a[index]) index = i;
        }
        return index;
    }

    public double sr(int[] a){
        double s = 0.0;
        for(int i = 0; i < a.length; i++)
        {
            s+=a[i];
        }
        double v = s/(double)a.length;
        return v;
    }
    
    //Zad8
    public int maks(int[] a, int imin, int imax){
        int index = imin;
        for(int i = imin; i <= imax; i++){
            if(a[i] > a[index]) index = i;
        }
        return index;
    }
        
}
