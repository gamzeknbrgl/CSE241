import java.lang.Math; 
import java.awt.Graphics;
import javax.swing.JPanel;
import java.awt.Color;
/**
 * The abstract class Polygon.
 *
 */

public abstract class Polygon extends JPanel implements Shape{


	 /**
	 * Returns the area of Polygon
	 *
	 * @return area 
	 */
	 public abstract double area();
	 /**
	 * Returns the perimeter of Polygon
	 *
	 * @return perimeter
	 */
   	 public abstract double perimeter();
   	 /**
	 * Increments the polygon positions 1.0
	 *
	 * @return new Polygon
	 */
   	 public abstract Polygon increment();
   	 /**
	 * Increments the polygon positions 1.0
	 *
	 * @return new Polygon
	 */
   	 public abstract Polygon decrement();
   	 /**
	 * Draws the shape 
	 * 
	 * @param g Graphics object
	 */
   	 public abstract void draw(Graphics g);
   	 /**
	 * Compare shapes respect to their areas
	 * 
	 * @return 0,-1 or 1
	 */
   	 public abstract String shapeName();
   
   	/**
 	* The Inner Class Point2D
 	**/
    public class Point2D{

	private double x;
	private double y;

	/**
	 * Sets x coordinate.
	 */
	public void set_x(double my_x)throws RuntimeException{

	x=my_x;

	}

	/**
	 * Sets y coordinate.
	 */
	public void set_y(double my_y)throws RuntimeException{

		y=my_y;
		
	}
	/**
	 * Instantiates points.
	 */
	public Point2D( double my_x, double my_y){

		set_x(my_x);
		set_y(my_y);
	}
	 /**
	 * Returns x coordinate.
	 * 
	 * @return x
	 */
	public double get_x()  {return x;}
	/**
	 * Returns y coordinate.
	 * 
	 * @return y
	 */
	public double get_y() {return y;}

	
	}



}
	