#include "Polygon.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;


namespace PolygonNameS{

Polygon :: Point2D :: Point2D( ){

}

Polygon :: Point2D :: Point2D( double my_x, double my_y){

	set_x(my_x);
	set_y(my_y);
}

void Polygon :: Point2D :: set_x(double my_x)throw (int){

		int wrong_x=0;
		x=my_x;
		if(my_x<0)
			throw wrong_x;
	
}

void Polygon :: Point2D :: set_y(double my_y)throw (int){

		int wrong_y;
		y=my_y;
		if(my_y<0)
			throw wrong_y;

}

bool operator ==(const Polygon& my_poly1, const Polygon& my_poly2){

	return (my_poly1.area() == my_poly2.area());

} //compare two shapes with respect to their areas

bool operator !=(const Polygon& my_poly1, const Polygon& my_poly2){

	return (my_poly1.area() != my_poly2.area());

} 
bool operator <(const Polygon& my_poly1, const Polygon& my_poly2){

	return (my_poly1.area() < my_poly2.area());

} //compare two shapes with respect to their areas
bool operator >(const Polygon& my_poly1, const Polygon& my_poly2){

	return (my_poly1.area() > my_poly2.area());

} //compare two shapes with respect to their areas

ostream& operator <<(ofstream& outputStream, Polygon& my_poly){

	my_poly.draw(outputStream);
	return outputStream;
	
}
}