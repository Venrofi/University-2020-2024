/**
 * Expandable arrays of values.
 */
public interface ExpandableArray<T> {
  /**
   * Set the ith element of the array to val.
   *
   * @pre i >= 0
   * @post get(i) = val
   */
  public void set(int i, T val);

  /**
   * Get the ith element of the array. If the ith element has not
   * been set, returns null.
   *
   * @pre i >= 0
   */
  public T get(int i);
} // interface ExpandableArray<T>
