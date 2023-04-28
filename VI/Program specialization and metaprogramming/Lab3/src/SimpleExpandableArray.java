import java.util.Arrays;

/**
 * A very simple implementation of expandable arrays.
 */
public class SimpleExpandableArray<T>
    implements ExpandableArray<T> {
  T[] values;

  @SuppressWarnings({ "unchecked" })
  public SimpleExpandableArray() {
    this.values = (T[]) new Object[16];
  } // SimpleExpandableArray

  public void set(int i, T val) {
    // If the array is not big enough, expand it
    if (this.values.length <= i) {
      int newsize = this.values.length * 2;
      while (newsize <= i) {
        newsize *= 2;
      } // while
      this.values = Arrays.copyOf(this.values, newsize);
    } // if the array is no big enough
    // And set the values
    this.values[i] = val;
  } // set(int, T)

  public T get(int i) {
    // If the array is not big enough, just return null
    if (this.values.length <= i) {
      return null;
    } // if the array is not big enough
    // Get the value
    return this.values[i];
  } // get(int)
} // class SimpleExpandableArray<T>
