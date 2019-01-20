import java.awt.Graphics;
import java.awt.*;  
import javax.swing.*;  
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.event.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.JButton;
import java.util.ArrayList;

public class Main {

	/**
	 * Takes an array of Shapes and increasingly sorts them with respect to their areas. 
	 * 
	 * @param shapes Shape objects array
	 */
	public static void sortShapes(Shape[] shapes){

		Shape[] sortShapes;
		System.out.printf("\nBefore sorting\n");
		for (int i=0; i<shapes.length; i++){
			System.out.printf("%s  & area: %.1f \n", shapes[i].shapeName(), shapes[i].area());
		}

		for (int i=0; i<shapes.length; i++){
	

			for(int j=i+1; j<shapes.length; j++){

				if(shapes[i].area()>shapes[j].area()){

					Shape temp=shapes[i];
					shapes[i]=shapes[j];
					shapes[j]=temp;

				}	
			}
		}
		System.out.printf("\nAfter sorting\n");
		for (int i=0; i<shapes.length; i++){

			System.out.printf("%s  & area: %.1f \n", shapes[i].shapeName(), shapes[i].area());
		}
	}
	/**
	 * takes an array of Shape references, converts all shapes to Polygons 
	 * and returns a new array with the new shapes
	 *
	 * @param shapes Shape objects array
	 * @return array
	 */
	public static PolygonDyn[] convertAll(Shape[] shapes){

		PolygonDyn[] newArray= new PolygonDyn[shapes.length];

		for (int i=0; i<shapes.length; i++){

			     if(shapes[i].shapeName()=="Rectangle"){

			     	Rectangle aa= (Rectangle)shapes[i];
			     	PolygonDyn a= new PolygonDyn(aa);
			     	newArray[i]=a;
			     	
			     }
			     else if(shapes[i].shapeName()=="Triangle"){
			
					Triangle bb= (Triangle)shapes[i];
			     	PolygonDyn b= new PolygonDyn(bb);
			     	newArray[i]=b;
			     }
			     else if(shapes[i].shapeName()=="Circle"){

			     	Circle cc= (Circle)shapes[i];
			     	PolygonDyn c= new PolygonDyn(cc);
			     	newArray[i]=c;
			     }

		}
		return newArray;
	}
	 /**
	 * Takes an array of Shape references and draws all shapes to an JPanel 
	 * 
	 * @param shapes Shape objects array
	 */
	public static void drawAll(Shape[] shapes){

		JFrame frame=new JFrame();
		JPanel main = new JPanel();
 		main.setLayout(new BoxLayout(main, BoxLayout.Y_AXIS));
 		frame.add(main);
 		frame.setTitle("Draw All");
 		frame.setSize(1000,1000);
 		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
 		JPanel x= new JPanel();
		frame.getContentPane().add(x); 
		Graphics g1 = x.getGraphics();
		PolygonDyn[] newArray= new PolygonDyn[shapes.length];
		newArray=convertAll(shapes);
		newArray[1].paintComponent(g1);
		main.add(newArray[1]);
		for (int i=0; i<newArray.length; i++){
			
			newArray[i].paintComponent(g1);
			main.add(newArray[i]);
		}

	}
    /**
	 * Makes GUI Stuff, adds buttons & calls paintComponent functions.
	 */
	public static void guidraw(){

		final JFrame frame=new JFrame();
		final JPanel main = new JPanel();
 		main.setLayout(new BoxLayout(main, BoxLayout.Y_AXIS));
 		frame.add(main);
 		frame.setTitle("HW7 Output");
		frame.setSize(1000,1000);
		frame.setVisible(true);
		 JPanel x= new JPanel();
		frame.getContentPane().add(x); 
		final Graphics g1 = x.getGraphics();
		JButton shape;
    	JButton composedshape;
    	JButton polygonvect;
    	JButton drawall;
    	JButton exit;
    	JButton polygondyn;

    	shape = new JButton("Add a Shape");
    	shape.setSize(50, 100);
    	composedshape = new JButton("Add ComposedShapes");
    	composedshape.setSize(50, 100);
    	polygonvect=new JButton("Add a Polygon with PolygonVect");
    	polygonvect.setSize(50, 100);
    	polygondyn=new JButton("Add a Polygon with PolygonDyn");
    	polygonvect.setSize(50, 100);
    	drawall = new JButton("Call the drawAll function");
    	drawall.setSize(50, 100);
    	exit = new JButton("Exit");
    	exit.setSize(50, 100);

    	main.add(shape);
    	main.add(composedshape);
    	main.add(polygonvect);
    	main.add(polygondyn);
    	main.add(drawall);
    	main.add(exit);
    
       	shape.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {

				Triangle t33=new Triangle(150,0,(150*Math.sqrt(3)/2),0);
        		main.add(t33);
        		t33.paintComponent(g1);
				frame.setVisible(true);
        		
			}
		});

       	polygonvect.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {

				ArrayList<PolygonVect.Point2D> a= new ArrayList<PolygonVect.Point2D>();
				PolygonVect b= new PolygonVect();
				PolygonVect.Point2D c = b.new Point2D(100,10);
				a.add(c);	
				PolygonVect.Point2D d = b.new Point2D(40,198);	
				a.add(d);
				PolygonVect.Point2D ee = b.new Point2D(190,78);	
				a.add(ee);
				PolygonVect.Point2D f= b.new Point2D(10,78);
				a.add(f);
				PolygonVect.Point2D g= b.new Point2D(160,198);
				a.add(g);
				PolygonVect t27=new PolygonVect(a);;
				t27.paintComponent(g1);
				main.add(t27);
				frame.setVisible(true);

			}
		});  

       	polygondyn.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				
				Circle t12=new Circle(50,50,50);
				PolygonDyn np=new PolygonDyn(t12);;
				np.paintComponent(g1);
				main.add(np);
				frame.setVisible(true);
			}
		});  
		composedshape.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {

					Rectangle t1= new Rectangle(300,100,200,0);
					Circle t2=new Circle(50,100,0);
					Rectangle ww= new Rectangle(50,40,0,0);
					Circle w2=new Circle(100,50,50);
					ComposedShape t4=new ComposedShape(t1,t2);
					ComposedShape t55=new ComposedShape(w2,ww);
					t55.optimalFit();
					t55.paintComponent(g1);
					main.add(t55);

					frame.setVisible(true);
			
			}
		});

		drawall.addMouseListener(new MouseAdapter() {
		@Override
		public void mouseClicked(MouseEvent e) {

					Rectangle a= new Rectangle(400,100,0,0);
					Circle b=new Circle(50,50,50);
					Triangle tt=new Triangle(150,0,(150*Math.sqrt(3)/2),0);
					frame.setVisible(false);
					Shape [] arr= new Shape[3];
					arr[0]= a;
					arr[1]=b;
					arr[2]=tt;
					drawAll(arr);	
			}
		});

		exit.addMouseListener(new MouseAdapter() {
		@Override
		public void mouseClicked(MouseEvent e) {

				frame.setVisible(false);
				
			}
		});
			

	}
	public static void main(String[] args){


		System.out.println("***********************************************");
		System.out.println("TEST PART FOR AREA & PERIMETER FUNCTIONS");
		try{

			Rectangle a= new Rectangle(400,100,0,0);
			Circle b=new Circle(50,50,50);
			Triangle d=new Triangle(50,0,0,0);	
			Rectangle p=new Rectangle(50,50,0,0);
			Rectangle aa=new Rectangle(500,100,0,0);
			Circle u=new Circle(40,0,0);
			Circle uu=new Circle(50,25,25);
			Triangle tt=new Triangle(150,0,(150*Math.sqrt(3)/2),0);
			Triangle d2=new Triangle(30,0,0,0);	
			Triangle t2=new Triangle(200,0,(200*Math.sqrt(3)/2),0);
			Rectangle pp=new Rectangle(50,50,300,0);
			Rectangle p3=new Rectangle(30,40,0,0);
			PolygonVect p1=new PolygonVect(a);
			PolygonDyn p2=new PolygonDyn(a);
			ComposedShape cc=new ComposedShape(a,b);

			System.out.println("Test object: Rectangle, width:400,height:100");
			System.out.printf("Area is: %.1f, Perimeter is: %.1f \n", a.area(), a.perimeter());
			System.out.println("Test object: Circle, radius :50");
			System.out.printf("Area is: %.1f, Perimeter is: %.1f \n", b.area(), b.perimeter());
			System.out.println("Test object: Triangle, edge :30");
			System.out.printf("Area is: %.1f, Perimeter is: %.1f \n", d2.area(), d2.perimeter());
			System.out.println("Test object: PolygonDyn (USES A RECTANGLE), width:400 height:100");
			System.out.printf("Area is: %.1f, Perimeter is: %.1f \n", p2.area(), p2.perimeter());
			System.out.println("Test object: PolygonVect (USES A RECTANGLE), width:400 height:100");
			System.out.printf("Area is: %.1f, Perimeter is: %.1f \n", p1.area(), p1.perimeter());
			System.out.println("Test object: ComposedShape (RETURNS CONTAINER SHAPES AREA), width:400 height:100");
			System.out.printf("Area is: %.1f, Perimeter is: %.1f \n", cc.area(), cc.perimeter());

			System.out.println("***********************************************");

			System.out.println("TEST PART FOR INCREMENT & DECREMENT FUNCTIONS");
			Circle c1=new Circle(50,25,25);
			System.out.println("Test object: Circle, x:25,y:25, call the INCREMENT Function");
			c1.increment();
			System.out.printf("new x: %.1f & new y: %.1f\n",c1.get_x(), c1.get_y());
			Rectangle a1= new Rectangle(400,100,10,10);
			System.out.println("Test object: Rectangle, x:10,y:10, call the DECREMENT Function");
			a1.decrement();
			System.out.printf("new x: %.1f & new y: %.1f\n",a1.get_x(), a1.get_y());

			System.out.println("***********************************************");

			System.out.println("TEST PART FOR COMPARETO FUNCTIONS");
			System.out.printf("Test objects: Circle & Rectangle & their areas: %.1f , %.1f\n",c1.area(), a1.area());
			c1.compareTo(a1);
			System.out.printf("Test objects: Circle & Circle & their areas: %.1f , %.1f\n",c1.area(), c1.area());
			c1.compareTo(c1);
			System.out.printf("Test objects: Circle & Polygon & their areas: %.1f , %.1f\n",p1.area(), p1.area());
			c1.compareTo(p1);


			System.out.println("***********************************************");
			System.out.println("TEST PART FOR STATIC SORT SHAPES FUNCTION");
			Triangle dd=new Triangle(100,0,(100*Math.sqrt(3)/2),0);
			Shape [] arr= new Shape[5];
			arr[0]= a;
			arr[1]=b;
			arr[2]=dd;
			arr[3]=p;
			arr[4]=tt;
			//drawAll(arr);
			sortShapes(arr);
			System.out.println("***********************************************");


		}
		catch (Exception e) {
			System.out.println("Error occurs: " + e.getMessage());
		}

		guidraw();
	}



}
