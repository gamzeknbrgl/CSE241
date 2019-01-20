#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

class Triangle
{
public:

	Triangle();
	Triangle(double my_edge, double my_x, double my_y, double my_z);
	Triangle(double my_x, double my_y, double my_z);
	inline double get_x() const {return x;}
	inline double get_y() const {return y;}
	inline double get_z() const {return z;}
	inline int get_edge() const {return edge;}
	void input();
	void set_edge(double my_edge);
	void set_positions(double my_x, double my_y, double my_z);
	double tri_perimeter(double tri_edge) const;
	double tri_area(double tri_edge) const;
	void draw(ofstream &fout, const Triangle& my_tri);
	friend ostream& operator <<(ostream& outputStream, const Triangle& my_tri);
	friend bool operator ==(const Triangle& my_tri1, const Triangle& my_tri2);
	friend bool operator !=(const Triangle& my_tri1, const Triangle& my_tri2);
	Triangle operator++(); //prefix increment
	Triangle operator++(int); //postfix increment
	Triangle operator--(int);//postfix decrement
	Triangle operator--();//prefix decrement
	friend Triangle operator+(Triangle& my_tri, double num);
	friend Triangle operator-(Triangle& my_tri, double num);
	static double total_area_f(Triangle &my_tri);
	static double total_perimeter_f(Triangle &my_tri);


private:
	double edge;
	double x;
	double y;
	double z;
	static double total_area;
	static double total_perimeter;
};

#endif
