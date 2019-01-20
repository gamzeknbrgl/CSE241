#include "Polygon.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;


namespace PolygonNameS{

Polygon :: Point2D :: Point2D( ){

	x=0;
	y=0;
}

Polygon :: Point2D :: Point2D( double my_x, double my_y){

	set_x(my_x);
	set_y(my_y);
}

void Polygon :: Point2D :: set_x(double my_x){

	if(x>=0)
		x=my_x;
	else
		exit(1);
}

void Polygon :: Point2D :: set_y(double my_y){

	if(y>=0)
		y=my_y;
	else
		exit(1);
}

Polygon::Polygon()
{
	
}
//This constructor returns a new Polygon object
Polygon::Polygon(int vert, Point2D *a){

	set_vertices(vert);
	points_2D= new Point2D[vert];
	for(auto i=0; i<vertices; i++){

		points_2D[i]=a[i];

	}

}

Polygon::Polygon(vector<Point2D> my_points){

	vertices=my_points.size();
	points_2D= new Point2D[my_points.size()];
	for (auto i=0; i<my_points.size(); i++){

		points_2D[i]=my_points[i];
	}

}
//Conversion constructor for rectangle
Polygon::Polygon (Rectangle my_rect){

	vertices=4;
	points_2D= new Point2D[4];
	points_2D[0]= Point2D(my_rect.get_x(), my_rect.get_y());
	points_2D[1]= Point2D(my_rect.get_x()+my_rect.get_width(), my_rect.get_y());
	points_2D[2]= Point2D(my_rect.get_x()+my_rect.get_width(), my_rect.get_y()+my_rect.get_height());
	points_2D[3]= Point2D(my_rect.get_x(), my_rect.get_y()+my_rect.get_height());

}
//Conversion constructor for triangle
Polygon::Polygon (Triangle my_tri){

	vertices=3;
	points_2D= new Point2D[3];
	points_2D[0]= Point2D(my_tri.get_x(), my_tri.get_y());
	points_2D[1]= Point2D(my_tri.get_x()+(my_tri.get_edge()/2), my_tri.get_z());
	points_2D[2]= Point2D(my_tri.get_x()+my_tri.get_edge(), my_tri.get_y());
}

//Conversion constructor for circle 
Polygon::Polygon (Circle my_circle){

	vertices=100;
	points_2D= new Point2D[100];
	double my_x, my_y, my_radius, temp_x, temp_y, temp;
	double s=(2*PI)/100;
	my_x= my_circle.get_x();
	my_y=my_circle.get_y();
	my_radius=my_circle.get_radius();
	for (auto i=0; i<100; i++){

		temp=s*i;
		temp_x= (my_x)+ (my_radius *cos(temp));
		temp_y= (my_y)+ (my_radius *sin(temp));	
		points_2D[i].set_x(temp_x);
		points_2D[i].set_y(temp_y);
	}

}

//conversion constructor
Polygon::Polygon (const Point2D &my_point) {

	points_2D= new Point2D[0];
	points_2D[0]= Point2D(my_point.get_x(), my_point.get_y());

}

//Copy constructor
Polygon::Polygon(const Polygon &my_poly){

	vertices=my_poly.get_vert();
	points_2D=new Point2D[vertices];
	for(auto i=0; i<vertices; i++){

		points_2D[i]=my_poly.points_2D[i];
	}
}


void Polygon::set_vertices(int vert)
{
	if(vert>0){
		
			vertices=vert;
		}
	else
		exit(1);
}

//Operator[] that returns a reference to the point at the given index
Polygon::Point2D &Polygon::operator[](int index){

	if(index<0 && index>vertices){

		exit(1);
	}
	return points_2D[index];

}

Polygon& Polygon::operator=(const Polygon &my_poly){

	if(vertices!= my_poly.vertices){

		delete[] points_2D;
		points_2D=new Point2D[my_poly.vertices];
	}
	vertices=my_poly.vertices;
	for(auto i=0; i<vertices; i++)
		points_2D[i]=my_poly.points_2D[i];
	return *this;
}


//Operator<< for producing the SVG code
ostream& operator <<(ostream& outputStream, const Polygon& my_poly){

		
		double my_x, my_y, vert;
		vert=my_poly.get_vert();
		
			outputStream<<"<polygon points= \"";
			for(auto i=0; i<vert; i++){
			my_x=my_poly.get_array()[i].get_x();
			my_y=my_poly.get_array()[i].get_y();
			outputStream<<my_x<<","<<my_y<<" ";
			}
			outputStream <<" \"";
			outputStream<<" stroke=\"black\" stroke-width=\"3\" fill=\"rgb(121,0,121)\"" ;
			outputStream <<"/>"<<endl;
	
}
//destructor
Polygon::~Polygon(){

	delete[]points_2D;
}
//Operator== that returns true if two Polygons are equal
bool operator ==(const Polygon& my_poly1, const Polygon& my_poly2){


	if(my_poly1.get_vert() != my_poly2.get_vert())
		return false;

	else if (my_poly1.get_vert() == my_poly2.get_vert()){

		for(auto i=0; i<my_poly1.get_vert(); i++){

			if(my_poly1.get_array()[i].get_x()== my_poly2.get_array()[i].get_x() 
				&& my_poly1.get_array()[i].get_y()== my_poly1.get_array()[i].get_y())
				return true;
			else
				return false;  
		}

	}
}
//Operator== that returns true if two Polygons are not equal
bool operator !=(const Polygon& my_poly1, const Polygon& my_poly2){


	if(my_poly1.get_vert() != my_poly2.get_vert())
		return true;

	else if (my_poly1.get_vert() == my_poly2.get_vert()){

		for(auto i=0; i<my_poly1.get_vert(); i++){

			if(my_poly1.get_array()[i].get_x()!= my_poly2.get_array()[i].get_x() 
				&& my_poly1.get_array()[i].get_y()!= my_poly1.get_array()[i].get_y())
				return true;
			else
				return false;  
		}

	}
}

//Operator+ that adds two Polygons by concatenating the points and returns the result as a new object
Polygon operator+(Polygon& my_poly1, Polygon& my_poly2){

	int vert=my_poly1.vertices+my_poly2.vertices;
	Polygon::Point2D *temp;
	temp= new Polygon::Point2D[vert];
	int i;
	for (auto i=0; i<my_poly1.vertices; i++){

		temp[i]=my_poly1.points_2D[i];
	}
	i=my_poly1.vertices;
	for (auto j=0; j<my_poly2.vertices; j++)
	{
		
		temp[i]=my_poly2.points_2D[j];
		if(i!=vert){
			i++;
		}
	}
	return Polygon(vert, temp);
}


}