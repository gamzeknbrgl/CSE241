#ifndef SHAPE_H_
#define SHAPE_H_
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cmath>
#define PI 3.14
using namespace std;

namespace ShapeNameS{


class Shape
{

public:

	virtual double area() const=0;
	virtual double perimeter() const=0;
	friend bool operator ==(const Shape& my_shape1, const Shape& my_shape2);
	friend bool operator !=(const Shape& my_shape1, const Shape& my_shape2);
	friend bool operator <(const Shape& my_shape1, const Shape& my_shape2);
	friend bool operator >(const Shape& my_shape1, const Shape& my_shape2);
	friend ostream& operator <<(ofstream& outputStream, Shape& my_shape);
	virtual string shapeName()const=0;
	virtual void draw(ofstream &fout)=0;
	virtual Shape& operator++()=0;//prefix increment
	virtual Shape& operator--()=0;//prefix decrement
	virtual Shape& operator--(int ignoreMe)=0;//postfix decrement
	virtual Shape& operator++(int ignoreMe)=0;//prefix increment
	
};


}
#endif