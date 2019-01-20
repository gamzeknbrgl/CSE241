#include "Shape.h"

namespace ShapeNameS{

	

bool operator ==(const Shape& my_shape1, const Shape& my_shape2){

	return (my_shape1.area() == my_shape2.area());

} //compare two shapes with respect to their areas

bool operator !=(const Shape& my_shape1, const Shape& my_shape2){

	return (my_shape1.area() != my_shape2.area());

} //compare two shapes with respect to their areas

bool operator <(const Shape& my_shape1, const Shape& my_shape2){

	return (my_shape1.area() < my_shape2.area());

} 
bool operator >(const Shape& my_shape1, const Shape& my_shape2){

	return (my_shape1.area() > my_shape2.area());

} 
ostream& operator <<(ofstream& outputStream, Shape& my_shape){

	my_shape.draw(outputStream);
	return outputStream;
	
}

} //end of shape namespace
