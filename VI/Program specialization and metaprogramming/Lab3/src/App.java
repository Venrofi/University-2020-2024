public class App {
    public static void main(String[] args) throws Exception {
        // 2.A.a
        // Aa2();

        // 2.A.b
        // Ab2();

        // 2.B.a
        // Ba2();

        // 2.B.b
        // Bb2();

        // 2.C.a
        // Ca2();

        // 2.C.b
        Cb2();
    }

    public static void Aa2() {
        // 2.A.a
        BoxedObject b1 = new BoxedObject(1);
        BoxedObject b2 = b1;

        System.out.println("Old: ");
        System.out.println("Object #1: " + b1.toString() + " Object #2: " + b2.toString());

        int val = (int) b1.get();
        b1.set(val + 1);

        // b1.set("New value in the string!");

        System.out.println("New: ");
        System.out.println("Object #1: " + b1.toString() + " Object #2: " + b2.toString());
    }

    public static void Ab2() {
        // A.b.dot#1 - works, it changes b1 & b2
        Box<String> b1 = new Box<String>("Sample string");
        Box<String> b2 = b1;

        System.out.println("Old: ");
        System.out.println(b2.toString());

        b1.set("Changed string!");

        System.out.println("New: ");
        System.out.println(b2.toString());

        // A.b.dot#2 - works, it changes b1 & b2
        Box<Integer> b3 = new Box<Integer>(5);
        Box<Integer> b4 = b3;

        System.out.println("Old: ");
        System.out.println(b4.toString());

        int val = (int) b3.get();
        b3.set(val + 1);

        System.out.println("New: ");
        System.out.println(b4.toString());

        // A.b.dot#3 - ofc works, because Object == String && Object == Integer
        Box<Object> b5 = new Box<Object>("Twenty five");
        Box<Object> b6 = b5;

        System.out.println("Old: ");
        System.out.println("Object #1: " + b5.toString() + " Object #2: " + b6.toString());

        b5.set(25);

        System.out.println("New: ");
        System.out.println("Object #1: " + b5.toString() + " Object #2: " + b6.toString());
    }

    public static void Ba2() {
        String s1 = "Hello";
        Box<String> box1 = new Box<String>(s1);
        Box<Box<String>> bbox1 = new Box<Box<String>>(box1);
        System.out.println(bbox1.toString());
    }

    public static void Bb2() {
        String s1 = "Hello";
        Box<String> box1 = new Box<String>(s1);
        Box<Box<String>> bbox1 = new Box<Box<String>>(box1);
        // bbox1.set("Howdy"); // does not work
        bbox1.set(new Box<String>("Howdy!"));
        System.out.println(bbox1.toString());
    }

    public static void Ca2() {
        Box<Object> someObject = new Box<Object>(null);
        someObject.set(new Box<Integer>(88));
        System.out.println(someObject.toString());
    }

    public static void Cb2() {
        Box<Integer> ibox = new Box<Integer>(new Integer(5));
        // Box<Object> obox = (Box<Object>) ibox;
        // Cannot cast from Box<Integer> to Box<Object> !
    }
}
