#include "source.h"
#include <iostream>
#include <fstream>
#include <cmath>
#define PI 3.14
enum class shapes {rectangle, circle, triangle};
using namespace std;

/* circle_in_rectangle function: Starting at the top of the rectangle until the
 * last line without crossing the limit maximum circle will be drawn
 * and the number of the circle will be counted in max_circle variable.
 * */
void circle_in_rectangle(int height, int width, int radius){

	double rect_area,max_circle=0, i, j,x=0, y=0, cx=radius ,cy =radius;
	double circle_area, empty_area;
	ofstream fout;
	fout.open("output.svg");
	rect_area=height*width;
	circle_area=PI*radius*radius;
	fout<< "<svg version=\"1.1\" baseProfile=\"full\" width=\"" <<width<< "\" height=\"" <<height<<"\" xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
	fout<< " <rect width=\"100%\" height=\"100%\" fill=\"red\" /> "<< endl;
	while(radius<width && radius<height && radius*2<=height && radius*2<=width){
		max_circle++;
		fout<< " <circle cx=\""<<cx<<"\" cy=\""<<cy<<"\" r=\""<<radius<<"\" fill=\"green\" /> "<< endl;
		cx+=radius*2;
		if(cx+radius>width){
			cx=radius;
			cy+=2*radius;
		}
		if(cy+radius>height)
			break;
	}
	fout << "</svg>" << endl;
	fout.close();
	empty_area=(double)rect_area- (max_circle*circle_area);
	cout<<"I can fit at most " <<max_circle<< " small shapes into the main container";
	cout<< " The empty area (red) in container is "<<empty_area<<endl;
}
/* rectangle_in_rectangle function: For the maximum number of rectangle without crossing
 * the limit of rectangle the horizontal and vertical calculation will occur separately
 * and then we will find the maximum rectangle.
 */
void rectangle_in_rectangle(int height,int width,int small_height,int small_width){

	int rect_area, max_rect, a,b,c,d, x=0, y=0,i;
	double empty_area;
	ofstream fout;
	fout.open("output.svg");
	fout<< "<svg version=\"1.1\" baseProfile=\"full\" width=\"" <<width<< "\" height=\"" <<height<<"\" xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
	fout<< " <rect width=\"100%\" height=\"100%\" fill=\"red\" /> "<< endl;
	a= (width/small_width)* (height/small_height);//horizontal rectangles
	b=(width/small_height)*(height/small_width); //vertical rectangles
	rect_area=height*width;
	if(a>b){
		cout<<"Horizontal";
		max_rect=a;
		fout<< " <rect x=\""<<x<<"\" y=\""<<y<<"\" width=\""<<small_width<<"\" height=\""<<small_height;
		fout<<"\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\"" " fill=\"green\" /> "<< endl;
		for(i=1; i<max_rect; i++){
			x=x+(small_width);
			if(x+(small_width)>width){
			x=0;
			y=y+small_height;
			fout<< " <rect x=\""<<x<<"\" y=\""<<y<<"\" width=\""<<small_width<<"\" height=\""<<small_height;
			fout<<"\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\"" " fill=\"green\" /> "<< endl;
		}
		else{
			fout<< " <rect x=\""<<x<<"\" y=\""<<y<<"\" width=\""<<small_width<<"\" height=\""<<small_height;
			fout<<"\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\"" " fill=\"green\" /> "<< endl;
			}
		}
	}
	else{
		cout<<"Vertical";
		max_rect=b;
		fout<< " <rect x=\""<<x<<"\" y=\""<<y<<"\" width=\""<<small_height<<"\" height=\""<<small_width;
		fout<<"\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\"" " fill=\"green\" /> "<< endl;
		for(i=1; i<max_rect; i++){
			x=x+(small_height);
			if(x+(small_height)>width){
				x=0;
				y=y+small_width;
				fout<< " <rect x=\""<<x<<"\" y=\""<<y<<"\" width=\""<<small_height<<"\" height=\""<<small_width;
				fout<<"\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\"" " fill=\"green\" /> "<< endl;
			}
			else{
				fout<< " <rect x=\""<<x<<"\" y=\""<<y<<"\" width=\""<<small_height<<"\" height=\""<<small_width;
				fout<<"\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\"" " fill=\"green\" /> "<< endl;
			}
		}
	}
	fout << "</svg>" << endl;
	fout.close();
	empty_area=(double)rect_area-((max_rect)*small_height*small_width);
	cout<<"I can fit at most " <<max_rect<< " small shapes into the main container";
	cout<< " The empty area (red) in container is "<<empty_area<<endl;
}
/* triangle_in_rectangle function: For the maximum number of triangle without crossing
 * the limit of the rectangle calculation will occur by using inverted & normal triangles*/
void triangle_in_rectangle(int height,int width,int edge){

	double max_triangle=0, x=0, y=(edge/2)*sqrt(3), z=0;
	double rect_area,tri_area,empty_area;
	ofstream fout;
	fout.open("output.svg");
	tri_area=(edge*edge*sqrt(3))/4;
	rect_area=height*width;
	fout<< "<svg version=\"1.1\" baseProfile=\"full\" width=\"" <<width<< "\" height=\"" <<height<<"\" xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
	fout<< " <rect width=\"100%\" height=\"100%\" fill=\"red\" /> "<< endl;
	while(edge<width && edge<height){
		max_triangle++;
		fout<<"<polygon points=\""<<x<<" "<< y<<","<< " "<<x+edge/2<<" "<< z<<" "<<","<< x+edge<<" "<< y<<"\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\" fill=\"green\"/>"<<endl;
		x+=edge;
		if(x+edge >width){
			x=0;
			y+=(edge/2)*sqrt(3);
			z+=(edge/2)*sqrt(3);
		}
		if(y>height)
			break;
	}
	x=edge/2, y=0, z=(edge/2)*sqrt(3);
	while(edge<width&& edge<height){ //inverted triangles
		max_triangle++;
		fout<<"<polygon points=\""<<x<<" "<< y<<","<< " "<<x+edge/2<<" "<< z<<" "<<","<< x+edge<<" "<< y<<"\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\" fill=\"green\"/>"<<endl;
			x+=edge;
			if(x+edge >width){
				x=edge/2;
				y+=(edge/2)*sqrt(3);
				z+=(edge/2)*sqrt(3);
			}
			if(z>height)
				break;
		}
	fout << "</svg>" << endl;
	fout.close();
	cout<<"I can fit at most " <<max_triangle<< " small shapes into the main container";
	empty_area= rect_area-(tri_area*max_triangle);
	cout<< " The empty area (red) in container is "<<empty_area<<endl;
}
/* circle in circle function: Maximum number of circle to fit will be calculated by starting at the center of circle.
 * (For some numbers at the top of the circle will be drawing circles crossing the line, I can't fix it.)
 */
void circle_in_circle(int radius, int small_radius){

	double cx,cy, temp, dx, empty_area;
	int i,j, max_circle=0;
	ofstream fout;
	fout.open("output.svg");
	cx=radius, cy=radius;
	fout<< "<svg version=\"1.1\" baseProfile=\"full\"  xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
	fout<< " <circle cx=\""<<cx<<"\" cy=\""<<cy<<"\" r=\""<<radius<<"\" fill=\"red\" /> "<< endl;
	cx=small_radius, cy=radius;
	dx=0;
	while(1){
		temp=(radius*2-(dx*2));
		i=(temp/(small_radius*2));
		if(i!=radius/small_radius)
			i++;
		for(j=0; j<i; j++){
			max_circle++;
			fout<< " <circle cx=\""<<cx<<"\" cy=\""<<cy<<"\" r=\""<<small_radius<<"\" fill=\"green\" /> "<< endl;
			fout<<"\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\"" " fill=\"green\" /> "<< endl;
			cx+=small_radius*2;
		}
		dx+=(small_radius*sqrt(3));
		cx=dx;
		cy-=(small_radius*2);
		if(cy-small_radius<0)
			break;
		if(2*radius-dx<0)
			break;
		if(cy<=0)
			break;
	}
	cx=small_radius, cy=radius;
	dx=0;
	while(1){
		temp=(radius*2-(dx*2));
		i=(temp/(small_radius*2));
		if(i!=radius/small_radius)
			i++;
		for(j=0; j<i; j++){
			max_circle++;
			fout<< " <circle cx=\""<<cx<<"\" cy=\""<<cy<<"\" r=\""<<small_radius<<"\" fill=\"green\" /> "<< endl;
			fout<<"\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\"" " fill=\"green\" /> "<< endl;
			cx+=small_radius*2;
		}
		dx+=(small_radius*sqrt(3));
		cx=dx;
		cy+=(small_radius*2);
		if(cy+small_radius>radius*2)
			break;
		if(2*radius-dx<0)
			break;
		if(cy>radius*2)
			break;
	}
	max_circle-=radius/small_radius;
	fout << "</svg>" << endl;
	fout.close();
	empty_area=(PI*radius*radius)-(PI*small_radius*small_radius*max_circle);
	cout<<"I can fit at most " <<max_circle<< " small shapes into the main container";
	cout<< " The empty area (red) in container is "<<empty_area<<endl;
}
/*rectangle_in_circle function: Maximum rectangle to fit starting from the center of the circle
 * will be calculated. (For some numbers the circle crosses its limit.)
 */
void rectangle_in_circle(int radius, int height, int width){

	double cx,cy, temp, dx, rx=width/2 ,ry=radius, empty_area;
	int i,j, max_rectangle=0;
	ofstream fout;
	cx=radius, cy=radius;
	fout.open("output.svg");
	fout<< "<svg version=\"1.1\" baseProfile=\"full\"  xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
	fout<< " <circle cx=\""<<cx<<"\" cy=\""<<cy<<"\" r=\""<<radius<<"\" fill=\"red\" /> "<< endl;
	dx=width/4;
	while(1){
		temp=(radius*2-(dx*2));
		i=(temp/(width));
		for(j=0; j<i; j++){
			fout<< " <rect x=\""<<rx<<"\" y=\""<<ry<<"\" width=\""<<width<<"\" height=\""<<height;
			fout<<"\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\"" " fill=\"green\" /> "<< endl;
			max_rectangle++;
			rx+=width;
		}
		dx+=width/4;
		rx=dx;
		ry-=height;
		if(ry-height<0)
			break;
		if(ry<=0)
			break;
	}
	rx=width/2 ,ry=radius, dx=width/4;
	while(1){
		temp=(radius*2-(dx*2));
		i=(temp/(width));
		for(j=0; j<i; j++){

			fout<< " <rect x=\""<<rx<<"\" y=\""<<ry<<"\" width=\""<<width<<"\" height=\""<<height;
			fout<<"\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\"" " fill=\"green\" /> "<< endl;
			rx+=width;
			if(ry!=radius)
			max_rectangle++;
		}
		dx+=width/4;
		rx=dx;
		ry+=height;
		if((rx*2)>(radius*2))
			break;
		if(ry+(height*2)>radius*2)
			break;
		if(ry+height>radius*2)
			break;
	}
	fout << "</svg>" << endl;
	fout.close();
	empty_area= (PI*radius*radius)-(max_rectangle*width*height);
	cout<<"I can fit at most " <<max_rectangle<< " small shapes into the main container";
	cout<< " The empty area (red) in container is "<<empty_area<<endl;
}
/* triangle_in_circle function: Maximum number of triangles to fit starting from the center of circle
 * calculated by placing the triangles normally or inverted. For any number the circle's limit would not be crossed.
 */
void triangle_in_circle(int radius, int edge){

	double cx,cy, temp=radius*2, dx, x=0, H=radius,h=((edge/2)*sqrt(3)),z=0, empty_area, tri_area;
	int i,j, max_triangle=0;
	cx=radius, cy=radius;
	tri_area= (edge*edge*sqrt(3))/4;
	ofstream fout;
	fout.open("output.svg");
	fout<< "<svg version=\"1.1\" baseProfile=\"full\"  xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
	fout<< " <circle cx=\""<<cx<<"\" cy=\""<<cy<<"\" r=\""<<radius<<"\" fill=\"red\" /> "<< endl;
	while(1){
		temp=(radius*2-(dx*2));
		i=(temp/edge);
		for(j=0; j<i; j++){
			max_triangle++;
			fout<<"<polygon points=\""<<x<<" "<< H<<","<< " "<<x+edge/2<<" "<< H-h <<" "<<","<< x+edge<<" "<< H<<"\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\" fill=\"green\"/>"<<endl;
			x+=edge;
		}
		dx+=(edge/2)*sqrt(3);
		x=dx;
		H-=h;
		if(H-edge<0)
			break;
		if(2*radius-dx<0)
			break;
		if(H<=0)
			break;
	}
	temp=radius*2;
	i=temp/edge;
	x=0, dx=0;
	h=(edge/2)*sqrt(3);
	H=radius;
	while(1){
		temp=(radius*2-(dx*2));
		i=(temp/edge);
		for(j=0; j<i-1; j++){
			if(i!=radius*2/edge)
			max_triangle++;
			fout<<"<polygon points=\""<<x+edge/2<<" "<< H-h<<","<< " "<<x+edge<<" "<< H<<" "<<","<< x+edge/2+edge<<" "<< H-h<<"\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\" fill=\"green\"/>"<<endl;
			x+=edge;
		}
		dx+=(edge/2)*sqrt(3);
		x=dx;
		H-=h;
		if(H-edge<0)
			break;
		if(2*radius-dx<0)
			break;
		if(H<=0)
			break;
	}
	temp=radius*2;
	i=temp/edge;
	x=0, dx=0;
	h=(edge/2)*sqrt(3);
	H=radius;
	while(1){
		temp=(radius*2-(dx*2));
		i=(temp/edge);
		for(j=0; j<i; j++){
			if(i!=radius*2/edge)
			max_triangle++;
			if(i!=radius*2/edge)
			fout<<"<polygon points=\""<<x<<" "<< H<<","<< " "<<x+edge/2<<" "<< H-h <<" "<<","<< x+edge<<" "<< H<<"\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\" fill=\"green\"/>"<<endl;
			x+=edge;
		}
		dx+=(edge/2)*sqrt(3);
		x=dx;
		H+=h;
		if(H+edge>radius*2)
			break;
		if(2*radius-dx<0)
			break;
		if(H>radius*2)
			break;
	}
	temp=radius*2;
	i=temp/edge;
	x=0, dx=0;
	h=(edge/2)*sqrt(3);
	H=radius;
	while(1){
		temp=(radius*2-(dx*2));
		i=(temp/edge);
		if(i==radius*2/edge)
			i--;
		for(j=0; j<i; j++){
			max_triangle++;
			fout<<"<polygon points=\""<<x+edge/2<<" "<< H-h<<","<< " "<<x+edge<<" "<< H<<" "<<","<< x+edge/2+edge<<" "<< H-h<<"\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\" fill=\"green\"/>"<<endl;
			x+=edge;
		}
		dx+=(edge/2)*sqrt(3);
		x=dx;
		H+=h;
		if(H+edge>radius*2)
			break;
		if(2*radius-dx<0)
			break;
		if(H>radius*2)
			break;
	}
	empty_area= (PI*radius*radius)-(max_triangle*tri_area);
	cout<<"I can fit at most " <<max_triangle<< " small shapes into the main container";
	cout<< " The empty area (red) in container is "<<empty_area<<endl;
	fout << "</svg>" << endl;
	fout.close();

}
/* circle_in_triangle: The coordinates of the circle will be calculated first at the top of the
 * triangle. Other circles will be placed by using similarity theorem to reach the maximum number of circles.
 */
void circle_in_triangle(int edge, int radius){

	double x=0, y= (edge/2)*sqrt(3), h, column, cx=edge/2,cy=radius*2, dx, empty_area, tri_area, circ_area;
	int max_circle,temp, i,j,k=0, row;
	h=(edge/2)*sqrt(3);
	tri_area=(edge*edge*sqrt(3))/4;
	circ_area=PI*radius*radius;
	row= ((h-2*radius)/(radius*sqrt(3)))+1;
	if(row==1 && (cy + radius>h)){
					row--;
	}
	ofstream fout;
	fout.open("output.svg");
	fout<< "<svg version=\"1.1\" baseProfile=\"full\"  xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
	fout<<"<polygon points=\""<<x<<" "<<y <<","<< " "<<x+ edge/2<<" "<< 0<<" "<<","<< x+edge<<" "<< y<<"\" fill=\"red\"/>"<<endl;
	if(row!=0){
		fout<< " <circle cx=\""<<cx<<"\" cy=\""<<cy<<"\" r=\""<<radius<<"\" fill=\"green\" /> "<< endl;
	}
	dx=cx;
	for(i=2; i<=row; i++){
		cy+=radius*sqrt(3);
		dx-=radius;
		cx=dx;
		if(i==row && (cy+radius)>h){
				row--;
				break;
		}
		for(j=1; j<=i; j++ ){
			fout<< " <circle cx=\""<<cx<<"\" cy=\""<<cy<<"\" r=\""<<radius<<"\" fill=\"green\" /> "<< endl;
			cx+=radius*2;
		}
	}
	max_circle= ((row*(row+1))/2);
	empty_area= (tri_area)-(max_circle*circ_area);
	cout<<"I can fit at most " <<max_circle<< " small shapes into the main container";
	cout<< " The empty area (red) in container is "<<empty_area<<endl;
	fout << "</svg>" << endl;
	fout.close();

}
/* rectangle_in_triangle function: Rectangles will be placed starting from the base of triangle
 * and the number of the maximum rectangles to fit up until the top will be calculated, by using similarity theorem.
 */
void rectangle_in_triangle(int edge, int height,int width){

	double x=0, y= (edge/2)*sqrt(3), rx,ry, h,temp, dx, empty_area, tri_area;
	int i,j,k, max_rectangle=0;
	temp=edge;
	h=(edge/2)*sqrt(3);
	tri_area=(edge*edge*sqrt(3))/4;
	rx= height/sqrt(3), ry=h-height;
	dx=rx;
	ofstream fout;
	fout.open("output.svg");
	fout<< "<svg version=\"1.1\" baseProfile=\"full\"  xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
	fout<<"<polygon points=\""<<x<<" "<<y <<","<< " "<<x+ edge/2<<" "<< 0<<" "<<","<< x+edge<<" "<< y<<"\" fill=\"red\"/>"<<endl;
	while(1){
		temp=(edge-(dx*2));
		i=(temp/width);
		for(j=0; j<i; j++){
			fout<< " <rect x=\""<<rx<<"\" y=\""<<ry<<"\" width=\""<<width<<"\" height=\""<<height;
			fout<<"\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\"" " fill=\"green\" /> "<< endl;
			max_rectangle++;
			rx+=width;
		}
		dx+=height/sqrt(3);
		rx=dx;
		ry=ry-height;
		if(edge-dx<0)
			break;
		if(ry<0)
			break;
	}
	fout << "</svg>" << endl;
	fout.close();
	empty_area=tri_area-(max_rectangle*width*height);
	cout<<"I can fit at most " <<max_rectangle<< " small shapes into the main container";
	cout<< " The empty area (red) in container is "<<empty_area<<endl;

}
/* triangle_in_triangle function: Starting from the base of the triangle, small triangles
 * will be placed inverted or normally and the maximum number of triangle will be calculated, by using similarity theorem.
 */
void triangle_in_triangle(int edge, int small_edge){

	double x=0, y= (edge/2)*sqrt(3), h, H, temp,dx, empty_area,tri_area, small_tri_area;
	int i,j,k, max_triangle=0;
	temp=edge;
	tri_area=(edge*edge*sqrt(3))/4;
	small_tri_area=(small_edge*small_edge*sqrt(3))/4;
	i=temp/small_edge;
	H=(edge/2)*sqrt(3);
	h=(small_edge/2)*sqrt(3);
	ofstream fout;
	fout.open("output.svg");
	fout<< "<svg version=\"1.1\" baseProfile=\"full\"  xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
	fout<<"<polygon points=\""<<x<<" "<<y <<","<< " "<<x+ edge/2<<" "<< 0<<" "<<","<< x+edge<<" "<< y<<"\" fill=\"red\"/>"<<endl;
	while(1){
	for(j=0; j<i; j++){
		max_triangle++;
		fout<<"<polygon points=\""<<x<<" "<< H<<","<< " "<<x+small_edge/2<<" "<< H-h<<" "<<","<< x+small_edge<<" "<< H<<"\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\" fill=\"green\"/>"<<endl;
		x+=small_edge;
	}
	dx+=small_edge/2;
	x=dx;
	temp=((i-1)*small_edge);
	i=temp/small_edge;
	H-=h;
	if(temp<0)
		break;
	}
	temp=edge;
	i=temp/small_edge;
	x=0, dx=0;
	H=(edge/2)*sqrt(3);
	h=(small_edge/2)*sqrt(3);
	while(1){
		for(j=0; j<i-1; j++){
			max_triangle++;
			fout<<"<polygon points=\""<<x+small_edge/2<<" "<< H-h<<","<< " "<<x+small_edge<<" "<< H<<" "<<","<< x+small_edge/2+small_edge<<" "<< H-h<<"\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\" fill=\"green\"/>"<<endl;
			x+=small_edge;
		}
		dx+=small_edge/2;
		x=dx;
		temp=((i-1)*small_edge);
		i=temp/small_edge;
		H-=h;
		if(temp<0)
			break;
	}
	empty_area=(tri_area)-((small_tri_area)*max_triangle);
	cout<<"I can fit at most " <<max_triangle<< " small shapes into the main container";
	cout<< " The empty area (red) in container is "<<empty_area<<endl;
	fout << "</svg>" << endl;
	fout.close();

}
void choose_shapes(){
	
	char shape, small_shape;
	int width,height,radius,edge,s_width,s_height,s_edge,s_radius;
	cout<<"Please enter the main container shape(R, C, T)"<<endl;
	cin>>shape;
	if(shape=='R'|| shape=='r'){
		cout<<"Please enter the width"<<endl;
		cin>>width;
		cout<<"Please enter the height"<<endl;
		cin>>height;
		shapes contShape = shapes::rectangle;
	}
	else if(shape=='C'|| shape=='c'){
		cout<<"Please enter the radius"<<endl;
		cin>>radius;
		shapes contShape = shapes::circle;

	}
	else if(shape=='T'|| shape=='t'){
		cout<<"Please enter the edge"<<endl;
		cin>>edge;
		shapes contShape = shapes::triangle;
	}
	cout<<"Please enter the small shape(R, C, T)"<<endl;
	cin>>small_shape;

	if(shape=='R'|| shape=='r'){

		if(small_shape=='C'|| small_shape=='c'){
			cout<<"Please enter the radius"<<endl;
			cin>>radius;
			circle_in_rectangle(height,width,radius);
			shapes smallShape = shapes::circle;
		}
		else if(small_shape=='R'|| small_shape=='r'){
			cout<<"Please enter the width"<<endl;
			cin>>s_width;
			cout<<"Please enter the height"<<endl;
			cin>>s_height;
			rectangle_in_rectangle(height,width,s_height,s_width);
			shapes smallShape = shapes::rectangle;
		}
		else if(small_shape=='T'|| small_shape=='t'){
			cout<<"Please enter the edge"<<endl;
			cin>>edge;
			triangle_in_rectangle(height,width,edge);
			shapes smallShape = shapes::triangle;
		}
	}
	else if(shape=='C'|| shape=='c'){

		if(small_shape=='C'|| small_shape=='c'){
			cout<<"Please enter the radius"<<endl;
			cin>>s_radius;
			circle_in_circle(radius,s_radius);
			shapes smallShape = shapes::circle;
		}
		else if(small_shape=='R'|| small_shape=='r'){
			cout<<"Please enter the width"<<endl;
			cin>>s_width;
			cout<<"Please enter the height"<<endl;
			cin>>s_height;
			rectangle_in_circle(radius, s_height, s_width);
			shapes smallShape = shapes::rectangle;
		}
		else if(small_shape=='T'|| small_shape=='t'){
			cout<<"Please enter the edge"<<endl;
			cin>>edge;
			triangle_in_circle(radius, edge);
			shapes smallShape = shapes::triangle;
		}
	}
	else if(shape=='T'|| shape=='t'){

		if(small_shape=='C'|| small_shape=='c'){
			cout<<"Please enter the radius"<<endl;
			cin>>s_radius;
			circle_in_triangle(edge, s_radius);
			shapes smallShape = shapes::circle;
		}
		else if(small_shape=='R'|| small_shape=='r'){
			cout<<"Please enter the width"<<endl;
			cin>>s_width;
			cout<<"Please enter the height"<<endl;
			cin>>s_height;
			rectangle_in_triangle(edge,s_height, s_width);
			shapes smallShape = shapes::rectangle;
		}
		else if(small_shape=='T'|| small_shape=='t'){
			cout<<"Please enter the edge"<<endl;
			cin>>s_edge;
			triangle_in_triangle(edge, s_edge);
			shapes smallShape = shapes::triangle;
		}
	}
	
}


