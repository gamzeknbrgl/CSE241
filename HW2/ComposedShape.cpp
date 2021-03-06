#include "ComposedShape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
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

/*Draw the container & small shapes with using their draw functions 
* Using the vectors for small shapes*/

void ComposedShape::draw(ofstream &fout)
{
	if(cont_type=='R' && inner_type=='C'){
		fout.open("output.svg");
		fout<< "<svg version=\"1.1\" baseProfile=\"full\"  xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
		my_cont_rect.draw(fout);
		fout << " fill=\"red\" />  " <<endl;
		fout<< " <rect width=\"100%\" height=\"100%\" fill=\"red\" /> "<< endl;
		for(auto i=0; i<inner_circle.size(); i++){

			inner_circle[i].draw(fout);
			fout << " fill=\"green\" />  " <<endl;
			
		}
		fout << "</svg>" << endl;
		fout.close();
	}	
	else if(cont_type=='R' && inner_type=='R')
	{
		fout.open("output2.svg");
		fout<< "<svg version=\"1.1\" baseProfile=\"full\"  xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
		my_cont_rect.draw(fout);
		fout << " fill=\"red\" />  " <<endl;
		fout<< " <rect width=\"100%\" height=\"100%\" fill=\"red\" /> "<< endl;
		for(auto i=0; i<inner_rect.size(); i++){

			inner_rect[i].draw(fout);
			fout << " fill=\"green\" />  " <<endl;
		}
		fout << "</svg>" << endl;
		fout.close();
		
	}

	else if( cont_type=='R' && inner_type=='T')
	{
		
		fout.open("output3.svg");
		fout<< "<svg version=\"1.1\" baseProfile=\"full\"  xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
		my_cont_rect.draw(fout);
		fout << " fill=\"red\" />  " <<endl;
		fout<< " <rect width=\"100%\" height=\"100%\" fill=\"red\" /> "<< endl;
		for(auto i=0; i<inner_tri.size(); i++){

			inner_tri[i].draw(fout);
			fout << " fill=\"green\" />  " <<endl;
		}
		fout << "</svg>" << endl;
		fout.close();

	}
	else if(cont_type=='C' && inner_type=='C')
	{

		fout.open("output4.svg");
		fout<< "<svg version=\"1.1\" baseProfile=\"full\"  xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
		my_cont_circle.draw(fout);
		fout << " fill=\"red\" />  " <<endl;
		for(auto i=0; i<inner_circle.size(); i++){

			inner_circle[i].draw(fout);
			fout << " fill=\"green\" />  " <<endl;
		}
		fout << "</svg>" << endl;
		fout.close();
	}
	
	else if( cont_type=='C' && inner_type=='R' )
	{
		
		fout.open("output5.svg");
		fout<< "<svg version=\"1.1\" baseProfile=\"full\"  xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
		my_cont_circle.draw(fout);
		fout << " fill=\"red\" />  " <<endl;
		for(auto i=0; i<inner_rect.size(); i++){

			inner_rect[i].draw(fout);
			fout << " fill=\"green\" />  " <<endl;
		}
		fout << "</svg>" << endl;
		fout.close();
	}

	else if( cont_type=='C' && inner_type=='T' )
	{
		
		fout.open("output6.svg");
		fout<< "<svg version=\"1.1\" baseProfile=\"full\"  xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
		my_cont_circle.draw(fout);
		fout << " fill=\"red\" />  " <<endl;
		for(auto i=0; i<inner_tri.size(); i++){

			inner_tri[i].draw(fout);
			fout << " fill=\"green\" />  " <<endl;
		}
		fout << "</svg>" << endl;
		fout.close();
	}
	
	else if( cont_type=='T' && inner_type=='C' )
	{
		
		fout.open("output7.svg");
		fout<< "<svg version=\"1.1\" baseProfile=\"full\"  xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
		my_cont_tri.draw(fout);
		fout << " fill=\"red\" />  " <<endl;
		for(auto i=0; i<inner_circle.size(); i++){

			inner_circle[i].draw(fout);
			fout << " fill=\"green\" />  " <<endl;
		}
		fout << "</svg>" << endl;
		fout.close();
	}
	
	else if( cont_type=='T' && inner_type=='R' )
	{
		
		fout.open("output8.svg");
		fout<< "<svg version=\"1.1\" baseProfile=\"full\"  xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
		my_cont_tri.draw(fout);
		fout << " fill=\"red\" />  " <<endl;
		for(auto i=0; i<inner_rect.size(); i++){

			inner_rect[i].draw(fout);
			fout << " fill=\"green\" />  " <<endl;
		}
		fout << "</svg>" << endl;
		fout.close();
	}

	else if( cont_type=='T' && inner_type=='T' )
	{
		
		fout.open("output9.svg");
		fout<< "<svg version=\"1.1\" baseProfile=\"full\"  xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
		my_cont_tri.draw(fout);
		fout << " fill=\"red\" />  " <<endl;
		for(auto i=0; i<inner_tri.size(); i++){

			inner_tri[i].draw(fout);
			fout << " fill=\"green\" />  " <<endl;
		}
		fout << "</svg>" << endl;
		fout.close();
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

/*Doing the necessary calculations for
 the number of inner shapes and filling up the inner vectors */
void ComposedShape::optimalFit()
{
	
	int decl;
	double decl_d;
	decltype(decl) max_circle=0,radius, max_rect, a,b, x=0, y=0,s_width, s_height, t_edge, i, row,H;
	decltype(decl_d) max_triangle=0, tx=0, ty=(my_small_tri.get_edge()/2)*sqrt(3), tz=0;
	decltype(decl_d) dx, temp, ry, rx, cx=radius,cy=radius,h;

	if(cont_type=='R' && inner_type=='C'){
		
		radius=my_small_circle.get_radius();
		cx=my_small_circle.get_radius(),cy=my_small_circle.get_radius();
		while(1){
		Circle temp_circle(radius,cx,cy); 
		inner_circle.push_back(temp_circle); //inner_circle vector filling
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
			inner_rect.push_back(temp_rect); //inner_rect vector filling
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
			inner_rect.push_back(temp_rect);
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
		inner_tri.push_back(temp_tri); //inner_tri vector filling
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
		inner_tri.push_back(temp_tri);
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
			Circle temp2_circle(radius,cx,cy);
			inner_circle.push_back(temp2_circle); //inner_circle vector filling
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
			Circle temp2_circle(radius,cx,cy);
			inner_circle.push_back(temp2_circle);
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
			
			Rectangle temp_rect2(s_width, s_height, rx,ry);
			inner_rect.push_back(temp_rect2); //inner_rect vector filling
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
			inner_rect.push_back(temp_rect2); 
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
			Triangle temp_tri2(t_edge,tx,ty,tz);
			inner_tri.push_back(temp_tri2); //inner_tri vector filling
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
			Triangle temp_tri2(t_edge,tx,tz,ty);
			inner_tri.push_back(temp_tri2);
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
			Triangle temp_tri2(t_edge,tx,ty,tz);
			inner_tri.push_back(temp_tri2);
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
			Triangle temp_tri2(t_edge,tx,tz,ty);
			inner_tri.push_back(temp_tri2);
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
			inner_circle.push_back(temp_circle); //inner_circle vector filling
			cy+=my_small_circle.get_radius()*sqrt(3);
			dx-=my_small_circle.get_radius();
			cx=dx;
			if(i==row && (cy+my_small_circle.get_radius())>h){
					row--;
					break;
			}
		
			for(auto j=1; j<=i; j++ ){
				Circle temp_circle(radius,cx,cy);
				inner_circle.push_back(temp_circle);
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
			
				Rectangle temp_rect2(s_width, s_height, rx,ry);
				inner_rect.push_back(temp_rect2); //inner_rect vector filling
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
			inner_tri.push_back(temp_tri3); //inner_tri vector filling
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
			inner_tri.push_back(temp_tri3);
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
