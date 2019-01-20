#include "Circle.h"


Circle::Circle()
 {
	radius=0;
 }
Circle::Circle(int my_radius, double my_x, double my_y){

	set_radius(my_radius);
	set_x(my_x);
	set_y(my_y);
}
void Circle::input(){
	
	int temp_radius;
	cout<<"Enter the radius"<<endl;
	cin>>temp_radius;
	set_radius(temp_radius);
}
void Circle::set_radius(int my_radius){

	if(my_radius>0){
		radius=my_radius;
	}	
	else
		exit(1);
}
void Circle::set_x(double my_x)
{
	if(my_x>=0 ){
		x=my_x;
		}
	else
		exit(1);
}
void Circle::set_y(double my_y)
{
	if(my_y>=0 ){
		y=my_y;
		}
	else
		exit(1);
}
void Circle::draw(ofstream &fout)
{
	
	fout<< " <circle cx=\""<<x<<"\" cy=\""<<y<<"\" r=\""<<radius<<"\"  ";
}

