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
	Triangle(int edge, double my_x, double my_y, double my_z);
	inline double get_x() const {return x;}
	inline double get_y() const {return y;}
	inline double get_z() const {return z;}
	inline int get_edge() const {return edge;}
	void input();
	void set_edge(int my_edge);
	void set_positions(double my_x, double my_y, double my_z);
	void draw(ofstream &fout);
private:
	int edge;
	double x;
	double y;
	double z;
};

#endif
