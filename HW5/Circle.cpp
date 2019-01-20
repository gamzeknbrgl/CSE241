#include "Circle.h"

namespace CircleleNameS{

double Circle::total_area=0;
double Circle::total_perimeter=0;
vector<Circle*> Circle::new_circles;

Circle::Circle()
 {
	
 }
Circle::Circle(double my_radius, double my_x, double my_y){

	set_radius(my_radius);
	set_x(my_x);
	set_y(my_y);
	total_area+=area();
	total_perimeter+=perimeter();
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
void Circle::set_radius(double my_radius)throw (int){

	int wrong_radius=0;
	if(my_radius>0){
		radius=my_radius;
	}	
	else
		throw wrong_radius;
}
void Circle::set_x(double my_x)throw (int)
{
	int wrong_x=-1;
	if(my_x>=0 ){
		x=my_x;
		}
	else
		throw wrong_x;
}
void Circle::set_y(double my_y)throw (int)
{
	int wrong_y=-1;
	if(my_y>=0 ){
		y=my_y;
		}
	else
		throw wrong_y;
}
void Circle::draw(ofstream &fout)
{
	fout << " <circle cx=\""<< x;
	fout << "\" cy=\"" <<y;
	fout <<"\" r=\""<< radius<<"\"  ";
	fout<<" fill=\"green\" />"<<endl;
	
}
// circle perimeter calculating
double Circle::perimeter() const{

		double circle_perimeter;
		circle_perimeter=2*PI*radius;
		return circle_perimeter;
	
}
// circle area calculating
double Circle::area() const{

			double circle_area;
			circle_area=PI*radius*radius;
			return circle_area;
	
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

Circle& Circle::operator++(int ignoreMe) //postfix increment
 {

 	int temp1=x;
 	int temp2=y;
 	x++;
 	y++;
 	Circle* x=new Circle(temp1, temp2);
 	new_circles.push_back(x);
 	return *x;
 }

 Circle& Circle::operator++() //prefix increment
 {
 	x++;
 	y++;
 	return *this;

 }

 Circle& Circle::operator--(int ignoreMe) //postfix decrement
 {
 	int temp1=x;
 	int temp2=y;
 	x--;
 	y--;
 	Circle* x=new Circle(temp1, temp2);
 	new_circles.push_back(x);
 	return *x;
 	
 }


 Circle& Circle::operator--() //prefix decrement
 {

 	x--;
 	y--;
 	return *this;

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

}