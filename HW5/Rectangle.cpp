#include "Rectangle.h"

namespace RectangleNameS{

double Rectangle::total_area=0;
double Rectangle::total_perimeter=0;
vector<Rectangle*> Rectangle::new_rects;

Rectangle::Rectangle()
{
	
}

Rectangle::Rectangle(double my_width, double my_height, double my_x, double my_y)
 {
	set_height_width(my_width,my_height);
	set_positions(my_x, my_y);
	total_area+=area();
	total_perimeter+=perimeter();

 }

 Rectangle::Rectangle(double my_x, double my_y)
 {
 	set_positions(my_x, my_y);
 }

void Rectangle::input(){
	
	int temp_width, temp_height;
	cout<<"Enter the width"<<endl;
	cin>> temp_width;
	cout<<"Enter the height:"<<endl;
	cin>>temp_height;
	set_height_width(temp_width, temp_height);

}
void Rectangle::set_height_width(double my_width, double my_height)throw (int, int){
	
	int wrong_width=0, wrong_height=0;
	if(my_width>0 && my_height>0){
		
		width=my_width;
		height=my_height;
	}
	else if(my_width<0)
		throw wrong_width;
	else if(my_height<0)
		throw wrong_height;
}
void Rectangle::set_positions(double my_x, double my_y)throw (int, int)
{
	int wrong_x=-1, wrong_y=-1;
	if(my_x>=0 && my_y>=0){
		x=my_x;
		y=my_y;	
		}
	else if (my_x<0)
		throw wrong_x;
	else if(my_y<0)
		throw wrong_y;
}
void Rectangle::draw(ofstream &fout)
{

	fout << " <rect x=\"" << x <<"\" y=\""<< y;
	fout << "\" width=\"" <<width;
	fout <<"\" height=\""<<height;
	fout <<"\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\"";
	fout<<" fill=\"green\" />"<<endl;

}

double Rectangle::perimeter() const{

		double rect_perimeter;
		rect_perimeter=(width+height)*2;
		return rect_perimeter;
}


double Rectangle::area() const{

	
		double rect_area;
		rect_area=width*height;
		return rect_area;
	
}
// operator << overloading for writing on svg file
ostream& operator <<(ostream& outputStream, const Rectangle& my_rect){

	int my_width=my_rect.width, my_height=my_rect.height;
	double my_x=my_rect.x, my_y=my_rect.y;
	
	if(my_width>0 && my_height>0 && my_x>=0 && my_y>=0){
	outputStream << " <rect x=\"" << my_x <<"\" y=\""<< my_y;
	outputStream << "\" width=\"" <<my_width;
	outputStream <<"\" height=\""<<my_height;
	outputStream <<"\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\"";
	}

	return outputStream;
}

Rectangle& Rectangle::operator++(int ignoreMe) //postfix increment
{
 	int temp1=x;
 	int temp2=y;
 	x++;
 	y++;
 	Rectangle* x=new Rectangle(temp1, temp2);
 	new_rects.push_back(x);
 	return *x;
}

Rectangle& Rectangle::operator++() //prefix increment
{

 	x++;
 	y++;
 	return *this;

}

Rectangle& Rectangle::operator--(int ignoreMe) //postfix decrement
{
 	int temp1=x;
 	int temp2=y;
 	x--;
 	y--;
 	Rectangle* x=new Rectangle(temp1, temp2);
 	new_rects.push_back(x);
 	return *x;

 }

Rectangle& Rectangle::operator--() //prefix decrement
{

 	x--;
 	y--;
 	return *this;

}


Rectangle operator+(Rectangle& my_rect, double num){

	my_rect.width=my_rect.width+num;
	my_rect.height=my_rect.height+num;
	return my_rect;
}


Rectangle operator-(Rectangle& my_rect, double num){

	if( my_rect.height-num>0 && my_rect.width-num>0){
		my_rect.width=my_rect.width-num;
		my_rect.height=my_rect.height-num;
	}
	return my_rect;
}


} //end of Rectangle namespace