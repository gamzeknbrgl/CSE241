#include "Rectangle.h"
Rectangle::Rectangle()
{
	width=0;
	height=0;
}

Rectangle::Rectangle(int my_width, int my_height, double my_x, double my_y)
 {
	set_height_width(my_width,my_height);
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
void Rectangle::set_height_width(int my_width, int my_height){
	

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
void Rectangle::draw(ofstream &fout)
{

	fout<< " <rect x=\""<<x<<"\" y=\""<<y<<"\" width=\""<<width<<"\" height=\""<<height<<"\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\"";
	//fout << " fill=\"green\" />  " <<endl;


}
