import java.lang.Math; 
import java.awt.Graphics;
import javax.swing.JPanel;
import java.awt.Color;
/**
 * The Class PolygonVect uses Java arrays to keep the 2D points
 *
 */
public class PolygonDyn extends Polygon{

	/*Array for keeping points*/
	private Point2D[] points_2D;
	/*vertices of polygon*/
	private int vertices;
	/**
	 * Returns the name of Shape
	 * 
	 * @return name
	 */
	public String shapeName() {return "Polygon";}
	/**
	 * Instantiates a new PolygonVect
	 */
	public PolygonDyn(){

	}
	/**
	 * Conversion constructor for points in Array
	 */
	public PolygonDyn(Point2D[] my_points){

		vertices=my_points.length;
		points_2D= new Point2D[my_points.length];
		for (int i=0; i<my_points.length; i++){

			points_2D[i]=my_points[i];
		}

	}
	/**
	 * Conversion constructor for rectangle
	 */
	public PolygonDyn (Rectangle my_rect){

		vertices=4;
		points_2D= new Point2D[4];
		points_2D[0]= new Point2D(my_rect.get_x(), my_rect.get_y());
		points_2D[1]= new Point2D(my_rect.get_x()+my_rect.get_width(), my_rect.get_y());
		points_2D[2]= new Point2D(my_rect.get_x()+my_rect.get_width(), my_rect.get_y()+my_rect.get_height());
		points_2D[3]= new Point2D(my_rect.get_x(), my_rect.get_y()+my_rect.get_height());

	}
	/**
	 * Conversion constructor for triangle
	 */
	public PolygonDyn (Triangle my_tri){

		vertices=3;
		points_2D= new Point2D[3];
		points_2D[0]= new Point2D(my_tri.get_x(), my_tri.get_y());
		points_2D[1]= new Point2D(my_tri.get_x()+(my_tri.get_edge()/2), my_tri.get_z());
		points_2D[2]= new Point2D(my_tri.get_x()+my_tri.get_edge(), my_tri.get_y());
	}
	/**
	 * Conversion constructor for circle
	 */
	public PolygonDyn (Circle my_circle){

		vertices=100;
		points_2D= new Point2D[100];
		double my_x, my_y, my_radius, temp_x, temp_y, temp;
		double s=(2*Math.PI)/100;
		my_x= my_circle.get_x();
		my_y=my_circle.get_y();
		my_radius=my_circle.get_radius();
		for (int i=0; i<100; i++){

			temp=s*i;
			temp_x= (my_x)+ (my_radius *Math.cos(temp));
			temp_y= (my_y)+ (my_radius *Math.sin(temp));	
			points_2D[i]=new Point2D(temp_x, temp_y);			
		}

	}
	/**
	 * Draws the Polygon
	 * 
	 * @param g Graphics object
	 */
	public void draw(Graphics g){

		 int my_x[]=new int[vertices];
		 int my_y[]=new int[vertices];

		 for(int i=0; i<vertices; i++){
			my_x[i]=(int)(points_2D[i].get_x());
			my_y[i]=(int)(points_2D[i].get_y());
		}
		g.setColor(Color.RED);
		g.drawPolygon(my_x, my_y, vertices);

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
	 * Returns the perimeter of Polygon
	 *
	 * @return perimeter
	 */
	public double perimeter(){

		double perimeter=0,x=0,y=0,z=0;

		for(int i=1; i<vertices; i++){

			x=(points_2D[i].get_x()-points_2D[i-1].get_x())*(points_2D[i].get_x()-points_2D[i-1].get_x());
			y=(points_2D[i].get_y()-points_2D[i-1].get_y())*(points_2D[i].get_y()-points_2D[i-1].get_y());
			z=Math.sqrt(x+y);
			perimeter+=z;
		}
		x=(points_2D[0].get_x()-points_2D[vertices-1].get_x())*(points_2D[0].get_x()-points_2D[vertices-1].get_x());
		y=(points_2D[0].get_y()-points_2D[vertices-1].get_y())*(points_2D[0].get_y()-points_2D[vertices-1].get_y());
		z=Math.sqrt(x+y);
		perimeter+=z;
		if(perimeter<0)
			perimeter=perimeter*-1;
		return perimeter;
	}
	/**
	 * Returns the area of Polygon
	 *
	 * @return area
	 */
	public double area() {

		double area=0, x=0, y=0, z=0;
		for(int i=1; i<vertices-1; i++){

			x=(points_2D[i].get_x()*points_2D[i+1].get_y());
			y=(points_2D[i].get_y()*points_2D[i+1].get_x());
			z=x-y;
			area+=z;
		}
		x=(points_2D[0].get_x()*points_2D[vertices-1].get_y());
		y=(points_2D[0].get_y()*points_2D[vertices-1].get_x());
		z=x-y;
		area+=z;
		area=area/2;
		if(area<0)
			area=area*-1;
		return area; 

	}
	/**
	 * Increments the polygon positions 1.0
	 *
	 * @return new polygon
	 */
	public PolygonDyn increment(){

		for(int i=1; i<vertices; i++){

			points_2D[i].set_x(points_2D[i].get_x()+1);
	 		points_2D[i].set_y(points_2D[i].get_y()+1);
	 	}
	 		return this;
	}
	/**
	 * Decrements the polygon positions 1.0
	 *
	 * @return new polygon
	 */
	public PolygonDyn decrement(){

		for(int i=1; i<vertices; i++){

		points_2D[i].set_x(points_2D[i].get_x()-1);
 		points_2D[i].set_y(points_2D[i].get_y()-1);
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