#include "Triangle.h"

namespace TriangleNameS{

double Triangle::total_area=0;
double Triangle::total_perimeter=0;
vector<Triangle*> Triangle::new_tri;

Triangle::Triangle()
{
	edge=0;
}

Triangle::Triangle(double my_edge, double my_x, double my_y, double my_z)
 {
	set_edge(my_edge);
	set_positions(my_x, my_y,my_z);
	total_area+=area();
	total_perimeter+=perimeter();

 }

 Triangle::Triangle(double my_x, double my_y, double my_z)
 {
	
	set_positions(my_x, my_y,my_z);

 }

void Triangle::input(){
	
	int temp_edge;
	cout<<"Enter the edge"<<endl;
	cin>> temp_edge;
	set_edge(temp_edge);
	set_positions(0,temp_edge*sqrt(3)/2,0);

}


void Triangle::set_edge(double my_edge)throw (int){

	int wrong_edge=0;
	if(my_edge>0){

		edge=my_edge;
	}
	else
		throw wrong_edge;
}
void Triangle::set_positions(double my_x, double my_y, double my_z)throw (int, int, int)
{

	int wrong_x=-1, wrong_y=-1, wrong_z=-1;
	if(my_x>=0 && my_y>=0 && my_z>=0){
		
		x=my_x;
		y=my_y;
		z=my_z;
		}
	else if(my_x<0)
		throw wrong_x;
	else if(my_y<0)
		throw wrong_y;
	else if (my_z<0)
		throw wrong_z;

}
void Triangle::draw(ofstream &fout)
{
	
	fout << "<polygon points=\"" << x << " " << y <<"," <<" ";
	fout << x+ (edge/2) << " " << z << " " << "," << x+edge<< " "<<y;
	fout <<"\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\" ";
	fout<<" fill=\"green\" />"<<endl;
}

double Triangle::perimeter() const{


		double tri_perimeter;
		tri_perimeter=3*edge;
		return tri_perimeter;
	
}

double Triangle::area() const{

		double tri_area;
		tri_area=(sqrt(3)*edge*edge)/4;
		return tri_area;
	

}
// operator << overloading for writing on svg file
ostream& operator <<(ostream& outputStream, const Triangle& my_tri){

	int my_edge=my_tri.edge;
	double my_x=my_tri.x, my_y=my_tri.y, my_z=my_tri.z;
	
	if(my_edge>0 && my_x>=0 && my_y>=0 && my_z>=0){
	outputStream << "<polygon points=\"" << my_x << " " << my_y <<"," <<" ";
	outputStream << my_x+ (my_edge/2) << " " << my_z << " " << "," << my_x+my_edge<< " "<<my_y;
	outputStream <<"\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\" ";
	}

	return outputStream;

}

Triangle& Triangle::operator++(int ignoreMe) //postfix increment
{
 	int temp1=x;
 	int temp2=y;
 	int temp3=z;
 	x++;
 	y++;
 	z++;
 	Triangle* x=new Triangle(temp1, temp2,temp3);
 	new_tri.push_back(x);
 	return *x;
}

Triangle& Triangle::operator++() //prefix increment
{

 	x++;
 	y++;
 	z++;
 	return *this;

}

 Triangle& Triangle::operator--(int ignoreMe) //postfix decrement
{
 	int temp1=x;
 	int temp2=y;
 	int temp3=z;
 	x--;
 	y--;
 	z--;
 	Triangle* x=new Triangle(temp1, temp2,temp3);
 	new_tri.push_back(x);
 	return *x;
}


 Triangle& Triangle::operator--() //prefix decrement
{

 	x--;
 	y--;
 	z--;
 	return *this;

}

Triangle operator+(Triangle& my_tri, double num) {

 	my_tri.edge=my_tri.edge+num;
 	my_tri.y=(my_tri.edge*sqrt(3))/2;
 	return my_tri;

 }

 Triangle operator-(Triangle& my_tri, double num) {

 	if(my_tri.edge-num>0 )
 	my_tri.edge=my_tri.edge-num;
 	my_tri.y=(my_tri.edge*sqrt(3))/2;

 	return my_tri;

 }


}