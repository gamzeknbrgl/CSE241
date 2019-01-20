#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include "Shape.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;
using ShapeNameS::Shape;

namespace RectangleNameS{
	
//Rectangle is a derived class from Shape class
class Rectangle : public Shape
{
public:

	Rectangle();
	Rectangle(double my_width, double my_height, double my_x, double my_y);
	Rectangle(double my_x, double my_y);
	inline double get_x() const {return x;}
	inline double get_y() const {return y;}
	inline int get_width() const {return width;}
	inline int get_height() const {return height;}
	inline string shapeName() const {return "Rectangle";}
	void input();
	void set_height_width(double my_width, double my_height)throw (int, int);
	void set_positions(double my_x, double my_y)throw (int, int);
	void draw(ofstream &fout);
	double perimeter() const;
	double area() const ;
	friend ostream& operator <<(ostream& outputStream, const Rectangle& my_rect);
	Rectangle& operator++(); //prefix increment
	Rectangle& operator++(int); //postfix increment
	Rectangle& operator--(int);//postfix decrement
	Rectangle& operator--();//prefix decrement
	friend Rectangle operator+(Rectangle& my_rect, double num);
	friend Rectangle operator-(Rectangle& my_rect, double num);
	static vector<Rectangle*> new_rects;

private:
	double height;
	double width;
	double x;
	double y;
	static double total_area;
	static double total_perimeter;
};

}
#endif
