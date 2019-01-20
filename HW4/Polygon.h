#ifndef POLYGON_H_
#define POLYGON_H_
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cmath>
#define PI 3.14
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
using namespace std;

using RectangleNameS::Rectangle;
using TriangleNameS::Triangle;
using CircleleNameS::Circle;

namespace PolygonNameS{

class Polygon{

public:

	Polygon();
	
	Polygon(Triangle my_tri);
	Polygon(Rectangle my_rect);
	Polygon(Circle my_circle);
	friend bool operator ==(const Polygon& my_poly1, const Polygon& my_poly2);
	friend bool operator !=(const Polygon& my_poly1, const Polygon& my_poly2);
	friend ostream& operator <<(ostream& outputStream, const Polygon& my_poly);
	inline int get_vert() const {return vertices;}
	//big three
	~Polygon(); //destructor
	Polygon(const Polygon &my_poly); //copy constructor
	Polygon& operator=(const Polygon& my_poly);
	void set_vertices(int vert);

	class Point2D{

	public:
		Point2D();
		Point2D(double my_x, double my_y);
		void set_x(double my_x);
		void set_y(double my_y);
		inline double get_x() const {return x;}
		inline double get_y() const {return y;}

	private:

		double x;
		double y;
	};
	Polygon(const Point2D &my_point);
	Polygon(int vert, Point2D *a);
	inline Point2D *get_array() const {return points_2D;}
	Point2D &operator[](int index);
	Polygon(vector<Point2D> my_points);
	friend Polygon operator+(Polygon& my_poly1, Polygon& my_poly2);

private:

	Point2D *points_2D;
	int vertices;
};

}


#endif