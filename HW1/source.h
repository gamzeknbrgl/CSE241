#include <iostream>
#include <fstream>
#include <cmath>
#ifndef SOURCE_H_
#define SOURCE_H_
void choose_shapes();
void circle_in_rectangle(int height, int width, int radius);
void rectangle_in_rectangle(int height,int width,int small_height,int small_width);
void triangle_in_rectangle(int height,int width,int edge);
void circle_in_circle(int radius, int small_radius);
void rectangle_in_circle(int radius, int height, int width);
void triangle_in_circle(int radius, int edge);
void circle_in_triangle(int edge, int radius);
void rectangle_in_triangle(int edge, int height,int width);
void triangle_in_triangle(int edge, int small_edge);



#endif 
