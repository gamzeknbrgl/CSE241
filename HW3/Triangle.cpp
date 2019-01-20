#include "Triangle.h"

double Triangle::total_area=0;
double Triangle::total_perimeter=0;

Triangle::Triangle()
{
	edge=0;
}

Triangle::Triangle(double my_edge, double my_x, double my_y, double my_z)
 {
	set_edge(my_edge);
	set_positions(my_x, my_y,my_z);

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


void Triangle::set_edge(double my_edge){

	if(my_edge>0){

		edge=my_edge;
	}
	else
		exit(1);
}
void Triangle::set_positions(double my_x, double my_y, double my_z)
{
	if(my_x>=0 && my_y>=0 && my_z>=0){
		
		x=my_x;
		y=my_y;
		z=my_z;
		}
	else
		exit(1);
}
void Triangle::draw(ofstream &fout, const Triangle& my_tri)
{
	
		
	fout<<my_tri;
}

double Triangle::tri_perimeter(double tri_edge) const{


	if(tri_edge>0){
		double tri_perimeter;
		tri_perimeter=3*edge;
		return tri_perimeter;
	}
	else
		exit(1);
}

double Triangle::tri_area(double tri_edge) const{

	if(tri_edge>0){
		double tri_area;
		tri_area=(sqrt(3)*edge*edge)/4;
		return tri_area;
	}
	else
		exit(1);

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

Triangle Triangle::operator++(int ignoreMe) //postfix increment
{
 	int temp1=x;
 	int temp2=y;
 	int temp3=z;
 	x++;
 	y++;
 	z++;
 	return Triangle(temp1, temp2, temp3);
}

Triangle Triangle::operator++() //prefix increment
{

 	x++;
 	y++;
 	z++;
 	return Triangle(x,y,z);

}

 Triangle Triangle::operator--(int ignoreMe) //postfix decrement
{
 	int temp1=x;
 	int temp2=y;
 	int temp3=z;
 	x--;
 	y--;
 	z--;
 	return Triangle(temp1, temp2, temp3);
}


 Triangle Triangle::operator--() //prefix decrement
{

 	x--;
 	y--;
 	z--;
 	return Triangle(x,y,z);

}

bool operator ==(const Triangle& my_tri1, const Triangle& my_tri2){

	return my_tri1.tri_area(my_tri1.get_edge()) == my_tri2.tri_area(my_tri2.get_edge());

}

bool operator !=(const Triangle& my_tri1, const Triangle& my_tri2){

	return my_tri1.tri_area(my_tri1.get_edge()) != my_tri2.tri_area(my_tri2.get_edge());

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

double Triangle::total_area_f(Triangle &my_tri){

 	total_area+=((sqrt(3)*my_tri.edge*my_tri.edge)/4);
 	return total_area;

 }


double Triangle::total_perimeter_f(Triangle &my_tri){

 	total_perimeter+=(3*my_tri.edge);
 	return total_perimeter;

 }