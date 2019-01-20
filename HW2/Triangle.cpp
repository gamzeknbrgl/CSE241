#include "Triangle.h"

Triangle::Triangle()
{
	edge=0;
}

Triangle::Triangle(int my_edge, double my_x, double my_y, double my_z)
 {
	set_edge(my_edge);
	set_positions(my_x, my_y,my_z);

 }

void Triangle::input(){
	
	int temp_edge;
	cout<<"Enter the edge"<<endl;
	cin>> temp_edge;
	set_edge(temp_edge);

}


void Triangle::set_edge(int my_edge){

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
void Triangle::draw(ofstream &fout)
{
	
	fout<<"<polygon points=\""<<x<<" "<< y<<","<< " "<<x+edge/2<<" "<< z<<" "<<","<< x+edge<<" "<< y<<"\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\" " ;
	//fout << " fill=\"green\" />  " <<endl;
		

}

