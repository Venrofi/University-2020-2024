/**
 * Generic boxes hold shared values.
 */
public class Box<T> {
  // +--------+------------------------------------------------------
  // | Fields |
  // +--------+

  /**
   * The contents of the box.
   */
  T contents;

  // +--------------+------------------------------------------------
  // | Constructors |
  // +--------------+

  /**
   * Build a new box with specified initial contents.
   */
  public Box(T initialContents) {
    this.contents = initialContents;
  } // Box(T)

  // +---------+-----------------------------------------------------
  // | Methods |
  // +---------+

  /**
   * Get the contents of the box.
   */
  public T get() {
    return this.contents;
  } // get()

  /**
   * Update the contents of the box.
   */
  public void set(T newContents) {
    this.contents = newContents;
  } // set(T)

  /**
   * Get the contents of the box as a string.
   */
  public String toString() {
    return this.contents.toString();
  } // toString()
} // class Box<T>
