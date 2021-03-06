#include "ComposedShape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"

namespace ComposedShapeNameS{

ComposedShape::ComposedShape()
{

	
}
/*Using that constructors for:
*Setting of container and small shape types with char variables
*and assigning it to ComposedShape class variables that i have created*/
ComposedShape::ComposedShape(Rectangle cont_rect, Circle small_circle){
	
	my_cont_rect=cont_rect;
	my_small_circle=small_circle;
	char cont_type='R';
	char inner_type='C';
	set_type(cont_type,inner_type);
	

}
ComposedShape::ComposedShape(Rectangle cont_rect, Rectangle small_rect){
	
	my_cont_rect=cont_rect;
	my_small_rect=small_rect;
	char cont_type='R';
	char inner_type='R';
	set_type(cont_type,inner_type);

}
ComposedShape::ComposedShape(Rectangle cont_rect, Triangle small_tri){
	
	my_cont_rect=cont_rect;
	my_small_tri=small_tri;
	char cont_type='R';
	char inner_type='T';
	set_type(cont_type,inner_type);

}
ComposedShape::ComposedShape(Triangle cont_tri, Circle small_circle){
	
	my_cont_tri=cont_tri;
	my_small_circle=small_circle;	
	char cont_type='T';
	char inner_type='C';
	set_type(cont_type,inner_type);
	

}
ComposedShape::ComposedShape(Triangle cont_tri, Rectangle small_rect){

	my_cont_tri=cont_tri;
	my_small_rect=small_rect;
	char cont_type='T';
	char inner_type='R';
	set_type(cont_type,inner_type);

}
ComposedShape::ComposedShape(Triangle cont_tri, Triangle small_tri){

	my_cont_tri=cont_tri;
	my_small_tri=small_tri;
	char cont_type='T';
	char inner_type='T';
	set_type(cont_type,inner_type);

}

ComposedShape::ComposedShape(Circle cont_circle, Circle small_circle){

	my_cont_circle=cont_circle;
	my_small_circle=small_circle;
	char cont_type='C';
	char inner_type='C';
	set_type(cont_type,inner_type);
	
}
ComposedShape::ComposedShape(Circle cont_circle, Rectangle small_rect){

	my_cont_circle=cont_circle;
	my_small_rect=small_rect;
	char cont_type='C';
	char inner_type='R';
	set_type(cont_type,inner_type);

}
ComposedShape::ComposedShape(Circle cont_circle, Triangle small_tri){

	my_cont_circle=cont_circle;
	my_small_tri=small_tri;
	char cont_type='C';
	char inner_type='T';
	set_type(cont_type,inner_type);
	
}
//Calculating perimeter of composedshape

double ComposedShape::perimeter() const{

	if(cont_type=='R'){

		return my_cont_rect.perimeter();

	}
	else if(cont_type=='C'){

		return my_cont_circle.perimeter();
	}

	else if(cont_type=='T'){

		return my_cont_tri.perimeter();
	}

}
// Calculating container shape's area
double ComposedShape::area() const{

	if(cont_type=='R'){

		return my_cont_rect.area();

	}
	else if(cont_type=='C'){

		return my_cont_circle.area();
	}

	else if(cont_type=='T'){

		return my_cont_tri.area();
	}

}
/*Draw the container & small shapes with using their draw functions 
* Using the vector<Shape*> shapes*/

void ComposedShape::draw(ofstream &fout)
{
	double empty_area, size;
	size=shapes.size();

	if(cont_type=='R' && inner_type=='C'){
		
		//container shape
		fout<< "<svg version=\"1.1\" baseProfile=\"full\"  xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
		my_cont_rect.draw(fout);
		fout<< " <rect width=\"100%\" height=\"100%\" fill=\"red\" /> "<< endl;

		for(auto i=0; i<shapes.size(); i++){

			fout<<*shapes[i]; // inner shapes
		
		}
		fout << "</svg>" << endl;
		cout<<"I can fit maximum "<<shapes.size()<<" circles in Rectangle"<<endl;
		
	}	
	else if(cont_type=='R' && inner_type=='R')
	{
		
		fout<< "<svg version=\"1.1\" baseProfile=\"full\"  xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
		my_cont_rect.draw(fout);
		fout<< " <rect width=\"100%\" height=\"100%\" fill=\"red\" /> "<< endl;
		for(auto i=0; i<shapes.size(); i++){
			
			fout<<*shapes[i]; //inner shapes
		}
		fout << "</svg>" << endl;
		cout<<"I can fit maximum "<<shapes.size()<<" rectangles in Rectangle"<<endl;
		
	}

	else if( cont_type=='R' && inner_type=='T')
	{
		
		//container shape
		fout<< "<svg version=\"1.1\" baseProfile=\"full\"  xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
		my_cont_rect.draw(fout);
		fout<< " <rect width=\"100%\" height=\"100%\" fill=\"red\" /> "<< endl;
		for(auto i=0; i<shapes.size(); i++){

	
			fout<<*shapes[i]; //inner shapes
			
		}
		fout << "</svg>" << endl;
		cout<<"I can fit maximum "<<shapes.size()<<" Triangle in Rectangle"<<endl;

	}
	else if(cont_type=='C' && inner_type=='C')
	{
		//container shape
		fout<< "<svg version=\"1.1\" baseProfile=\"full\"  xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
		fout << " <circle cx=\""<< my_cont_circle.get_x();
		fout << "\" cy=\"" <<my_cont_circle.get_y();
		fout <<"\" r=\""<< my_cont_circle.get_radius()<<"\"  ";
		fout<<" fill=\"red\" />"<<endl;
		for(auto i=0; i<shapes.size(); i++){

			fout<<*shapes[i]; // inner shapes 
		}
		fout << "</svg>" << endl;
		cout<<"I can fit maximum "<<shapes.size()<<" Circles in Circle"<<endl;
	}
	
	else if( cont_type=='C' && inner_type=='R' )
	{

		//container shape
		fout<< "<svg version=\"1.1\" baseProfile=\"full\"  xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
		fout << " <circle cx=\""<< my_cont_circle.get_x();
		fout << "\" cy=\"" <<my_cont_circle.get_y();
		fout <<"\" r=\""<< my_cont_circle.get_radius()<<"\"  ";
		fout<<" fill=\"red\" />"<<endl;

		for(auto i=0; i<shapes.size(); i++){

			fout<<*shapes[i]; //inner shapes
			
		}
		fout << "</svg>" << endl;
		cout<<"I can fit maximum "<<shapes.size()<<"rectangles in Circle"<<endl;
		
	}

	else if( cont_type=='C' && inner_type=='T' )
	{
		
		//container shape
		fout<< "<svg version=\"1.1\" baseProfile=\"full\"  xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
		fout << " <circle cx=\""<< my_cont_circle.get_x();
		fout << "\" cy=\"" <<my_cont_circle.get_y();
		fout <<"\" r=\""<< my_cont_circle.get_radius()<<"\"  ";
		fout<<" fill=\"red\" />"<<endl;

		for(auto i=0; i<shapes.size(); i++){

			fout<<*shapes[i]; //inner shapes	
		}
		fout << "</svg>" << endl;
		cout<<"I can fit maximum "<<shapes.size()<<"circles in Circle"<<endl;

	}
	
	else if( cont_type=='T' && inner_type=='C' )
	{
		
		//container shape
		fout<< "<svg version=\"1.1\" baseProfile=\"full\"  xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
		fout << "<polygon points=\"" << my_cont_tri.get_x() << " " << my_cont_tri.get_y() <<"," <<" ";
		fout << my_cont_tri.get_x()+ (my_cont_tri.get_edge()/2) << " " << my_cont_tri.get_z() << " " << "," << my_cont_tri.get_x()+my_cont_tri.get_edge()<< " "<<my_cont_tri.get_y() ;
		fout <<"\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\" ";
		fout<<" fill=\"red\" />"<<endl;
		for(auto i=0; i<shapes.size(); i++){

			fout<<*shapes[i]; // inner shapes
		
		}
		fout << "</svg>" << endl;
		cout<<"I can fit maximum "<<shapes.size()<<"circles in Triangle"<<endl;

	}
	
	else if( cont_type=='T' && inner_type=='R' )
	{
		
		
		//container shape
		fout<< "<svg version=\"1.1\" baseProfile=\"full\"  xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
		fout << "<polygon points=\"" << my_cont_tri.get_x() << " " << my_cont_tri.get_y() <<"," <<" ";
		fout << my_cont_tri.get_x()+ (my_cont_tri.get_edge()/2) << " " << my_cont_tri.get_z() << " " << "," << my_cont_tri.get_x()+my_cont_tri.get_edge()<< " "<<my_cont_tri.get_y() ;
		fout <<"\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\" ";
		fout<<" fill=\"red\" />"<<endl;
		for(auto i=0; i<shapes.size(); i++){

			fout<<*shapes[i];
		}
		fout << "</svg>" << endl;
		cout<<"I can fit maximum "<<shapes.size()<<"rectangles in Triangle"<<endl;

	}

	else if( cont_type=='T' && inner_type=='T' )
	{
		//container shape
		fout<< "<svg version=\"1.1\" baseProfile=\"full\"  xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
		fout << "<polygon points=\"" << my_cont_tri.get_x() << " " << my_cont_tri.get_y() <<"," <<" ";
		fout << my_cont_tri.get_x()+ (my_cont_tri.get_edge()/2) << " " << my_cont_tri.get_z() << " " << "," << my_cont_tri.get_x()+my_cont_tri.get_edge()<< " "<<my_cont_tri.get_y()  ;
		fout <<"\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\" ";
		fout<<" fill=\"red\" />"<<endl;
		for(auto i=0; i<shapes.size(); i++){

			fout<<*shapes[i];
	
		}
		fout << "</svg>" << endl;
		cout<<"I can fit maximum "<<shapes.size()<<" triangles in Triangle"<<endl;

	}

}

/*Setting of container and small shape types */
void ComposedShape::set_type(char a, char b)
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


void ComposedShape::optimalFit()
{
	
	int decl;
	double decl_d;
	decltype(decl) max_circle=0,radius, max_rect, a,b, x=0, y=0,s_width, s_height, t_edge, i, row,H;
	decltype(decl_d) max_triangle=0, tx=0,ty=(my_small_tri.get_edge()/2)*sqrt(3), tz=0;
	decltype(decl_d) dx, temp, ry, rx, cx=radius,cy=radius,h;

	if(cont_type=='R' && inner_type=='C'){
		
		radius=my_small_circle.get_radius();
		cx=my_small_circle.get_radius(),cy=my_small_circle.get_radius();
		while(1){

		Circle temp_circle(radius,cx,cy); 
		Shape* shape= new Circle(temp_circle);
		shapes.push_back(shape);
		cx+=my_small_circle.get_radius()*2;
		if(cx+my_small_circle.get_radius()>my_cont_rect.get_width()){

			cx=my_small_circle.get_radius();
			cy+=2*my_small_circle.get_radius();
		
		}
		if(cy+my_small_circle.get_radius()>my_cont_rect.get_height())
			break;
		
		}
	}


	else if(cont_type=='R' && inner_type=='R'){

		s_width=my_small_rect.get_width();
		s_height=my_small_rect.get_height();
		a= (my_cont_rect.get_width()/my_small_rect.get_width())* (my_cont_rect.get_height()/my_small_rect.get_height());
		b=(my_cont_rect.get_width()/my_small_rect.get_height())*(my_cont_rect.get_height()/my_small_rect.get_width()); 
		if(a>b){ //Horizontal
		max_rect=a;
		for(auto i=0; i<max_rect; i++){

			Rectangle temp_rect(s_width, s_height, x,y);
			Shape* shape= new Rectangle(temp_rect);
			shapes.push_back(shape);
			x=x+(my_small_rect.get_width());
			if(x+(my_small_rect.get_width())>my_cont_rect.get_width()){
			x=0;
			y=y+my_small_rect.get_height();
			}
		}
		}
		else{ //Vertical
		max_rect=b;
		for(auto i=0; i<max_rect; i++){
	
			Rectangle temp_rect(s_height, s_width, x,y);
			Shape* shape= new Rectangle(temp_rect);
			shapes.push_back(shape);
			x=x+(my_small_rect.get_height());
			if(x+(my_small_rect.get_height())>my_cont_rect.get_width()){
				x=0;
				y=y+my_small_rect.get_width();
			}
		}
		}
	}
	
	
	else if( cont_type=='R' && inner_type=='T' ){
	
		while(my_small_tri.get_edge()<my_cont_rect.get_width() && my_small_tri.get_edge()<my_cont_rect.get_height()){
		t_edge=my_small_tri.get_edge();
		Triangle temp_tri(t_edge,tx,ty,tz);
		Shape* shape= new Triangle(temp_tri);
		shapes.push_back(shape);

		tx+=my_small_tri.get_edge();
		if(tx+my_small_tri.get_edge()>my_cont_rect.get_width() ){
			tx=0;
			ty+=(my_small_tri.get_edge()/2)*sqrt(3);
			tz+=(my_small_tri.get_edge()/2)*sqrt(3);
		}
		if(ty>my_cont_rect.get_height())
			break;
		}
		tx=my_small_tri.get_edge()/2, ty=0, tz=(my_small_tri.get_edge()/2)*sqrt(3);
		//inverted triangles
		while(my_small_tri.get_edge()<my_cont_rect.get_width()&& my_small_tri.get_edge()<my_cont_rect.get_height()){ 
			Triangle temp_tri(t_edge,tx,ty,tz);
			Shape* shape= new Triangle(temp_tri);
			shapes.push_back(shape);
			tx+=my_small_tri.get_edge();
			if(tx+my_small_tri.get_edge() >my_cont_rect.get_width()){
				tx=my_small_tri.get_edge()/2;
				ty+=(my_small_tri.get_edge()/2)*sqrt(3);
				tz+=(my_small_tri.get_edge()/2)*sqrt(3);
			}
			if(tz>my_cont_rect.get_height())
				break;
		}
	}
	
	
	else if( cont_type=='C' && inner_type=='C' ){
		
		radius=my_small_circle.get_radius();
		cx=my_small_circle.get_radius(), cy=my_cont_circle.get_radius();
		dx=0;
		while(1){
		temp=(my_cont_circle.get_radius()*2-(dx*2));
		i=(temp/(my_small_circle.get_radius()*2));
		if(i!=my_cont_circle.get_radius()/my_small_circle.get_radius())
			i++;
		for(auto j=0; j<i; j++){

			Circle temp_circle(radius,cx,cy); 
			Shape* shape= new Circle(temp_circle);
			shapes.push_back(shape);
			cx+=my_small_circle.get_radius()*2;
		}
		dx+=(my_small_circle.get_radius()*sqrt(3));
		cx=dx;
		cy-=(my_small_circle.get_radius()*2);
		if(cy-my_small_circle.get_radius()<0)
			break;
		if(2*my_cont_circle.get_radius()-dx<0)
			break;
		if(cy<=0)
			break;
		}
		cx=my_small_circle.get_radius(), cy=my_cont_circle.get_radius();
		dx=0;
		while(1){
		temp=(my_cont_circle.get_radius()*2-(dx*2));
		i=(temp/(my_small_circle.get_radius()*2));
		if(i!=my_cont_circle.get_radius()/my_small_circle.get_radius())
			i++;
		for(auto j=0; j<i; j++){
	
			Circle temp_circle2(radius,cx,cy); 
			Shape* shape= new Circle(temp_circle2);
			shapes.push_back(shape);
			cx+=my_small_circle.get_radius()*2;
		}
		dx+=(my_small_circle.get_radius()*sqrt(3));
		cx=dx;
		cy+=(my_small_circle.get_radius()*2);
		if(cy+my_small_circle.get_radius()>my_cont_circle.get_radius()*2)
			break;
		if(2*my_cont_circle.get_radius()-dx<0)
			break;
		if(cy>my_cont_circle.get_radius()*2)
			break;
		}
	}

	
	else if( cont_type=='C' && inner_type=='R' ){

		cx=my_cont_circle.get_radius(), cy=my_cont_circle.get_radius();
		dx=my_small_rect.get_width()/4;
		rx=my_small_rect.get_width()/2 ,ry=my_cont_circle.get_radius();
		s_width=my_small_rect.get_width();
		s_height=my_small_rect.get_height();


		while(1){
		temp=(my_cont_circle.get_radius()*2-(dx*2));
		i=(temp/(my_small_rect.get_width()));
		for(auto j=0; j<i; j++){
			

			Rectangle temp_rect(s_width,s_height,rx,ry);
			Shape* shape= new Rectangle(temp_rect);
			shapes.push_back(shape);

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
		rx=my_small_rect.get_width()/2 ,ry=my_cont_circle.get_radius(), dx=my_small_rect.get_width()/4;
		while(1){
		temp=((my_cont_circle.get_radius()*2)-(dx*2));
		i=(temp/(my_small_rect.get_width()));
		for(auto j=0; j<i; j++){

			Rectangle temp_rect2(s_width, s_height, rx,ry);
			Shape* shape= new Rectangle(temp_rect2);
			shapes.push_back(shape);
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
	}
	
	else if( cont_type=='C' && inner_type=='T' ){

	h=((my_small_tri.get_edge()/2)*sqrt(3));
	H=my_cont_circle.get_radius();
	temp=my_cont_circle.get_radius()*2,cx=my_cont_circle.get_radius(), cy=my_cont_circle.get_radius();
	 ty=my_cont_circle.get_radius(), tx=0, tz= ty-h;
	t_edge=my_small_tri.get_edge();
	tz=H-h;
	while(1){
		temp=(my_cont_circle.get_radius()*2-(dx*2));
		i=(temp/my_small_tri.get_edge());
		for(auto j=0; j<i; j++){
			Triangle temp_tri2(t_edge,tx,tz,ty);
			Shape* shape= new Triangle(temp_tri2);
			shapes.push_back(shape);
			tx+=my_small_tri.get_edge();
		}
		dx+=(my_small_tri.get_edge()/2)*sqrt(3);
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
	temp=radius*2;
	i=temp/my_small_tri.get_edge();
	tx=my_small_tri.get_edge()/2, dx=0;
	h=(my_small_tri.get_edge()/2)*sqrt(3);
	ty=my_cont_circle.get_radius();
	tz=H-h;
	while(1){
		temp=(my_cont_circle.get_radius()*2-(dx*2));
		i=(temp/my_small_tri.get_edge());
		for(auto j=0; j<i-1; j++){
			if(i!=my_cont_circle.get_radius()*2/my_small_tri.get_edge())
			max_triangle++;	
			Triangle temp_tri2(t_edge,tx,ty,tz);
			Shape* shape= new Triangle(temp_tri2);
			shapes.push_back(shape);
			tx+=my_small_tri.get_edge();
		}
		dx+=(my_small_tri.get_edge()/2)*sqrt(3);
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


	temp=my_cont_circle.get_radius()*2;
	i=temp/my_small_tri.get_edge();
	tx=0, dx=0;
	h=(my_small_tri.get_edge()/2)*sqrt(3);
	ty=my_cont_circle.get_radius();
	tz=0;

	while(1){
		temp=(my_cont_circle.get_radius()*2-(dx*2));
		i=(temp/my_small_tri.get_edge());
		for(auto j=0; j<i; j++){

			
			if(i!=my_cont_circle.get_radius()*2/my_small_tri.get_edge()){
			Triangle temp_tri2(t_edge,tx,tz,ty);
			Shape* shape= new Triangle(temp_tri2);
			shapes.push_back(shape);
			}
			tx+=my_small_tri.get_edge();
		}
		
		dx+=(my_small_tri.get_edge()/2)*sqrt(3);
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
	temp=my_cont_circle.get_radius()*2;
	i=temp/my_small_tri.get_edge();
	tx=(my_small_tri.get_edge()/2), dx=0;
	h=(my_small_tri.get_edge()/2)*sqrt(3);
	ty=my_cont_circle.get_radius();
	tz=H-h;
	while(1){

		
		temp=(my_cont_circle.get_radius()*2-(dx*2));
		i=(temp/my_small_tri.get_edge());
		if(i==my_cont_circle.get_radius()*2/my_small_tri.get_edge())
			i--;
		for(auto j=0; j<i; j++){
			max_triangle++;
			Triangle temp_tri2(t_edge,tx,ty,tz);
			Shape* shape= new Triangle(temp_tri2);
			shapes.push_back(shape);
			tx+=my_small_tri.get_edge();
		}
		dx+=(my_small_tri.get_edge()/2)*sqrt(3);
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

	}

	else if( cont_type=='T' && inner_type=='C' ){ 

		h=(my_cont_tri.get_edge()/2)*sqrt(3);
		radius=my_small_circle.get_radius();
		cx=my_cont_tri.get_edge()/2,cy=my_small_circle.get_radius()*2;
		row= ((h-(2*my_small_circle.get_radius()))/(my_small_circle.get_radius()*sqrt(3)));
		if(row==1 && (cy + my_small_circle.get_radius()>h)){
			row--;
		}
		dx=cx;
		for(i=1; i<=row; i++){
	
			Circle temp_circle(radius,cx,cy); 
			Shape* shape= new Circle(temp_circle);
			shapes.push_back(shape);

			cy+=my_small_circle.get_radius()*sqrt(3);
			dx-=my_small_circle.get_radius();
			cx=dx;
			if(i==row && (cy+my_small_circle.get_radius())>h){
					row--;
					break;
			}
		
			for(auto j=1; j<=i; j++ ){
				Circle temp_circle(radius,cx,cy); 
				Shape* shape= new Circle(temp_circle);
				shapes.push_back(shape);
				cx+=my_small_circle.get_radius()*2;
			}
		}

	}
	

	else if( cont_type=='T' && inner_type=='R' ){

		s_width=my_small_rect.get_width();
		s_height=my_small_rect.get_height();	
		temp=my_cont_tri.get_edge();
		h=(my_cont_tri.get_edge()/2)*sqrt(3);
		rx= my_small_rect.get_height()/sqrt(3), ry=h-my_small_rect.get_height();
		dx=rx;
		while(1){
			temp=(my_cont_tri.get_edge()-(dx*2));
			i=(temp/my_small_rect.get_width());
			for(auto j=0; j<i; j++){
			Rectangle temp_rect(s_width, s_height, rx,ry);
			Shape* shape= new Rectangle(temp_rect);
			shapes.push_back(shape);


				rx+=my_small_rect.get_width();
			}
			dx+=my_small_rect.get_height()/sqrt(3);
			rx=dx;
			ry=ry-my_small_rect.get_height();
			if(my_cont_tri.get_edge()-dx<0)
				break;
			if(ry<0)
				break;
		}

	}
	
	else if( cont_type=='T' && inner_type=='T' ){
	
	tx=0,ty= (my_cont_tri.get_edge()/2)*sqrt(3);
	t_edge=my_small_tri.get_edge();
	temp=my_cont_tri.get_edge();
	i=temp/my_small_tri.get_edge();
	ty=(my_cont_tri.get_edge()/2)*sqrt(3);
	h=(my_small_tri.get_edge()/2)*sqrt(3);
	H=(my_cont_tri.get_edge()/2)*sqrt(3);
	tz=H-h;
	while(1){

		for(auto j=0; j<i; j++){
			Triangle temp_tri3(t_edge,tx,ty,tz);
			Shape* shape= new Triangle(temp_tri3);
			shapes.push_back(shape);

			tx+=my_small_tri.get_edge();
		}
		dx+=my_small_tri.get_edge()/2;
		tx=dx;
		temp=((i-1)*my_small_tri.get_edge());
		i=temp/my_small_tri.get_edge();
		ty-=h;
		tz-=h;
		if(temp<0 || tz<0)
			break;
	}
	tx=my_small_tri.get_edge()/2, dx=0;
	temp=my_cont_tri.get_edge();
	i=temp/my_small_tri.get_edge();
	ty=(my_cont_tri.get_edge()/2)*sqrt(3);
	h=(my_small_tri.get_edge()/2)*sqrt(3);
	tz=H-h;
	while(1){
		
		for(auto j=0; j<i-1; j++){
			
			Triangle temp_tri3(t_edge,tx,tz,ty);
			Shape* shape= new Triangle(temp_tri3);
			shapes.push_back(shape);
			tx+=my_small_tri.get_edge();
			
		}
		dx+=my_small_tri.get_edge()/2;
		tx=dx+my_small_tri.get_edge()/2;
		temp=((i-1)*my_small_tri.get_edge());
		i=temp/my_small_tri.get_edge();
		ty-=h;
		tz-=h;
		if(temp<0 || tz<0)
			break;
	}

	
	}
		
}
// << operator overloading for ComposedShape (i use it like cout for shape informations)
ostream& operator <<(ostream& outputStream, const ComposedShape& my_shape){



		if(my_shape.cont_type=='R'){
			cout<<"Container shape is Rectangle:"<<endl<<"Width of Rectangle: "<<my_shape.my_cont_rect.get_width()<<endl;
			cout<<" Height of Rectangle: "<<my_shape.my_cont_rect.get_height()<<endl;
		}
		else if(my_shape.cont_type=='C'){
			cout<<"Container shape is Circle:"<<endl<<"Radius of Circle: "<<my_shape.my_cont_circle.get_radius()<<endl;
		}
		else if(my_shape.cont_type=='T'){
			cout<<"Container shape is Triangle:"<<endl<<"Edge of Triangle: "<<my_shape.my_cont_tri.get_edge()<<endl;
		}
		if(my_shape.inner_type=='R'){
			cout<<"Inner shape is Rectangle:"<<endl<<"Width of Rectangle: "<<my_shape.my_small_rect.get_width()<<endl;
			cout<<" Height of Rectangle: "<<my_shape.my_small_rect.get_height()<<endl;

		}
		else if(my_shape.inner_type=='C'){
			cout<<"Inner shape is Circle:"<<endl<<"Radius of Circle: "<<my_shape.my_small_circle.get_radius()<<endl;
		}
		else if(my_shape.inner_type=='T'){
			cout<<"Inner shape is Triangle:"<<endl<<"Edge of Triangle: "<<my_shape.my_small_tri.get_edge()<<endl;
		}
}

//destructor
ComposedShape::~ComposedShape(){

	for(auto ptr : shapes){

		delete ptr;
	}
}
// copy constructor
ComposedShape::ComposedShape(const ComposedShape &my_cshape){

		if(my_cshape.cont_type=='R' && my_cshape.inner_type=='R'){
				my_cont_rect=my_cshape.my_cont_rect;
				my_small_rect=my_cshape.my_small_rect;
				 cont_type='R';
				inner_type='R';	
		}
		else if(my_cshape.cont_type=='R' && my_cshape.inner_type=='C'){
				my_cont_rect=my_cshape.my_cont_rect;
				my_small_circle=my_cshape.my_small_circle;
				 cont_type='R';
				inner_type='C';	
		}
		else if(my_cshape.cont_type=='R' && my_cshape.inner_type=='T'){
				my_cont_rect=my_cshape.my_cont_rect;
				my_small_tri=my_cshape.my_small_tri;
				 cont_type='R';
				inner_type='T';	
		}
		else if(my_cshape.cont_type=='C' && my_cshape.inner_type=='C'){
				my_cont_circle=my_cshape.my_cont_circle;
				my_small_circle=my_cshape.my_small_circle;
				 cont_type='C';
				inner_type='C';	
		}
		else if(my_cshape.cont_type=='C' && my_cshape.inner_type=='T'){

				my_cont_circle=my_cshape.my_cont_circle;
				my_small_tri=my_cshape.my_small_tri;
				 cont_type='C';
				inner_type='T';	
		}
		else if(my_cshape.cont_type=='C' && my_cshape.inner_type=='R'){
				my_cont_circle=my_cshape.my_cont_circle;
				my_small_rect=my_cshape.my_small_rect;
				 cont_type='C';
				inner_type='R';	
		}
		else if(my_cshape.cont_type=='T' && my_cshape.inner_type=='C'){
				my_cont_tri=my_cshape.my_cont_tri;
				my_small_circle=my_cshape.my_small_circle;
				 cont_type='T';
				inner_type='C';	
		}
		else if(my_cshape.cont_type=='T' && my_cshape.inner_type=='T'){

				my_cont_tri=my_cshape.my_cont_tri;
				my_small_tri=my_cshape.my_small_tri;
				 cont_type='T';
				inner_type='T';	
		}
		else if(my_cshape.cont_type=='T' && my_cshape.inner_type=='R'){
				my_cont_tri=my_cshape.my_cont_tri;
				my_small_rect=my_cshape.my_small_rect;
				 cont_type='T';
				inner_type='R';	
		}


		shapes=my_cshape.shapes;
		
}
// = operator
ComposedShape& ComposedShape::operator=(const ComposedShape& my_cshape){

		for(auto ptr : shapes){

				delete ptr;
		}
		if(my_cshape.cont_type=='R' && my_cshape.inner_type=='R'){

				my_cont_rect=my_cshape.my_cont_rect;
				my_small_rect=my_cshape.my_small_rect;
				 cont_type='R';
				inner_type='R';
		}
		else if(my_cshape.cont_type=='R' && my_cshape.inner_type=='C'){
				my_cont_rect=my_cshape.my_cont_rect;
				my_small_circle=my_cshape.my_small_circle;
				 cont_type='R';
				inner_type='C';	
		}
		else if(my_cshape.cont_type=='R' && my_cshape.inner_type=='T'){
				my_cont_rect=my_cshape.my_cont_rect;
				my_small_tri=my_cshape.my_small_tri;
				 cont_type='R';
				inner_type='T';	
		}
		else if(my_cshape.cont_type=='C' && my_cshape.inner_type=='C'){
				my_cont_circle=my_cshape.my_cont_circle;
				my_small_circle=my_cshape.my_small_circle;
				 cont_type='C';
				inner_type='C';	
		}
		else if(my_cshape.cont_type=='C' && my_cshape.inner_type=='T'){

				my_cont_circle=my_cshape.my_cont_circle;
				my_small_tri=my_cshape.my_small_tri;
				 cont_type='C';
				inner_type='T';	
		}
		else if(my_cshape.cont_type=='C' && my_cshape.inner_type=='R'){
				my_cont_circle=my_cshape.my_cont_circle;
				my_small_rect=my_cshape.my_small_rect;
				 cont_type='C';
				inner_type='R';	
		}
		else if(my_cshape.cont_type=='T' && my_cshape.inner_type=='C'){
				my_cont_tri=my_cshape.my_cont_tri;
				my_small_circle=my_cshape.my_small_circle;
				 cont_type='T';
				inner_type='C';	
		}
		else if(my_cshape.cont_type=='T' && my_cshape.inner_type=='T'){

				my_cont_tri=my_cshape.my_cont_tri;
				my_small_tri=my_cshape.my_small_tri;
				 cont_type='T';
				inner_type='T';	
		}
		else if(my_cshape.cont_type=='T' && my_cshape.inner_type=='R'){
				my_cont_tri=my_cshape.my_cont_tri;
				my_small_rect=my_cshape.my_small_rect;
				 cont_type='T';
				inner_type='R';	
		}
		shapes=my_cshape.shapes;
		
		return *this;

}
//prefix increment
ComposedShape& ComposedShape::operator++(){ 

	//It's empty but i wrote it just because make composed shape a concrete class

}
//prefix decrement
ComposedShape& ComposedShape::operator--(){

	//It's empty but i wrote it just because make composed shape a concrete class

}
ComposedShape& ComposedShape::operator--(int ignoreMe){

	//It's empty but i wrote it just because make composed shape a concrete class
}
ComposedShape& ComposedShape::operator++(int ignoreMe){

	//It's empty but i wrote it just because make composed shape a concrete class
}

}
