package kolokwium2_radosław_terelak_4g;

public class Kolokwium2_Radosław_Terelak_4G {

    public static void main(String[] args){
        Punkt3DKolor punkt1 = new Punkt3DKolor();
        Punkt3DKolor punkt2 = new Punkt3DKolor(100,200,500);
        Punkt3DKolor punkt3 = new Punkt3DKolor(10,20,30,2,22,222);
        
        System.out.println("\nWyświetlanie danych:");
        punkt1.wyswietlDane();
        punkt2.wyswietlDane();
        punkt3.wyswietlDane();
        
        System.out.print("\nZmiana RGB w 'punkt1'..");
        punkt1.setRGB(5, 5, 5);

        System.out.println("\n\nWyświetlanie danych:");
        punkt1.wyswietlDane();
        punkt2.wyswietlDane();
        punkt3.wyswietlDane();
        
        System.out.println("\nWyświetlanie współrzędnych:");
        punkt1.wyswietlXYZ();
        punkt2.wyswietlXYZ();
        punkt3.wyswietlXYZ();
        
        System.out.println("\nUstawianie nowych współrzędnych..");
        punkt1.setX(6);
        punkt1.setY(6);
        punkt1.setZ(6);
        punkt2.setX(-5);
        punkt2.setY(5);
        punkt2.setZ(-5);
        punkt3.setX(7);
        punkt3.setY(8);
        punkt3.setZ(9);
        
        System.out.println("\nWyświetlanie współrzędnych:");
        punkt1.wyswietlXYZ();
        punkt2.wyswietlXYZ();
        punkt3.wyswietlXYZ();
    } 
}

class Punkt2D{
    protected double x, y;
    
    public Punkt2D(double x, double y){
        this.x = x;
        this.y = y;
    }
    public Punkt2D(){
        this.x = 5;
        this.y = 10;
    }
    public void wyswietlXY(){
        System.out.println("Współrzędne: " + this.x + ", " + this.y);
    }
    
    public void setX(double x){
        this.x = x;
    }
    public void setY(double y){
        this.y = y;
    }
    
    public double getX(){
        return this.x;
    }
    public double getY(){
        return this.y;
    } 
}

class Punkt3D extends Punkt2D{
    protected double z;
    
    public Punkt3D(double x, double y, double z){
        super(x,y);
        this.z = z;
    }
    public Punkt3D(double z){
        this.z = z;
    }
    public Punkt3D(){
        this.z = 15;
    }
    public void wyswietlXYZ(){
        System.out.println("Współrzędne: " + this.x + ", " + this.y +", " + this.z);
    }
    
    public void setZ(double z){
        this.z = z;
    }
    public double getZ(){
        return this.z;
    }
}

class Punkt3DKolor extends Punkt3D{
    protected int R, G, B;
    
    public Punkt3DKolor(double x, double y, double z, int r, int g, int b){
        super(x,y,z);
        if((r >= 0 && r <= 255) && (g >= 0 && g <= 255) && (b >= 0 && b <= 255)){
            this.R = r;
            this.G = g; 
            this.B = b; 
        }
        else{
            System.out.println("Wartość spoza zakresu!");
        }
    }
    public Punkt3DKolor(int r, int g, int b){
        if((r >= 0 && r <= 255) && (g >= 0 && g <= 255) && (b >= 0 && b <= 255)){
            this.R = r;
            this.G = g; 
            this.B = b; 
        }
        else{
            System.out.println("Wartość spoza zakresu!");
        }
    }
    public Punkt3DKolor(){
        this.R = 50;
        this.G = 100;
        this.B = 150;
    }
    
    public int[] getRGB(){
        int[] RGB = new int[]{this.R, this.G, this.B};
        return RGB;
    }
    
    public void setRGB(int r, int g, int b){
        if((r >= 0 && r <= 255) && (g >= 0 && g <= 255) && (b >= 0 && b <= 255)){
            this.R = r;
            this.G = g; 
            this.B = b; 
        }
        else{
            System.out.println("Wartość spoza zakresu!");
        }
    }
    
    public void wyswietlDane(){
        System.out.println("Współrzędne: " + this.x + ", " + this.y +", " + this.z);
        System.out.println("RGB: " + this.R + ", " + this.G + ", " + this.B);
    }
}
