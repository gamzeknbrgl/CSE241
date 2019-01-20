#ifndef POLYGONDYN_H_
#define POLYGONDYN_H_
#include "Polygon.h"
using namespace std;

using RectangleNameS::Rectangle;
using TriangleNameS::Triangle;
using CircleleNameS::Circle;
using ShapeNameS::Shape;
using PolygonNameS::Polygon;


class PolygonDyn: public Polygon{

public:

	PolygonDyn();
	PolygonDyn(Triangle my_tri);
	PolygonDyn(Rectangle my_rect);
	PolygonDyn(Circle my_circle);
	inline int get_vert() const {return vertices;}
	void draw(ofstream &fout);
	~PolygonDyn(); //destructor
	PolygonDyn(const PolygonDyn &my_poly); //copy constructor
	PolygonDyn& operator=(const PolygonDyn& my_poly);
	void set_vertices(int vert);
	inline Point2D *get_array() const {return points_2D;}
	PolygonDyn(vector<Point2D> &my_points);
	PolygonDyn& operator++();//prefix increment
	PolygonDyn& operator--();//prefix decrement
	PolygonDyn& operator--(int ignoreMe);//postfix decrement
	PolygonDyn& operator++(int ignoreMe);//prefix increment
	double area() const;
	double perimeter() const; 
	static vector<PolygonDyn*> new_dyns;

private:

	Polygon::Point2D *points_2D;
	int vertices;

};


#endif