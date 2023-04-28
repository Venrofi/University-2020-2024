import java.io.PrintWriter;
import java.math.BigInteger;

/**
 * A simple experiment with expandable arrays.
 */
public class SEAExpt {
  /**
   * Square a big integer.
   */
  public static BigInteger square(BigInteger i) {
    return i.multiply(i);
  } // square(BigInteger)

  public static void main(String[] args) {
    // Eb2();
    // Ec2();
    // Ef2();
    Eh2();
  }

  public static void Eb2() {
    PrintWriter pen = new PrintWriter(System.out, true);
    ExpandableArray<BigInteger> numbers = new SimpleExpandableArray<BigInteger>();

    // Set some values
    for (int i = 0; i < 10; i++) {
      numbers.set(i, BigInteger.valueOf(i));
    } // for i

    // Get some values
    for (int i = 0; i < 10; i++) {
      pen.println("numbers[" + i + "] = " + numbers.get(i));
    } // for i

    // Do some simple computations
    for (int i = 0; i < 10; i++) {
      pen.println(numbers.get(i) + "^2 = " + square(numbers.get(i)));
    } // for i
  }

  public static void Ec2() {
    PrintWriter pen = new PrintWriter(System.out, true);
    ExpandableArray<String> strings = new SimpleExpandableArray<String>();

    for (int i = 0; i < 10; i++) {
      strings.set(i, "String #" + i);
    }

    // strings.set(0, 44); // This should cause a compiler error

    for (int i = 0; i < 10; i++) {
      pen.println("strings[" + i + "] = " + strings.get(i));
    }
  }

  public static void Ef2() {
    PrintWriter pen = new PrintWriter(System.out, true);
    ExpandableArray<BigInteger> numbers = new SimpleExpandableArray();

    // Set some values
    for (int i = 0; i < 10; i++) {
      numbers.set(i, BigInteger.valueOf(i));
    } // for i

    // Get some values
    for (int i = 0; i < 10; i++) {
      pen.println("numbers[" + i + "] = " + numbers.get(i));
    } // for i

    // Do some simple computations
    for (int i = 0; i < 10; i++) {
      pen.println(numbers.get(i) + "^2 = " + square(numbers.get(i)));
    }
  }

  public static void Eh2() {
    PrintWriter pen = new PrintWriter(System.out, true);
    ExpandableArray<String> strings = new SimpleExpandableArray();

    for (int i = 0; i < 10; i++) {
      strings.set(i, "String #" + i);
    }

    for (int i = 0; i < 10; i++) {
      pen.println("strings[" + i + "] = " + strings.get(i));
    }
  }
} // class SEAExpt
