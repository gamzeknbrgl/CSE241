#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cmath>
#define PI 3.14
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Polygon.h"

using namespace std;
using PolygonNameS::Polygon;
using RectangleNameS::Rectangle;
using TriangleNameS::Triangle;
using CircleleNameS::Circle;


namespace ComposedShapeNameS{

class ComposedShape
{
public:

	ComposedShape();
	ComposedShape(Rectangle cont_rect, Circle small_circle);
	ComposedShape(Rectangle cont_rect, Rectangle small_rect);
	ComposedShape(Rectangle cont_rect, Triangle small_tri);
	ComposedShape(Triangle cont_tri, Circle small_circle);
	ComposedShape(Triangle cont_tri, Rectangle small_rect);
	ComposedShape(Triangle cont_tri, Triangle small_tri);
	ComposedShape(Circle cont_circle, Circle small_circle);
	ComposedShape(Circle cont_circle, Rectangle small_rect);
	ComposedShape(Circle cont_circle, Triangle small_tri);
	friend ostream& operator <<(ostream& outputStream, const ComposedShape& my_shape);
	ComposedShape operator+=(const ComposedShape &my_shape);
	ComposedShape& operator[]( ComposedShape &my_shape);
	char get_type(){return cont_type;}
	void set_type(char a, char b);
	void draw(ofstream &fout);
	void optimalFit();

private:

	Rectangle my_cont_rect, my_small_rect;
	Circle my_cont_circle, my_small_circle;
	Triangle my_cont_tri, my_small_tri;
	vector<Polygon> my_poly;
	char cont_type;
	char inner_type;

};

}

#endif
