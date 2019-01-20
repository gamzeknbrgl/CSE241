
import java.awt.Graphics;
/**
 * The Interface Shape.
 *
 * @author Gamze

 */

public interface Shape extends Comparable<Shape>{
   
	/**
	 * Returns the area of Shape
	 *
	 * @return area 
	 */
   	 public abstract double area();

	/**
	 * Returns the perimeter of Shape
	 *
	 * @return perimeter
	 */
   	 public abstract double perimeter();
   	 /**
	 * Increments the shape positions 1.0
	 *
	 * @return new Shape
	 */
   	 public abstract Shape increment();
   	 /**
	 * Decrements the shape positions 1.0
	 *
	 * @return new Shape
	 */
   	 public abstract Shape decrement();
   	 /**
	 * Draws the shape 
	 * 
	 * @param g Graphics object
	 */
   	 public abstract void draw(Graphics g);
   	 /**
	 * Returns the name of Shape
	 * 
	 * @return name
	 */
   	 public abstract String shapeName();
   	 /**
	 * Compare shapes respect to their areas
	 * 
	 * @return 0,-1 or 1
	 */
   	@Override public int compareTo(Shape that);


}