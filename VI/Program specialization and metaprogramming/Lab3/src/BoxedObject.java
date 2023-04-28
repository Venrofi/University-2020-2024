/**
 * Generic boxes hold shared values.
 */
public class BoxedObject {
  // +--------+------------------------------------------------------
  // | Fields |
  // +--------+

  /**
   * Objecthe contents of the box.
   */
  Object contents;

  // +--------------+------------------------------------------------
  // | Constructors |
  // +--------------+

  /**
   * Build a new box with specified initial contents.
   */
  public BoxedObject(Object initialContents) {
    this.contents = initialContents;
  } // Box(Object)

  // +---------+-----------------------------------------------------
  // | Methods |
  // +---------+

  /**
   * Get the contents of the box.
   */
  public Object get() {
    return this.contents;
  } // get()

  /**
   * Update the contents of the box.
   */
  public void set(Object newContents) {
    this.contents = newContents;
  } // set(Object)

  /**
   * Get the contents of the box as a string.
   */
  public String toString() {
    return this.contents.toString();
  } // toString()
} // class BoxedObject
