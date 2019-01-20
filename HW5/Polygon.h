#ifndef POLYGON_H_
#define POLYGON_H_
#include "Shape.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cmath>
#define PI 3.14
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Shape.h"
using namespace std;

using RectangleNameS::Rectangle;
using TriangleNameS::Triangle;
using CircleleNameS::Circle;
using ShapeNameS::Shape;

namespace PolygonNameS{

class Polygon{

public:

	class Point2D{

	public:
		Point2D();
		Point2D(double my_x, double my_y);
		void set_x(double my_x)throw (int);
		void set_y(double my_y)throw (int);
		inline double get_x() const {return x;}
		inline double get_y() const {return y;}

	private:

		double x;
		double y;
	};
	virtual double area() const=0;
	virtual double perimeter() const=0;
	virtual void draw(ofstream &fout)=0;
	friend bool operator ==(const Polygon& my_poly1, const Polygon& my_poly2);
	friend bool operator !=(const Polygon& my_poly1, const Polygon& my_poly2);
	friend bool operator <(const Polygon& my_poly1, const Polygon& my_poly2);
	friend bool operator >(const Polygon& my_poly1, const Polygon& my_poly2);
	virtual Polygon& operator++()=0;//prefix increment
	virtual Polygon& operator--()=0;//prefix decrement
	virtual Polygon& operator--(int ignoreMe)=0;//postfix decrement
	virtual Polygon& operator++(int ignoreMe)=0;//prefix increment
	friend ostream& operator <<(ofstream& outputStream, Polygon& my_poly);
};

}


#endif