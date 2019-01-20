#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include "Shape.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;
using ShapeNameS::Shape;

namespace TriangleNameS{

//Triangle is a derived class from Shape class
class Triangle : public Shape
{
public:

	Triangle();
	Triangle(double my_edge, double my_x, double my_y, double my_z);
	Triangle(double my_x, double my_y, double my_z);
	inline double get_x() const {return x;}
	inline double get_y() const {return y;}
	inline double get_z() const {return z;}
	inline int get_edge() const {return edge;}
	inline string shapeName() const {return "Triangle";}
	void input();
	void set_edge(double my_edge) throw (int);
	void set_positions(double my_x, double my_y, double my_z) throw (int, int, int);
	double perimeter() const;
	double area() const;
	void draw(ofstream &fout);
	friend ostream& operator <<(ostream& outputStream, const Triangle& my_tri);
	Triangle& operator++(); //prefix increment
	Triangle& operator++(int); //postfix increment
	Triangle& operator--(int);//postfix decrement
	Triangle& operator--();//prefix decrement
	friend Triangle operator+(Triangle& my_tri, double num);
	friend Triangle operator-(Triangle& my_tri, double num);
	static vector<Triangle*> new_tri;

private:
	double edge;
	double x;
	double y;
	double z;
	static double total_area;
	static double total_perimeter;
};


}
#endif
