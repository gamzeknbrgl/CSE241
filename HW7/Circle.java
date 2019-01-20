import java.lang.Math; 
import java.awt.Graphics;
import javax.swing.JPanel;
import java.awt.Color;
/**
 * The Class Circle
 *
 */

public class Circle extends JPanel implements Shape {
	
	/*Radius of circle*/
	private double radius;
	/*x and y coordinates of circle*/
	private double x;
	private double y;
	/*Total area and total perimeter static class variables */
	private static double total_area=0;
	private static double total_perimeter=0;
	/**
	 * Returns the name of Shape
	 * 
	 * @return name
	 */
	public String shapeName() {return "Circle";}

	/**
	 * Instantiates a new Circle.
	 */
	public Circle(){

		this(0,0,0);
 	}
 	/**
	 * Three parameter constructor for Circle.
	 */
 	public Circle(double my_radius, double my_x, double my_y){
		set_radius(my_radius);
		set_x(my_x);
		set_y(my_y);
		total_area+=area();
		total_perimeter+=perimeter();
	}
	 /**
	 * Two parameter constructor for Circle.
	 */
	public Circle(double my_x, double my_y){
		set_x(my_x);
		set_y(my_y);
	}
	/**
	 * One parameter constructor for Circle.
	 */
	public Circle(double my_radius){

		set_radius(my_radius);

	}
	/**
	 * Sets radius
	 */
	public void set_radius(double my_radius)throws RuntimeException{

		
		if(my_radius>0){
			radius=my_radius;
		}	
		else
			throw new RuntimeException("Invalid radius");
	}
	/**
	 * Returns radius of Circle
	 * 
	 * @return radius
	 */

	public double get_radius(){

		return radius;
	}
	/**
	 * Returns x coordinate of Circle
	 * 
	 * @return x
	 */
	public double get_x(){

		return x;
	}
	/**
	 * Returns y coordinate of Circle
	 * 
	 * @return y
	 */
	public double get_y(){

		return y;
	}
	/**
	 * Sets x coordinate
	 */
	public void set_x(double my_x)throws RuntimeException{

		
		if(my_x>=0 ){
			x=my_x;
			}
		else
			 throw new RuntimeException("Invalid x");
	}
	/**
	 * Sets y coordinate
	 */
	public void set_y(double my_y) throws RuntimeException{

		
		if(my_y>=0 ){
			y=my_y;
			}
		else
			throw new RuntimeException("Invalid y");
	}
	 /**
	 * Draws the Circle 
	 * 
	 * @param g Graphics object
	 */
	public void draw(Graphics g){

		int my_x = (int)( x-(radius/2));
  		int	my_y = (int) (y-(radius/2));
		g.setColor(Color.BLUE);
		g.drawOval(my_x,my_y,(int)radius*2,(int)radius*2);
	
	}
	/**
	 * Override from JPanel
	 * 
	 * @param g Graphics object
	 */
	@Override
	public void paintComponent(Graphics g){

		super.paintComponent(g);
		draw(g);
	}
	/**
	 * Returns the perimeter of Circle
	 *
	 * @return perimeter
	 */
	public double perimeter(){

		double circle_perimeter;
		circle_perimeter=2* Math.PI *radius;
		return circle_perimeter;
	}
   
	/**
	 * Returns the area of Circle
	 *
	 * @return area 
	 */
	public double area() {

			double circle_area;
			circle_area= Math.PI *radius*radius;
			return circle_area;
	
	}
	/**
	 * Decrements the circle positions 1.0
	 *
	 * @return new Circle
	 */
	public Circle decrement(){

		if(x-1>=0 && y-1>=0 ){
			x--;
			y--;
		}	
		return new Circle(radius,x,y);

	}
	 /**
	 * Increments the circle positions 1.0
	 *
	 * @return new Circle
	 */
	public Circle increment(){

		x++;
		y++;

		return new Circle(radius,x,y);

	}
	 /**
	 * Compare shapes respect to their areas
	 * 
	 * @return 0,-1 or 1
	 */
	@Override public int compareTo(Shape that){

		final int BEFORE = -1;
	    final int EQUAL = 0;
	    final int AFTER = 1;

		    if (this.area()==that.area()){

		    	System.out.println("EQUAL AREAS,EQUAL SHAPES\n");
		     	return EQUAL;
		    }
		    else if (this.area() < that.area()) {

		    	System.out.println("SHAPE1 IS SMALL ONE\n");
		    	return BEFORE;
		    }
		  	 else
		  	 	System.out.println("SHAPE2 IS SMALL ONE\n");
		   		return AFTER;
	   
	}
}