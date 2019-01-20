#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "ComposedShape.h"
using namespace std;

int main(){

	ofstream file;
	int decl;
	decltype(decl) set_radius=40, set_width=60, set_height=40, set_edge=50;
	Circle circle_array[4];
	Rectangle rectangle_array[4];
	Triangle triangle_array[4];
	ComposedShape composed_array[4];

	/*Fill the circle_array objects*/
	for(auto i=0; i<4; i++){
		
		// If you want to enter your own input
		//circle_array[i].input();
		circle_array[i].set_radius(set_radius); //test the set_radius(int my_radius) function  
		circle_array[i].set_x(set_radius); //test the set_x(double my_x) function 
		circle_array[i].set_y(set_radius);// test the set_y(double my_y) function
		set_radius+=50;
		cout<<"For circle "<<i+1<<endl;
		cout<<"Radius is : "<< circle_array[i].get_radius()<<endl; // test the get_radius() function
		cout<<"x is :" <<circle_array[i].get_x()<<endl; // test the get_x() function 
		cout<<"y is :" <<circle_array[i].get_y()<<endl; // test the get_y() function 

	}
	/*Fill the rectangle_array objects*/
	for(auto i=0; i<4; i++){
		
		// If you want to enter your own input
		//rectangle_array[i].input();
		//test the set_height_width(int my_width, int my_height) 
		rectangle_array[i].set_height_width(set_width,set_height); 
		rectangle_array[i].set_positions(0,0); // test the set_positions(double my_x, double my_y)
		set_width+=150;
		set_height+=100;
		cout<<"For rectangle "<<i+1<<endl;
		cout<<"Width is: "<<rectangle_array[i].get_width()<<endl;  //test the get_width() function 
		cout<<"Height is: "<<rectangle_array[i].get_height()<<endl;  //test the get_height() function
		cout<<"x is :" <<rectangle_array[i].get_x()<<endl; //test the get_x() function
		cout<<"y is :"<<rectangle_array[i].get_y()<<endl; //test the get_y() function
	}
	for(auto i=0; i<4; i++){

		// If you want to enter your own input
		//triangle_array[1].input();
		triangle_array[i].set_edge(set_edge); // test the set_edge(int my_edge) function 
		cout<<"For triangle "<<i+1<<endl;
		cout<<"Edge is : "<< triangle_array[i].get_edge()<<endl; // test the get_edge() function 
		// test the set_positions(double my_x, double my_y, double my_z) 
		triangle_array[i].set_positions(0,(set_edge*sqrt(3)/2),0); 
		set_edge+=100;
		cout<<"x is :" <<triangle_array[i].get_x()<<endl; //test the get_x() function
		cout<<"y is :"<<triangle_array[i].get_y()<<endl; //test the get_y() function
		cout<<"z is :"<<triangle_array[i].get_z()<<endl; //test the get_z() function
	}
	/*I can't do the this test part with composed_shape array 
	 *I used objects from arrays of rectangle, circle and triangle to create my own test files.*/

	ComposedShape tempcs(rectangle_array[3],circle_array[0]);
	tempcs.optimalFit();
	tempcs.draw(file);

	ComposedShape tempcs2(rectangle_array[3],rectangle_array[0]);
	tempcs2.optimalFit();
	tempcs2.draw(file);
	
	ComposedShape tempcs3(rectangle_array[3],triangle_array[0]);
	tempcs3.optimalFit();
	tempcs3.draw(file);
	
	ComposedShape tempcs4(circle_array[3],circle_array[0]);
	tempcs4.optimalFit();
	tempcs4.draw(file);
	
	ComposedShape tempcs5(circle_array[3],rectangle_array[0]);
	tempcs5.optimalFit();
	tempcs5.draw(file);
	
	ComposedShape tempcs6(circle_array[3],triangle_array[0]);
	tempcs6.optimalFit();
	tempcs6.draw(file);
	
	ComposedShape tempcs7(triangle_array[3],circle_array[0]);
	tempcs7.optimalFit();
	tempcs7.draw(file);
	
	ComposedShape tempcs8(triangle_array[3],rectangle_array[0]);
	tempcs8.optimalFit();
	tempcs8.draw(file);
	
	ComposedShape tempcs9(triangle_array[3],triangle_array[1]);
	tempcs9.optimalFit();
	tempcs9.draw(file);
	
	return 0;
}
