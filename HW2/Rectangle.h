#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;
class Rectangle
{
public:

	Rectangle();
	Rectangle(int my_width, int my_height, double my_x, double my_y);
	inline double get_x() const {return x;}
	inline double get_y() const {return y;}
	inline int get_width() const {return width;}
	inline int get_height() const {return height;}
	void input();
	void set_height_width(int my_width, int my_height);
	void set_positions(double my_x, double my_y);
	void draw(ofstream &fout);

private:
	int height;
	int width;
	double x;
	double y;
};

#endif
