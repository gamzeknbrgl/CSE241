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
using namespace std;
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
	vector<Rectangle> get_inner_rect() {return inner_rect;}
	vector<Triangle> get_inner_tri() {return inner_tri;}
	vector<Circle> get_inner_circle() {return inner_circle;}
	friend ostream& operator <<(ostream& outputStream, const ComposedShape& my_shape);
	ComposedShape operator+=(const ComposedShape &my_shape);
	ComposedShape& operator[]( ComposedShape &my_shape);
	char get_type(){return cont_type;}
	void set_type(char a, char b);
	void draw(ofstream &fout);
	void optimalFit();
	class ShapeElem {

	public:
		enum class Shapes{Rectangle, Triangle, Circle};
		ShapeElem();
		ShapeElem(void *s, char type);
		inline double get_area() const {return my_area;}
		inline double get_perimeter() const {return my_perimeter;}
		friend ostream& operator <<(ostream& outputStream, void *s);
		double area(void *s);
		double perimeter(void *s);
		void draw(ofstream &fout, void *s, char type);
		

	private:

		void *shape;
		Shapes types;
		double my_area;
		double my_perimeter;
	};
	ShapeElem my_shape;

private:
	Rectangle my_cont_rect, my_small_rect;
	Circle my_cont_circle, my_small_circle;
	Triangle my_cont_tri, my_small_tri;
	vector<Rectangle> inner_rect;
	vector<Triangle> inner_tri;
	vector<Circle> inner_circle;
	vector<ShapeElem> inner_shapes;
	char cont_type;
	char inner_type;
	void *cont;
	void *inner;

};

#endif
