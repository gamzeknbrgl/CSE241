import java.lang.Math; 
import java.awt.Graphics;
import javax.swing.JPanel;
import java.awt.Color;
import java.awt.Polygon;
/**
 * The Class Triangle
 *
 */

public class Triangle extends JPanel implements Shape{
	
	/* Edge of triangle */
	private double edge;
	/*x, y , z coordinates of triangle */
	private double x;
	private double y;
	private double z;
	/*Total area and total perimeter static class variables */
	private static double total_area=0;
	private static double total_perimeter=0;
	/**
	 * Returns the name of Shape
	 * 
	 * @return name
	 */
	public String shapeName() {return "Triangle";}

	/**
	 * Instantiates a new Triangle
	 */
	public Triangle(){

		this(0,0,0,0);
	}
	 /**
	 * Four parameter constructor for Triangle
	 */
	public Triangle(double my_edge, double my_x, double my_y, double my_z){

		set_edge(my_edge);
		set_positions(my_x, my_y,my_z);
		total_area+=area();
		total_perimeter+=perimeter();

 	}
 	 /**
	 * Three parameter constructor for Triangle.
	 */
 	public Triangle(double my_x, double my_y, double my_z) {
	
		set_positions(my_x, my_y,my_z);

 	}
 	/**
	 * Returns x coordinate of Triangle
	 * 
	 * @return x
	 */
 	public double get_x() {return x;}
 	 /**
	 * Returns y coordinate of Triangle
	 * 
	 * @return y
	 */
 	public double get_y() {return y;}
 	 /**
	 * Returns z coordinate of Triangle
	 * 
	 * @return z
	 */
 	public double get_z() {return z;}
 	 /**
	 * Returns edge of Triangle
	 * 
	 * @return edge
	 */
 	public double get_edge() {return edge;}
 	/**
	 * Sets edge
	 */
 	public void set_edge(double my_edge)throws RuntimeException{

	if(my_edge>0){

		edge=my_edge;
	}
	else
		throw new RuntimeException("Invalid edge");
	}
	/**
	 * Sets positions
	 */
	public void set_positions(double my_x, double my_y, double my_z)throws RuntimeException{

		int wrong_x=-1, wrong_y=-1, wrong_z=-1;
		if(my_x>=0 && my_y>=0 && my_z>=0){
			
			x=my_x;
			y=my_y;
			z=my_z;
			}
		else if(my_x<0)
			throw new RuntimeException("Invalid x");
		else if(my_y<0)
			throw new RuntimeException("Invalid y");
		else if (my_z<0)
			throw new RuntimeException("Invalid z");

	}
	/**
	 * Draws the Triangle
	 * 
	 * @param g Graphics object
	 */
	public void draw(Graphics g){
		
		Polygon poly;

		poly = new Polygon(new int[] {(int)(x+edge/2), (int)(x+edge), (int)x }, new int[] {(int) z,(int) y,(int) y }, 3);

		g.setColor(Color.BLACK);
		g.drawPolygon(poly);
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
	 * Returns the perimeter of Triangle
	 *
	 * @return perimeter
	 */
	public double perimeter() {

		double tri_perimeter;
		tri_perimeter=3*edge;
		return tri_perimeter;
	
	}
	/**
	 * Returns the area of Triangle
	 *
	 * @return area
	 */
	public double area(){

		double tri_area;
		tri_area=(Math.sqrt(3)*edge*edge)/4;
		return tri_area;
	}
	/**
	 * Increments the triangle positions 1.0
	 *
	 * @return new Triangle
	 */
	public Triangle increment(){

		x++;
		y++;
		z++;

		return new Triangle(edge,x,y,z);

	}
	/**
	 * Decrements the triangle positions 1.0
	 *
	 * @return new Triangle
	 */
	public Triangle decrement(){

		if(x-1>=0 && y-1>=0 && z-1>=0){
			x--;
			y--;
			z--;
		}	
		return new Triangle(edge,x,y,z);

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