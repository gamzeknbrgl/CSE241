import java.lang.Math; 
import java.awt.Graphics;
import javax.swing.JPanel;
import java.awt.Color;
import java.util.ArrayList;
/**
 * The Class PolygonVect uses ArrayList to keep the 2D points
 *
 */

public class PolygonVect extends Polygon{

	/*ArrayList for keeping points*/
	private ArrayList<Point2D> points_2D; 
	/**
	 * Returns the name of Shape
	 * 
	 * @return name
	 */
	public String shapeName() {return "Polygon";}
	/**
	 * Instantiates a new PolygonVect
	 */
	public PolygonVect(){

		points_2D=new ArrayList<Point2D>();
	}
	/**
	 * Conversion constructor for points in ArrayList
	 */
	public PolygonVect(ArrayList<Point2D> myPoints){
	
		points_2D=new ArrayList<Point2D>();
		for (int i=0; i<myPoints.size(); i++){

			points_2D.add(myPoints.get(i));
		}
	}

	/**
	 * Conversion constructor for rectangle
	 */
	public PolygonVect(Rectangle my_rect){

		points_2D=new ArrayList<Point2D>(); 
		points_2D.add(new Point2D (my_rect.get_x(),my_rect.get_y()));
		points_2D.add(new Point2D(my_rect.get_x()+my_rect.get_width(), my_rect.get_y()));
		points_2D.add(new Point2D(my_rect.get_x()+my_rect.get_width(), my_rect.get_y()+my_rect.get_height()));
		points_2D.add(new Point2D(my_rect.get_x(), my_rect.get_y()+my_rect.get_height()));

	}
	/**
	 * Conversion constructor for triangle
	 */
	public PolygonVect(Triangle my_tri){

		points_2D=new ArrayList<Point2D>(); 
		points_2D.add(new Point2D(my_tri.get_x(), my_tri.get_y()));
		points_2D.add(new Point2D(my_tri.get_x()+(my_tri.get_edge()/2), my_tri.get_z()));
		points_2D.add(new Point2D(my_tri.get_x()+my_tri.get_edge(), my_tri.get_y()));
	}
	/**
	 * Conversion constructor for circle
	 */
	public PolygonVect(Circle my_circle){

		points_2D=new ArrayList<Point2D>(); 
		double my_x, my_y, my_radius, temp_x, temp_y, temp;
		double s=(2*Math.PI)/100;
		my_x= my_circle.get_x();
		my_y=my_circle.get_y();
		my_radius=my_circle.get_radius();
		for (int i=0; i<100; i++){

			temp=s*i;
			temp_x= (my_x)+ (my_radius *Math.cos(temp));
			temp_y= (my_y)+ (my_radius *Math.sin(temp));	
			points_2D.add(new Point2D(temp_x,temp_y));
		
		}
	}
	/**
	 * Draws the Rectangle
	 * 
	 * @param g Graphics object
	 */
	public void draw(Graphics g){

		 int my_x[]=new int[points_2D.size()];
		 int my_y[]=new int[points_2D.size()];

		 for(int i=0; i<points_2D.size(); i++){
			my_x[i]=(int)(points_2D.get(i).get_x());
			my_y[i]=(int)(points_2D.get(i).get_y());
		}
		g.setColor(Color.RED);
		g.drawPolygon(my_x, my_y, points_2D.size());

	}
	/**
	 * Override from JPanel
	 * 
	 * @param g Graphics object
	 */
	public void paintComponent(Graphics g){

		super.paintComponent(g);
		draw(g);
	}
	/**
	 * Returns the area of Polygon
	 *
	 * @return area
	 */
	public double area() {

		double area=0, x=0, y=0, z=0;
		for(int i=1; i<points_2D.size()-1; i++){

			x=(points_2D.get(i).get_x()*points_2D.get(i+1).get_y());
			y=(points_2D.get(i).get_y()*points_2D.get(i+1).get_x());
			z=x-y;
			area+=z;
		}
		x=(points_2D.get(0).get_x()*points_2D.get(points_2D.size()-1).get_y());
		y=(points_2D.get(0).get_y()*points_2D.get(points_2D.size()-1).get_x());
		z=x-y;
		area+=z;
		area=area/2;
		if(area<0)
			area=area*-1;
		return area; 

	}
	/**
	 * Returns the perimeter of Polygon
	 *
	 * @return perimeter
	 */
	public double perimeter(){

		double perimeter=0, x=0,y=0,z=0;

		for(int i=1; i<points_2D.size(); i++){
			
			x=(points_2D.get(i).get_x()-points_2D.get(i-1).get_x())*(points_2D.get(i).get_x()-points_2D.get(i-1).get_x());
			y=(points_2D.get(i).get_y()-points_2D.get(i-1).get_y())*(points_2D.get(i).get_y()-points_2D.get(i-1).get_y());
			z=Math.sqrt(x+y);
			perimeter+=z;
		}
		x=(points_2D.get(0).get_x()-points_2D.get(points_2D.size()-1).get_x())*(points_2D.get(0).get_x()-points_2D.get(points_2D.size()-1).get_x());
		y=(points_2D.get(0).get_y()-points_2D.get(points_2D.size()-1).get_y())*(points_2D.get(0).get_y()-points_2D.get(points_2D.size()-1).get_y());
		z=Math.sqrt(x+y);
		perimeter+=z;
		if(perimeter<0)
			perimeter=perimeter*-1;
		return perimeter;

	}
	/**
	 * Increments the polygon positions 1.0
	 *
	 * @return new polygon
	 */
	public PolygonVect increment(){

		for(int i=1; i<points_2D.size(); i++){

			points_2D.get(i).set_x(points_2D.get(i).get_x()-1);
	 		points_2D.get(i).set_y(points_2D.get(i).get_y()-1);
	 	}
	 	return this;
			
	}
	/**
	 * Decrements the polygon positions 1.0
	 *
	 * @return new polygon
	 */
	public PolygonVect decrement(){

		for(int i=1; i<points_2D.size(); i++){

			points_2D.get(i).set_x(points_2D.get(i).get_x()+1);
	 		points_2D.get(i).set_y(points_2D.get(i).get_y()+1);
 		}
 		return this;
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