#include "Circle.h"

double Circle::total_area=0;
double Circle::total_perimeter=0;

Circle::Circle()
 {
	radius=0;
 }
Circle::Circle(double my_radius, double my_x, double my_y){

	set_radius(my_radius);
	set_x(my_x);
	set_y(my_y);
}

Circle::Circle(double my_x, double my_y)
{
	set_x(my_x);
	set_y(my_y);

}

Circle::Circle(double my_radius){

	set_radius(my_radius);

}

void Circle::input(){
	
	double temp_radius;
	cout<<"Enter the radius"<<endl;
	cin>>temp_radius;
	set_radius(temp_radius);
}
void Circle::set_radius(double my_radius){

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
void Circle::draw(ofstream &fout, const Circle& my_circle)
{
	
	fout<<my_circle;
}
// circle perimeter calculating
double Circle::circle_perimeter(double circ_radius) const{

	if(circ_radius>0){
		double circle_perimeter;
		circle_perimeter=2*PI*radius;
		return circle_perimeter;
	}
	else
		exit(1);
}
// circle area calculating
double Circle::circle_area(double circ_radius) const{

		
		if(circ_radius>0){
			double circle_area;
			circle_area=PI*circ_radius*circ_radius;
			return circle_area;
		}
		else
			exit(1);
}
// operator << overloading for writing on svg file

ostream& operator <<(ostream& outputStream, const Circle& my_circle){

	double my_radius=my_circle.radius;
	double my_x=my_circle.x, my_y=my_circle.y;
	
	if(my_radius>0 && my_x>=0 && my_y>=0){
	outputStream << " <circle cx=\""<< my_x;
	outputStream << "\" cy=\"" <<my_y;
	outputStream <<"\" r=\""<< my_radius<<"\"  ";
	}

	return outputStream;
}

Circle Circle::operator++(int ignoreMe) //postfix increment
 {
 	int temp1=x;
 	int temp2=y;
 	x++;
 	y++;
 	return Circle(temp1, temp2);
 }

 Circle Circle::operator++() //prefix increment
 {
 	x++;
 	y++;
 	return Circle(x,y);

 }

 Circle Circle::operator--(int ignoreMe) //postfix decrement
 {
 	int temp1=x;
 	int temp2=y;
 	x--;
 	y--;
 	return Circle(temp1, temp2);
 }


 Circle Circle::operator--() //prefix decrement
 {

 	x--;
 	y--;
 	return Circle(x,y);

 }

 bool operator ==(const Circle& my_circle1, const Circle& my_circle2){
 	
 	return my_circle1.circle_area(my_circle1.get_radius()) == my_circle2.circle_area(my_circle2.get_radius());
 	
 }

 bool operator !=(const Circle& my_circle1, const Circle& my_circle2){

 	return my_circle1.circle_area(my_circle1.get_radius()) != my_circle2.circle_area(my_circle2.get_radius());
 	
 }

Circle operator+(Circle& my_circle, double num) {

 	my_circle.radius=my_circle.radius+num;
 	return my_circle;

 }

 Circle operator-(Circle& my_circle, double num) {

 	if(my_circle.radius-num>0)
 	my_circle.radius=my_circle.radius-num;
 	return my_circle;

 }

double Circle::total_area_f(Circle &my_circle){

 	total_area+=(my_circle.radius*PI*my_circle.radius);
 	return total_area;

 }


double Circle::total_perimeter_f(Circle &my_circle){

 	total_perimeter+=(2*PI*my_circle.radius);
 	return total_perimeter;

 }