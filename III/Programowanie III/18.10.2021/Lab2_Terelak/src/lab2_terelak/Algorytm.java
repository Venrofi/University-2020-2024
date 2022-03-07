/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab2_terelak;

/**
 *
 * @author User
 */
public class Algorytm {
    public static double Zad5(double a1, double a2, double b1, double b2){
        double det = a1 * b2 - a2 * b1;        
        return det;
    }
    
    public static double Zad6(double a1, double a2, double a3, double b1, double b2, double b3, double c1, double c2, double c3){
        double det = (a1*b2*c3 + a2*b3*c1 + a3*b1*c2) - (a3*b2*c1 + a1*b3*c2 + a2*b1*c3);        
        return det;
    }
}
