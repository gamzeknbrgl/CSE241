#include "Rectangle.h"


/*I can only use the unnamed namespace here
* Because i don't have any helper functions that
* i can use out of the other namespaces. */
namespace{

	void ReadWidth(int &rectWidth){

		int testWidth;
		cin>>testWidth;

		if(testWidth<0){

			cout<<"Illegal width"<<endl;
			exit(1);
		}
		else 
			cout<<"Width is: "<<testWidth<<endl;
	}

	void ReadHeight(int &rectHeight){

		int testHeight;
		cin>>testHeight;

		if(testHeight<0){

			cout<<"Illegal height"<<endl;
			exit(1);
		}
		else 
			cout<<"height is: "<<testHeight<<endl;
	}
}

namespace RectangleNameS{

double Rectangle::total_area=0;
double Rectangle::total_perimeter=0;


Rectangle::Rectangle()
{
	
}

Rectangle::Rectangle(double my_width, double my_height, double my_x, double my_y)
 {
	set_height_width(my_width,my_height);
	set_positions(my_x, my_y);
	total_area+=rect_area(my_width,my_height);
	total_perimeter+=rect_perimeter(my_width,my_height);

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
void Rectangle::set_height_width(double my_width, double my_height){
	

	if(my_width>0 && my_height>0){
		
		width=my_width;
		height=my_height;
	}
	else
		exit(1);
}
void Rectangle::set_positions(double my_x, double my_y)
{
	if(my_x>=0 && my_y>=0){
		x=my_x;
		y=my_y;	
		}
	else
		exit(1);
}
void Rectangle::draw(ofstream &fout, const Rectangle& my_rect)
{

	fout<<my_rect;

}

double Rectangle::rect_perimeter(double my_width, double my_height) const{

	if(my_width>0 && my_height>0){
		double rect_perimeter;
		rect_perimeter=(my_width+my_height)*2;
		return rect_perimeter;
	}
	else
		exit(1);
}

double Rectangle::rect_area(double my_width, double my_height) const{

	if(my_width>0 && my_height>0){
		double rect_area;
		rect_area=my_width*my_height;
		return rect_area;
	}
	else
		exit(1);
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

Rectangle Rectangle::operator++(int ignoreMe) //postfix increment
{
 	int temp1=x;
 	int temp2=y;
 	x++;
 	y++;
 	return Rectangle(temp1, temp2);
}

Rectangle Rectangle::operator++() //prefix increment
{

 	x++;
 	y++;
 	return Rectangle(x,y);

}

Rectangle Rectangle::operator--(int ignoreMe) //postfix decrement
{
 	int temp1=x;
 	int temp2=y;
 	x--;
 	y--;
 	return Rectangle(temp1, temp2);
 }

Rectangle Rectangle::operator--() //prefix decrement
{

 	x--;
 	y--;
 	return Rectangle(x,y);

}

bool operator ==(const Rectangle& my_rect1, const Rectangle& my_rect2){

	return my_rect1.rect_area(my_rect1.get_width(), my_rect1.get_height()) == my_rect2.rect_area(my_rect2.get_width(), my_rect2.get_height());

}

bool operator !=(const Rectangle& my_rect1, const Rectangle& my_rect2){

	return my_rect1.rect_area(my_rect1.get_width(), my_rect1.get_height()) != my_rect2.rect_area(my_rect2.get_width(), my_rect2.get_height());

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


}