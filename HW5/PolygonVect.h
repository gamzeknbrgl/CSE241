#ifndef POLYGONVECT_H_
#define POLYGONVECT_H_
#include "Polygon.h"
#include <vector>
using namespace std;

using RectangleNameS::Rectangle;
using TriangleNameS::Triangle;
using CircleleNameS::Circle;
using ShapeNameS::Shape;
using PolygonNameS::Polygon;

class PolygonVect: public Polygon{

public:

	PolygonVect();
	PolygonVect(Triangle my_tri);
	PolygonVect(Rectangle my_rect);
	PolygonVect(Circle my_circle);
	void draw(ofstream &fout);
	PolygonVect(vector<Point2D> &my_points);
	PolygonVect& operator++();//prefix increment
	PolygonVect& operator--();//prefix decrement
	PolygonVect& operator--(int ignoreMe);//postfix decrement
	PolygonVect& operator++(int ignoreMe);//prefix increment
	double area() const;
	double perimeter() const; 
	static vector<PolygonVect*> new_vects;

private:

	vector <Polygon::Point2D> points_2D; 
	
};

#endif