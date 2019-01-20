#ifndef CIRCLE_H_
#define CIRCLE_H_
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

class Circle
{
public:
	Circle();
	Circle(int radius, double my_x, double my_y);
	inline double get_x() const {return x;}
	inline double get_y() const {return y;}
	inline int get_radius() const {return radius;}
	void input();
	void set_radius(int my_radius);
	void set_x(double my_x);
	void set_y(double my_y);
	
	void draw(ofstream &fout);
private:
	int radius;
	double x;
	double y;
};

#endif
