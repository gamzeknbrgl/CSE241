import java.lang.Math; 
import java.awt.Graphics;
import javax.swing.JPanel;
import java.awt.Color;
/**
 * The Class Rectangle
 *
 */

public class Rectangle extends JPanel implements Shape {
	
	/*width and height of rectangle */
	private double height;
	private double width;
	/*x y coordinates of rectangle*/
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
	public String shapeName() {return "Rectangle";}
	/**
	 * Instantiates a new Rectangle
	 */
	public Rectangle(){

		this(0,0,0,0);
	}
	/**
	 * Four parameter constructor for Rectangle
	 */
	public Rectangle(double my_width, double my_height, double my_x, double my_y){

	set_height_width(my_width,my_height);
	set_positions(my_x, my_y);
	total_area+=area();
	total_perimeter+=perimeter();

	}
	/**
	 * Two parameter constructor for Rectangle
	 */
	public Rectangle(double my_x, double my_y){

 	set_positions(my_x, my_y);

 	}
    /**
	* Returns y coordinate of Rectangle
	* 
	* @return y
	*/
 	public double get_y() {return y;}
 	/**
	* Returns x coordinate of Rectangle
	* 
	* @return x
	*/
 	public double get_x() {return x;}
 	/**
	* Returns width coordinate of Rectangle
	* 
	* @return width
	*/
 	public double get_width() {return width;}
 	/**
	* Returns width coordinate of Rectangle
	* 
	* @return height
	*/
 	public double get_height() {return height;}
 	/**
	 * Sets width & height
	 */
 	public void set_height_width(double my_width, double my_height) throws RuntimeException{
	
		if(my_width>0 && my_height>0){
			
			width=my_width;
			height=my_height;
		}
		else if(my_width<0)
			throw new RuntimeException("Invalid width");
		else if(my_height<0)
			throw new RuntimeException("Invalid height");

	}
	/**
	 * Sets positions
	 */
	public void set_positions(double my_x, double my_y)throws RuntimeException {
		
		if(my_x>=0 && my_y>=0){
			x=my_x;
			y=my_y;	
			}
		else if (my_x<0)
			throw new RuntimeException("Invalid x");
		else if(my_y<0)
			throw new RuntimeException("Invalid y");

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
	 * Draws the Rectangle
	 * 
	 * @param g Graphics object
	 */
	public void draw(Graphics g){

		g.setColor(Color.RED);
		g.drawRect((int)x,(int)y,(int)width,(int)height);
		

	}
	/**
	 * Returns the perimeter of Rectangle
	 *
	 * @return perimeter
	 */
	public double perimeter() {

		double rect_perimeter;
		rect_perimeter=(width+height)*2;
		return rect_perimeter;
	}	
	/**
	 * Returns the area of Rectangle
	 *
	 * @return area
	 */
	public double area(){

	
		double rect_area;
		rect_area=width*height;
		return rect_area;

	}
	/**
	 * Decrements the rectangle positions 1.0
	 *
	 * @return new Rectangle
	 */
	public Rectangle decrement(){

		if(x-1>=0 && y-1>=0 ){
			x--;
			y--;
		}	
		return new Rectangle(width,height,x,y);

	 }
	 /**
	 * Increments the rectangle positions 1.0
	 *
	 * @return new Rectangle
	 */
	public Rectangle increment(){

		x++;
		y++;

		return new Rectangle(width,height,x,y);

	}
	/**
	 * Compare shapes respect to their areas, overrides from Comparable
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