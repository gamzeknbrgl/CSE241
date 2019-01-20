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
	Rectangle(double my_width, double my_height, double my_x, double my_y);
	Rectangle(double my_x, double my_y);
	inline double get_x() const {return x;}
	inline double get_y() const {return y;}
	inline int get_width() const {return width;}
	inline int get_height() const {return height;}
	void input();
	void set_height_width(double my_width, double my_height);
	void set_positions(double my_x, double my_y);
	void draw(ofstream &fout, const Rectangle& my_rect);
	double rect_perimeter(double my_width, double my_height) const;
	double rect_area(double my_width, double my_height) const;
	friend ostream& operator <<(ostream& outputStream, const Rectangle& my_rect);
	friend bool operator ==(const Rectangle& my_rect1, const Rectangle& my_rect2);
	friend bool operator !=(const Rectangle& my_rect1, const Rectangle& my_rect2);
	Rectangle operator++(); //prefix increment
	Rectangle operator++(int); //postfix increment
	Rectangle operator--(int);//postfix decrement
	Rectangle operator--();//prefix decrement
	friend Rectangle operator+(Rectangle& my_rect, double num);
	friend Rectangle operator-(Rectangle& my_rect, double num);
	static double total_area_f(Rectangle &my_rect);
	static double total_perimeter_f(Rectangle &my_rect);

private:
	double height;
	double width;
	double x;
	double y;
	static double total_area;
	static double total_perimeter;
};

#endif
