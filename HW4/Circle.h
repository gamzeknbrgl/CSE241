#ifndef CIRCLE_H_
#define CIRCLE_H_
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cmath>
#define PI 3.14
using namespace std;

namespace CircleleNameS{

class Circle
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
	void set_radius(double my_radius);
	void set_x(double my_x);
	void set_y(double my_y);
	double circle_perimeter(double circ_radius) const;
	double circle_area(double circ_radius) const;
	void draw(ofstream &fout, const Circle& my_circle);
	friend ostream& operator <<(ostream& outputStream, const Circle& my_circle);
	friend bool operator ==(const Circle& my_circle1, const Circle& my_circle2);
	friend bool operator !=(const Circle& my_circle1, const Circle& my_circle2);
	Circle operator++(); //prefix increment
	Circle operator++(int); //postfix increment
	Circle operator--(int);//postfix decrement
	Circle operator--();//prefix decrement
	friend Circle operator+(Circle& my_circle, double num);
	friend Circle operator-(Circle& my_circle, double num);
	double area;
	double perimeter;
	
private:
	double radius;
	double x;
	double y;
	static double total_area;
	static double total_perimeter;
	
};

}

#endif
