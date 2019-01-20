import java.lang.Math; 
import java.awt.Graphics;
import javax.swing.JPanel;
import java.awt.Color;
/**
 * The Class ComposedShape
 *
 */

public class ComposedShape extends JPanel implements Shape{

	/*Container & inner shapes */
	private Rectangle my_cont_rect, my_small_rect;
	private Circle my_cont_circle, my_small_circle;
	private Triangle my_cont_tri, my_small_tri;
	/* keeps an array of Shape references  for the shape elements. */
	private Shape [] shapes;
	/*Container & inner shape types */
	private char cont_type;
	private char inner_type;
	/**
	 * Returns the name of Shape
	 * 
	 * @return name
	 */
	public String shapeName() {return "ComposedShape";}

	/**
	*Using that constructors for:
	*Setting of container and small shape types with char variables
	*and assigning it to ComposedShape class variables that i have created
	*/
	public ComposedShape(Rectangle cont_rect, Circle small_circle){
	
		my_cont_rect=cont_rect;
		my_small_circle=small_circle;
		char cont_type='R';
		char inner_type='C';
		set_type(cont_type,inner_type);

	}

    public ComposedShape(Rectangle cont_rect, Rectangle small_rect){
	
		my_cont_rect=cont_rect;
		my_small_rect=small_rect;
		char cont_type='R';
		char inner_type='R';
		set_type(cont_type,inner_type);

	}

	public ComposedShape(Rectangle cont_rect, Triangle small_tri){
	
		my_cont_rect=cont_rect;
		my_small_tri=small_tri;
		char cont_type='R';
		char inner_type='T';
		set_type(cont_type,inner_type);

	}

	public ComposedShape(Triangle cont_tri, Circle small_circle){
	
		my_cont_tri=cont_tri;
		my_small_circle=small_circle;	
		char cont_type='T';
		char inner_type='C';
		set_type(cont_type,inner_type);
	

	}

	public ComposedShape(Triangle cont_tri, Rectangle small_rect){

		my_cont_tri=cont_tri;
		my_small_rect=small_rect;
		char cont_type='T';
		char inner_type='R';
		set_type(cont_type,inner_type);

	}

	public ComposedShape(Triangle cont_tri, Triangle small_tri){

		my_cont_tri=cont_tri;
		my_small_tri=small_tri;
		char cont_type='T';
		char inner_type='T';
		set_type(cont_type,inner_type);

	}

	public ComposedShape(Circle cont_circle, Circle small_circle){

		my_cont_circle=cont_circle;
		my_small_circle=small_circle;
		char cont_type='C';
		char inner_type='C';
		set_type(cont_type,inner_type);
	
	}

	public ComposedShape(Circle cont_circle, Rectangle small_rect){

		my_cont_circle=cont_circle;
		my_small_rect=small_rect;
		char cont_type='C';
		char inner_type='R';
		set_type(cont_type,inner_type);

	}

	public ComposedShape(Circle cont_circle, Triangle small_tri){

		my_cont_circle=cont_circle;
		my_small_tri=small_tri;
		char cont_type='C';
		char inner_type='T';
		set_type(cont_type,inner_type);
	
	}
	/**
	 * Returns the perimeter of container shape
	 *
	 * @return perimeter
	 */
	public double perimeter(){

		if(cont_type=='R'){

			return my_cont_rect.perimeter();

		}
		else if(cont_type=='C'){

			return my_cont_circle.perimeter();
		}

		else 
			return my_cont_tri.perimeter();
		
	}
	/**
	 * Returns the area of container shape
	 *
	 * @return area
	 */
	public double area(){

		if(cont_type=='R'){

			return my_cont_rect.area();

		}
		else if(cont_type=='C'){

			return my_cont_circle.area();
		}

		else 
			return my_cont_tri.area();
		
	}
	/**
	 * Sets types
	 */
	public void set_type(char a, char b)
	{
		if( a=='R' || a=='T' || a=='C')
		{	
			cont_type=a;
		}
		if( b=='R' || b=='T' || b=='C')
		{
			inner_type=b;
		}
	}
	/**
	 * Decrements the container&small shapes positions 1.0
	 *
	 * @return new ComposedShape
	 */
	public ComposedShape decrement(){

		if(cont_type=='R' && inner_type=='R'){

				return new ComposedShape(my_cont_rect.decrement(),my_small_rect.decrement());
		}
		else if(cont_type=='R' && inner_type=='C'){

			return new ComposedShape(my_cont_rect.decrement(),my_small_circle.decrement());
		}
		else if(cont_type=='R' && inner_type=='T'){

			return new ComposedShape(my_cont_rect.decrement(),my_small_tri.decrement());
		}
		else if(cont_type=='C' && inner_type=='C'){
			
			return new ComposedShape(my_cont_circle.decrement(),my_small_circle.decrement());
		}
		else if(cont_type=='C' && inner_type=='T'){

			return new ComposedShape(my_cont_circle.decrement(),my_small_tri.decrement());
				
		}
		else if(cont_type=='C' && inner_type=='R'){

			return new ComposedShape(my_cont_circle.decrement(),my_small_rect.decrement());
		}
		else if(cont_type=='T' && inner_type=='C'){

			return new ComposedShape(my_cont_tri.decrement(),my_small_circle.decrement());
				
		}
		else if(cont_type=='T' && inner_type=='T'){

			return new ComposedShape(my_cont_tri.decrement(),my_small_tri.decrement());
				
		}
		else 

			return new ComposedShape(my_cont_tri.decrement(),my_small_rect.decrement());

	}
	/**
	 * Increments the container&small shapes positions 1.0
	 *
	 * @return new ComposedShape
	 */
	public ComposedShape increment(){

		if(cont_type=='R' && inner_type=='R'){

				return new ComposedShape(my_cont_rect.increment(),my_small_rect.increment());
		}
		else if(cont_type=='R' && inner_type=='C'){

			return new ComposedShape(my_cont_rect.increment(),my_small_circle.increment());
		}
		else if(cont_type=='R' && inner_type=='T'){

			return new ComposedShape(my_cont_rect.increment(),my_small_tri.increment());
		}
		else if(cont_type=='C' && inner_type=='C'){
			
			return new ComposedShape(my_cont_circle.increment(),my_small_circle.increment());
		}
		else if(cont_type=='C' && inner_type=='T'){

			return new ComposedShape(my_cont_circle.increment(),my_small_tri.increment());
				
		}
		else if(cont_type=='C' && inner_type=='R'){

			return new ComposedShape(my_cont_circle.increment(),my_small_rect.increment());
		}
		else if(cont_type=='T' && inner_type=='C'){

			return new ComposedShape(my_cont_tri.increment(),my_small_circle.increment());
				
		}
		else if(cont_type=='T' && inner_type=='T'){

			return new ComposedShape(my_cont_tri.increment(),my_small_tri.increment());
				
		}
		else 
			return new ComposedShape(my_cont_tri.increment(),my_small_rect.increment());
			

	}
	/**
	 * Draws the ComposedShape using shapes draw functions
	 * 
	 * @param g Graphics object
	 */	
	public void draw(Graphics g){


		if(cont_type=='R' && inner_type=='C'){
			
			my_cont_rect.draw(g);
			for(int i=0; i<shapes.length; i++){

				shapes[i].draw(g);
			}
		}
		else if(cont_type=='R' && inner_type=='R'){
			
			my_cont_rect.draw(g);
			for(int i=0; i<shapes.length; i++){

					shapes[i].draw(g);
			}
		}
		else if(cont_type=='R' && inner_type=='T'){
			
			my_cont_rect.draw(g);
			for(int i=0; i<shapes.length; i++){

					shapes[i].draw(g);
			}
		}
		else if(cont_type=='C' && inner_type=='C'){
			
			my_cont_circle.draw(g);
			for(int i=0; i<shapes.length; i++){

					shapes[i].draw(g);
			}
				
		}

		else if(cont_type=='C' && inner_type=='R'){
			
			my_cont_circle.draw(g);
			for(int i=0; i<shapes.length; i++){

				shapes[i].draw(g);	
			}
			
		}
		else if(cont_type=='C' && inner_type=='T'){
			
			my_cont_circle.draw(g);
			for(int i=0; i<shapes.length; i++){

					shapes[i].draw(g);
			}
		}

		else if(cont_type=='T' && inner_type=='C'){

			my_cont_tri.draw(g);
			for(int i=0; i<shapes.length; i++){

					shapes[i].draw(g);
			}
		}
		else if(cont_type=='T' && inner_type=='R'){
			
			my_cont_tri.draw(g);
			for(int i=0; i<shapes.length; i++){

					shapes[i].draw(g);
			}
		}
		else if(cont_type=='T' && inner_type=='T'){
			
			my_cont_tri.draw(g);
			for(int i=0; i<shapes.length; i++){

					shapes[i].draw(g);
			}
		}
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
	 * Calculating how much small shapes can fit in container shape
	 */
	public void optimalFit(){

		double cx,cy, radius=0, s_width, s_height, max_rect=0, x=0,y=0, a,b;
		int max_size=10000, index=0, size=0,i,j, max_triangle=0;
		double ty=0, tx=0, tz=0, t_edge=0, dx=0, temp2=0, rx,ry,h,k, row,w;

		if(cont_type=='R' && inner_type=='C'){
		
			radius=my_small_circle.get_radius();
			cx=my_small_circle.get_radius()/2;
			cy=my_small_circle.get_radius()/2;
			Shape temp[]= new Shape[max_size];
			while(true){

			temp[index]=new Circle(radius,cx,cy);
			size++;
			index++;

			cx+=my_small_circle.get_radius()*2;
			if(cx+my_small_circle.get_radius()>my_cont_rect.get_width()){

				cx=my_small_circle.get_radius();
				cy+=2*my_small_circle.get_radius();
			
			}
			if(cy+my_small_circle.get_radius()>my_cont_rect.get_height())
				break;
			
			}

			shapes=new Shape[size];
			for(i=0; i<size; i++){

				shapes[i]=temp[i];			
			} 

		}
		else if(cont_type=='R' && inner_type=='R'){

			s_width=my_small_rect.get_width();
			s_height=my_small_rect.get_height();
			a= (my_cont_rect.get_width()/my_small_rect.get_width())* (my_cont_rect.get_height()/my_small_rect.get_height());
			b=(my_cont_rect.get_width()/my_small_rect.get_height())*(my_cont_rect.get_height()/my_small_rect.get_width()); 
			x=my_small_rect.get_x();
			y=my_small_rect.get_y();

			Shape temp[]= new Shape[max_size];
			if(a>b){ //Horizontal
			max_rect=a;
			for( i=0; i<max_rect; i++){

				temp[index]=new Rectangle(s_width, s_height, x,y);
				size++;
				index++;
				x=x+(my_small_rect.get_width());
				if(x+(my_small_rect.get_width())>my_cont_rect.get_width()){
				x=my_small_rect.get_x();
				y=y+my_small_rect.get_height();
				}
			}
			}
			else{ //Vertical
			max_rect=b;
			for( i=0; i<max_rect; i++){
				
				temp[index]=new Rectangle(s_width, s_height, x,y);
				size++;
				index++;
				x=x+(my_small_rect.get_height());
				if(x+(my_small_rect.get_height())>my_cont_rect.get_width()){
					x=my_small_rect.get_x();
					y=y+my_small_rect.get_width();
				}
			}
			}
			shapes=new Shape[size];
			for(i=0; i<size; i++){

				shapes[i]=temp[i];			
			} 

		}
		else if( cont_type=='R' && inner_type=='T' ){

			Shape temp[]= new Shape[max_size];
			ty=(my_small_tri.get_edge()/2)*Math.sqrt(3);
			while(my_small_tri.get_edge()<my_cont_rect.get_width() && my_small_tri.get_edge()<my_cont_rect.get_height()){
			t_edge=my_small_tri.get_edge();
			temp[index]=new Triangle(t_edge,tx,ty,tz);
			size++;
			index++;
			tx+=my_small_tri.get_edge();
			if(tx+my_small_tri.get_edge()>my_cont_rect.get_width() ){
				tx=0;
				ty+=(my_small_tri.get_edge()/2)*Math.sqrt(3);
				tz+=(my_small_tri.get_edge()/2)*Math.sqrt(3);
			}
			if(ty>my_cont_rect.get_height())
				break;
			}
			tx=my_small_tri.get_edge()/2; 
			ty=0;
			 tz=(my_small_tri.get_edge()/2)*Math.sqrt(3);
			//inverted triangles
			while(my_small_tri.get_edge()<my_cont_rect.get_width()&& my_small_tri.get_edge()<my_cont_rect.get_height()){ 
				temp[index]=new Triangle(t_edge,tx,ty,tz);
				size++;
				index++;
				tx+=my_small_tri.get_edge();
				if(tx+my_small_tri.get_edge() >my_cont_rect.get_width()){
					tx=my_small_tri.get_edge()/2;
					ty+=(my_small_tri.get_edge()/2)*Math.sqrt(3);
					tz+=(my_small_tri.get_edge()/2)*Math.sqrt(3);
				}
				if(tz>my_cont_rect.get_height())
					break;
			}

			shapes=new Shape[size];
			for(i=0; i<size; i++){

				shapes[i]=temp[i];			
			} 
		}

		else if( cont_type=='C' && inner_type=='C' ){

			Shape temp[]= new Shape[max_size];
			radius=my_small_circle.get_radius();
			cx=my_small_circle.get_radius();
			cy=my_cont_circle.get_radius();
			dx=0;
			while(true){

			temp2=(my_cont_circle.get_radius()*2-(dx*2));
			w=(temp2/(my_small_circle.get_radius()*2));
			if(w!=my_cont_circle.get_radius()/my_small_circle.get_radius())
				w++;
			for( j=0; j<w; j++){

				temp[index]=new Circle(radius,cx,cy); 
				size++;
				index++;
				cx+=my_small_circle.get_radius()*2;
			}
			dx+=(my_small_circle.get_radius()*Math.sqrt(3));
			cx=dx;
			cy-=(my_small_circle.get_radius()*2);
			if(cy-my_small_circle.get_radius()<0)
				break;
			if(2*my_cont_circle.get_radius()-dx<0)
				break;
			if(cy<=0)
				break;
			}
			cx=my_small_circle.get_radius();
			 cy=my_cont_circle.get_radius();
			dx=0;
			while(true){

			temp2=(my_cont_circle.get_radius()*2-(dx*2));
			w=(temp2/(my_small_circle.get_radius()*2));
			if(w!=my_cont_circle.get_radius()/my_small_circle.get_radius())
				w++;
			for(j=0; j<w; j++){
				temp[index]=new Circle(radius,cx,cy); 
				size++;
				index++;
				cx+=my_small_circle.get_radius()*2;
			}
			dx+=(my_small_circle.get_radius()*Math.sqrt(3));
			cx=dx;
			cy+=(my_small_circle.get_radius()*2);
			if(cy+my_small_circle.get_radius()>my_cont_circle.get_radius()*2)
				break;
			if(2*my_cont_circle.get_radius()-dx<0)
				break;
			if(cy>my_cont_circle.get_radius()*2)
				break;
			}		
			shapes=new Shape[size];
			for(i=0; i<size; i++){

				shapes[i]=temp[i];			
			} 	
		}

		else if( cont_type=='C' && inner_type=='R' ){

			cx=my_cont_circle.get_radius();
			 cy=my_cont_circle.get_radius();
			dx=my_small_rect.get_width()/4;
			rx=my_small_rect.get_width()/2;
			ry=my_cont_circle.get_radius();
			s_width=my_small_rect.get_width();
			s_height=my_small_rect.get_height();
			Shape temp[]= new Shape[max_size];
			while(true){
			temp2=(my_cont_circle.get_radius()*2-(dx*2));
			i=(int)(temp2/(my_small_rect.get_width()));
			for(j=0; j<i; j++){

				temp[index]=new Rectangle(s_width,s_height,rx,ry);
				size++;
				index++;

				rx+=my_small_rect.get_width();
			}
			dx+=my_small_rect.get_width()/4;
			rx=dx;
			ry-=my_small_rect.get_height();
			if(ry-my_small_rect.get_height()<0)
				break;
			if(ry<=0)
				break;
			
			}
			rx=my_small_rect.get_width()/2;
			ry=my_cont_circle.get_radius();
			dx=my_small_rect.get_width()/4;
			while(true){
			temp2=((my_cont_circle.get_radius()*2)-(dx*2));
			i=(int)(temp2/(my_small_rect.get_width()));
			for(j=0; j<i; j++){

				temp[index]=new Rectangle(s_width,s_height,rx,ry);
				size++;
				index++;

				rx+=my_small_rect.get_width();
				if(ry!=my_cont_circle.get_radius()){
				}
			}
			dx+=my_small_rect.get_width()/4;
			rx=dx;
			ry+=my_small_rect.get_height();
			if((rx*2)>(my_cont_circle.get_radius()*2))
				break;
			if(ry+(my_small_rect.get_height()*2)>my_cont_circle.get_radius()*2)
				break;
			if(ry+my_small_rect.get_height()>my_cont_circle.get_radius()*2)
				break;
			}

			shapes=new Shape[size];
			for(i=0; i<size; i++){

				shapes[i]=temp[i];			
			} 
		}
			
		else if( cont_type=='C' && inner_type=='T' ){

		Shape temp[]= new Shape[max_size];
		h=((my_small_tri.get_edge()/2)*Math.sqrt(3));
		k=my_cont_circle.get_radius();
		temp2=my_cont_circle.get_radius()*2;
		cx=my_cont_circle.get_radius();
		 cy=my_cont_circle.get_radius();
		ty=my_cont_circle.get_radius();
		tx=0;
		tz= ty-h;
		t_edge=my_small_tri.get_edge();
		tz=k-h;
		while(true){

			temp2=(my_cont_circle.get_radius()*2-(dx*2));
			i=(int)(temp2/my_small_tri.get_edge());
			for(j=0; j<i; j++){
	
				temp[index]=new Triangle(t_edge,tx,tz,ty);
				size++;
				index++;
				tx+=my_small_tri.get_edge();
			}
			dx+=(my_small_tri.get_edge()/2)*Math.sqrt(3);
			tx=dx;
			ty-=h;
			tz-=h;
			if(ty-my_small_tri.get_edge()<0)
				break;
			if(2*my_cont_circle.get_radius()-dx<0)
				break;
			if(ty<=0)
				break;
		}
		temp2=radius*2;
		i=(int)(temp2/my_small_tri.get_edge());
		tx=my_small_tri.get_edge()/2;
		 dx=0;
		h=(my_small_tri.get_edge()/2)*Math.sqrt(3);
		ty=my_cont_circle.get_radius();
		tz=k-h;
		while(true){
			temp2=(my_cont_circle.get_radius()*2-(dx*2));
			i=(int)(temp2/my_small_tri.get_edge());
			for(j=0; j<i-1; j++){
				if(i!=my_cont_circle.get_radius()*2/my_small_tri.get_edge())
				max_triangle++;	
				temp[index]=new Triangle(t_edge,tx,tz,ty);
				size++;
				index++;
				tx+=my_small_tri.get_edge();
			}
			dx+=(my_small_tri.get_edge()/2)*Math.sqrt(3);
			tx=dx+my_small_tri.get_edge()/2;
			ty-=h;
			tz-=h;
			if(ty-my_small_tri.get_edge()<0)
				break;
			if(2*my_cont_circle.get_radius()-dx<0)
				break;
			if(ty<=0)
				break;
		}


		temp2=my_cont_circle.get_radius()*2;
		i=(int)(temp2/my_small_tri.get_edge());
		tx=0;
		dx=0;
		h=(my_small_tri.get_edge()/2)*Math.sqrt(3);
		ty=my_cont_circle.get_radius();
		tz=0;

		while(true){
			temp2=(my_cont_circle.get_radius()*2-(dx*2));
			i=(int)(temp2/my_small_tri.get_edge());
			for(j=0; j<i; j++){

				
				if(i!=my_cont_circle.get_radius()*2/my_small_tri.get_edge()){
				temp[index]=new Triangle(t_edge,tx,tz,ty);
				size++;
				index++;
				}
				tx+=my_small_tri.get_edge();
			}
			
			dx+=(my_small_tri.get_edge()/2)*Math.sqrt(3);
			tx=dx;
			ty+=h;
			tz=ty-h;

			if(ty+my_small_tri.get_edge()>my_cont_circle.get_radius()*2)
				break;
			if(2*my_cont_circle.get_radius()-dx<0)
				break;
			if(ty>my_cont_circle.get_radius()*2)
				break;
		}
		temp2=my_cont_circle.get_radius()*2;
		i=(int)(temp2/my_small_tri.get_edge());
		tx=(my_small_tri.get_edge()/2);
		 dx=0;
		h=(my_small_tri.get_edge()/2)*Math.sqrt(3);
		ty=my_cont_circle.get_radius();
		tz=k-h;
		while(true){

			
			temp2=(my_cont_circle.get_radius()*2-(dx*2));
			i=(int)(temp2/my_small_tri.get_edge());
			if(i==my_cont_circle.get_radius()*2/my_small_tri.get_edge())
				i--;
			for(j=0; j<i; j++){
				max_triangle++;
				temp[index]=new Triangle(t_edge,tx,tz,ty);
				size++;
				index++;
				tx+=my_small_tri.get_edge();
			}
			dx+=(my_small_tri.get_edge()/2)*Math.sqrt(3);
			tx=dx;
			tx+=(my_small_tri.get_edge()/2);
			ty+=h;	
			tz=ty-h;
			if(ty+my_small_tri.get_edge()>my_cont_circle.get_radius()*2)
				break;
			if(2*my_cont_circle.get_radius()-dx<0)
				break;
			if(ty>my_cont_circle.get_radius()*2)
				break;
			}
			shapes=new Shape[size];
			for(i=0; i<size; i++){

				shapes[i]=temp[i];			
			} 

		}
		else if( cont_type=='T' && inner_type=='C' ){ 

			Shape temp[]= new Shape[max_size];
			h=(my_cont_tri.get_edge()/2)*Math.sqrt(3);
			radius=my_small_circle.get_radius();
			cx=my_cont_tri.get_edge()/2;
			cy=my_small_circle.get_radius()*2;
			row= ((h-(2*my_small_circle.get_radius()))/(my_small_circle.get_radius()*Math.sqrt(3)));
			if(row==1 && (cy + my_small_circle.get_radius()>h)){
				row--;
			}
			dx=cx;
			for(i=1; i<=row; i++){
		
				temp[index]=new Circle(radius,cx,cy); 
				size++;
				index++;
				cy+=my_small_circle.get_radius()*Math.sqrt(3);
				dx-=my_small_circle.get_radius();
				cx=dx;
				if(i==row && (cy+my_small_circle.get_radius())>h){
						row--;
						break;
				}
			
				for( j=1; j<=i; j++ ){
		
					temp[index]=new Circle(radius,cx,cy); 
					size++;
					index++;
					cx+=my_small_circle.get_radius()*2;
				}
			}
			shapes=new Shape[size];
			for(i=0; i<size; i++){

				shapes[i]=temp[i];			
			} 


		}
		else if( cont_type=='T' && inner_type=='R' ){

			Shape temp[]= new Shape[max_size];
			s_width=my_small_rect.get_width();
			s_height=my_small_rect.get_height();	
			temp2=my_cont_tri.get_edge();
			h=(my_cont_tri.get_edge()/2)*Math.sqrt(3);
			rx= my_small_rect.get_height()/Math.sqrt(3);
			ry=h-my_small_rect.get_height();
			dx=rx;
			while(true){
				temp2=(my_cont_tri.get_edge()-(dx*2));
				i=(int)(temp2/my_small_rect.get_width());
				for( j=0; j<i; j++){
					temp[index]=new Rectangle(s_width, s_height, rx,ry);
					size++;
					index++;
					rx+=my_small_rect.get_width();
				}
				dx+=my_small_rect.get_height()/Math.sqrt(3);
				rx=dx;
				ry=ry-my_small_rect.get_height();
				if(my_cont_tri.get_edge()-dx<0)
					break;
				if(ry<0)
					break;
			}
			shapes=new Shape[size];
			for(i=0; i<size; i++){

				shapes[i]=temp[i];			
			} 
		}
			
		else if( cont_type=='T' && inner_type=='T' ){
		
		Shape temp[]= new Shape[max_size];
		tx=0;
		ty= (my_cont_tri.get_edge()/2)*Math.sqrt(3);
		t_edge=my_small_tri.get_edge();
		temp2=my_cont_tri.get_edge();
		i=(int)(temp2/my_small_tri.get_edge());
		ty=(my_cont_tri.get_edge()/2)*Math.sqrt(3);
		h=(my_small_tri.get_edge()/2)*Math.sqrt(3);
		k=(my_cont_tri.get_edge()/2)*Math.sqrt(3);
		tz=k-h;
		while(true){

			for(j=0; j<i; j++){

				temp[index]=new Triangle(t_edge,tx,ty,tz);
				size++;
				index++;
				tx+=my_small_tri.get_edge();
			}
			dx+=my_small_tri.get_edge()/2;
			tx=dx;
			temp2=((i-1)*my_small_tri.get_edge());
			i=(int)(temp2/my_small_tri.get_edge());
			ty-=h;
			tz-=h;
			if(temp2<0 || tz<0)
				break;
		}
		tx=my_small_tri.get_edge()/2;
		 dx=0;
		temp2=my_cont_tri.get_edge();
		i=(int)(temp2/my_small_tri.get_edge());
		ty=(my_cont_tri.get_edge()/2)*Math.sqrt(3);
		h=(my_small_tri.get_edge()/2)*Math.sqrt(3);
		tz=k-h;
		while(true){
			
			for( j=0; j<i-1; j++){
				
				temp[index]=new Triangle(t_edge,tx,ty,tz);
				size++;
				index++;
				tx+=my_small_tri.get_edge();
				
			}
			dx+=my_small_tri.get_edge()/2;
			tx=dx+my_small_tri.get_edge()/2;
			temp2=((i-1)*my_small_tri.get_edge());
			i=(int)(temp2/my_small_tri.get_edge());
			ty-=h;
			tz-=h;
			if(temp2<0 || tz<0)
				break;
		}
		shapes=new Shape[size];
		for(i=0; i<size; i++){

			shapes[i]=temp[i];			
		} 
		
		}

	}
	/**
	 * Compare shapes respect to their areas, overrides from Comparable
	 * 
	 * @return 0,-1 or 1
	 */
	@Override public int compareTo(Shape that)throws RuntimeException{

		final int BEFORE = -1;
	    final int EQUAL = 0;
	    final int AFTER = 1;
	    if (!(that instanceof ComposedShape))
	    	throw new RuntimeException("Incompatible types");

		    if (this.area()==that.area())
		     return EQUAL;
		    else if (this.area() < that.area()) 
		    	return BEFORE;
		  	 else
		   		return AFTER;
	   
	}

}