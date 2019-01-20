#ifndef CIRCLE_H_
#define CIRCLE_H_
#include "Shape.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cmath>
#define PI 3.14
using namespace std;
using ShapeNameS::Shape;

namespace CircleleNameS{

//Circle is a derived class from Shape class
class Circle :public Shape
{
public:
	Circle();
	Circle(double my_radius, double my_x, double my_y);
	Circle(double my_x, double my_y);
	Circle(double my_radius);
	inline double get_x() const {return x;}
	inline double get_y() const {return y;}
	inline int get_radius() const {return radius;}  
	void input();
	inline string shapeName() const {return "Circle";}
	void set_radius(double my_radius) throw (int);
	void set_x(double my_x)throw (int); 
	void set_y(double my_y)throw (int);
	double perimeter() const;
	double area() const;
	void draw(ofstream &fout);
	friend ostream& operator <<(ostream& outputStream, const Circle& my_circle);
	Circle& operator++(); //prefix increment
	Circle& operator++(int); //postfix increment
	Circle& operator--(int);//postfix decrement
	Circle& operator--();//prefix decrement
	friend Circle operator+(Circle& my_circle, double num);
	friend Circle operator-(Circle& my_circle, double num);
	static vector<Circle*> new_circles;
	
private:
	double radius;
	double x;
	double y;
	static double total_area;
	static double total_perimeter;

	
};

}

#endif
