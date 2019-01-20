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

	ofstream user_test, file1, file2, file3, file4, file5,file6, file7,file8, file9;
	double area, perimeter;
	int decl;
	decltype(decl) set_radius=40, set_width=60, set_height=40, set_edge=50;
	Circle circle_array[4], c1,c2;
	Rectangle rectangle_array[4],r1, r2;
	Triangle triangle_array[4],t1,t2;
	ComposedShape composed_array[4];
	
	char cont_shape, small_shape;


	cout<<"MY TEST part" <<endl;
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
		area= Circle::total_area_f(circle_array[i]);
		perimeter=Circle::total_perimeter_f(circle_array[i]);
	}
	cout<<"Static function tests for Circle Array" <<endl;
	cout<<"Total area: " <<area <<endl;
	cout<<"Total perimeter: " <<perimeter <<endl;
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
		area= Rectangle::total_area_f(rectangle_array[i]);
		perimeter=Rectangle::total_perimeter_f(rectangle_array[i]);
	}
	cout<<"Static function tests for Rectangle Array" <<endl;
	cout<<"Total area: " <<area <<endl;
	cout<<"Total perimeter: " <<perimeter <<endl;
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
		area= Triangle::total_area_f(triangle_array[i]);
		perimeter=Triangle::total_perimeter_f(triangle_array[i]);
	}

	cout<<"Static function tests for Triangle Array" <<endl;
	cout<<"Total area: " <<area <<endl;
	cout<<"Total perimeter: " <<perimeter <<endl;

	cout<<"Testing operator overloading for Circle class"<<endl;
	cout<<"Before increment  "<< "x: " <<circle_array[0].get_x()<< "y: " << circle_array[0].get_y()<<endl;
	circle_array[0]++;
	cout<<"After:"<< "x: " <<circle_array[0].get_x()<< "y: " << circle_array[0].get_y()<<endl;

	cout<<"Before decrement  "<< "x: " <<circle_array[0].get_x()<< "y: " << circle_array[0].get_y()<<endl;
	--circle_array[0];
	cout<<"After:"<< "x: " <<circle_array[0].get_x()<< "y: " << circle_array[0].get_y()<<endl;

	cout<<"== , =! test & also area test"<<endl;
	if(circle_array[0]!=circle_array[1]){
		cout<<"not equal circles, circle 1's area:" << circle_array[0].circle_area(circle_array[0].get_radius())<<endl;
		cout<<"not equal circles, circle 2's area:" << circle_array[1].circle_area(circle_array[1].get_radius())<<endl;
	}
	if(circle_array[0]==circle_array[0]){
		cout<<" equal circles, circle 1's area:" << circle_array[0].circle_area(circle_array[0].get_radius())<<endl;
		cout<<"equal circles, circle 2's area:" << circle_array[0].circle_area(circle_array[0].get_radius())<<endl;
	}
	cout<<"+ , - test"<<endl;
	cout<<"Before +2"<<circle_array[0].get_radius()<<endl;
	circle_array[0]+2;
	cout<<"After +2"<<circle_array[0].get_radius()<<endl;

	cout<<"Before -2"<<circle_array[0].get_radius()<<endl;
	circle_array[0]-2;
	cout<<"After -2"<<circle_array[0].get_radius()<<endl;


	cout<<"Testing operator overloading for Rectangle class"<<endl;
	cout<<"Before increment  "<< "x: " <<circle_array[0].get_x()<< "y: " << circle_array[0].get_y()<<endl;
	rectangle_array[0]++;
	cout<<"After:"<< "x: " <<rectangle_array[0].get_x()<< "y: " << rectangle_array[0].get_y()<<endl;

	cout<<"Before decrement  "<< "x: " <<rectangle_array[0].get_x()<< "y: " << rectangle_array[0].get_y()<<endl;
	--rectangle_array[0];
	cout<<"After:"<< "x: " <<rectangle_array[0].get_x()<< "y: " << rectangle_array[0].get_y()<<endl;

	cout<<"== , =! test & also area test"<<endl;
	if(rectangle_array[0]!=rectangle_array[0]){
		cout<<"not equal rects"<< endl;
		
	}
	if(rectangle_array[0]==rectangle_array[0]){
		cout<<" equal rects"<<endl;
	}
	cout<<"+ , - test"<<endl;
	cout<<"Before +2 width"<<rectangle_array[0].get_width()<<endl;
	cout<<"Before +2 height:"<<rectangle_array[0].get_height()<<endl;
	rectangle_array[0]+2;
	cout<<"After +2 width "<<rectangle_array[0].get_width()<<endl;
	cout<<"After +2 height:"<<rectangle_array[0].get_height()<<endl;
	cout<<"Before -2 width"<<rectangle_array[0].get_width()<<endl;
	cout<<"Before -2 height:"<<rectangle_array[0].get_height()<<endl;
	rectangle_array[0]-2;
	cout<<"After -2 width "<<rectangle_array[0].get_width()<<endl;
	cout<<"After -2 height:"<<rectangle_array[0].get_height()<<endl;

	cout<<"Testing operator overloading for Triangle class"<<endl;
	cout<<"Before increment  "<< "x: " <<triangle_array[0].get_x()<< "y: " << triangle_array[0].get_y()<<endl;
	triangle_array[0]++;
	cout<<"After:"<< "x: " <<triangle_array[0].get_x()<< "y: " << triangle_array[0].get_y()<<endl;

	cout<<"Before decrement  "<< "x: " <<triangle_array[0].get_x()<< "y: " << triangle_array[0].get_y()<<endl;
	--triangle_array[0];
	cout<<"After:"<< "x: " <<triangle_array[0].get_x()<< "y: " << triangle_array[0].get_y()<<endl;

	cout<<"== , =! test & also area test"<<endl;
	if(triangle_array[0]!=triangle_array[0]){
		cout<<"not equal triangles"<< endl;
		
	}
	if(triangle_array[0]==triangle_array[0]){
		cout<<" equal rects"<<endl;
	}
	cout<<"+ , - test"<<endl;
	cout<<"Before +2 edge "<<triangle_array[0].get_edge()<<endl;
	triangle_array[0]+2;
	cout<<"After +2 edge:"<<triangle_array[0].get_edge()<<endl;
	cout<<"Before -2 edge "<<triangle_array[0].get_edge()<<endl;
	triangle_array[0]-2;
	cout<<"After -2 edge:"<<triangle_array[0].get_edge()<<endl;


	/*I can't do the this test part with composed_shape array 
	 *I used objects from arrays of rectangle, circle and triangle to create my own test files.*/

	ComposedShape tempcs(rectangle_array[3],circle_array[0]);
	tempcs.optimalFit();
	file1.open("output.svg");
	tempcs.draw(file1);
	file1.close();

	cout<<"composed shape << test"<<endl;
	cout<<tempcs<<endl;

	ComposedShape tempcs2(rectangle_array[3],rectangle_array[0]);
	tempcs2.optimalFit();
	file2.open("output2.svg");
	tempcs2.draw(file2);
	file2.close();
	
	ComposedShape tempcs3(rectangle_array[3],triangle_array[0]);
	tempcs3.optimalFit();
	file3.open("output3.svg");
	tempcs3.draw(file3);
	file3.close();
	
	ComposedShape tempcs4(circle_array[3],circle_array[0]);
	tempcs4.optimalFit();
	file4.open("output4.svg");
	tempcs4.draw(file4);
	file4.close();
	
	ComposedShape tempcs5(circle_array[3],rectangle_array[0]);
	tempcs5.optimalFit();
	file5.open("output5.svg");
	tempcs5.draw(file5);
	file5.close();
	
	ComposedShape tempcs6(circle_array[3],triangle_array[0]);
	tempcs6.optimalFit();
	file6.open("output6.svg");
	tempcs6.draw(file6);
	file6.close();
	
	ComposedShape tempcs7(triangle_array[3],circle_array[0]);
	tempcs7.optimalFit();
	file7.open("output7.svg");
	tempcs7.draw(file7);
	file7.close();
	
	ComposedShape tempcs8(triangle_array[3],rectangle_array[0]);
	tempcs8.optimalFit();
	file8.open("output8.svg");
	tempcs8.draw(file8);
	file8.close();
	
	ComposedShape tempcs9(triangle_array[3],triangle_array[1]);
	tempcs9.optimalFit();
	file9.open("output9.svg");
	tempcs9.draw(file9);
	file9.close();

	cout<<"END OF MY TEST"<<endl;

	cout<<"USER TEST"<<endl;
	user_test.open("user_test.svg");
	while (1){
	cout<<"Enter the container shape:"<<endl;
	cin>>cont_shape;
		if(cont_shape!='R' && cont_shape!='T' && cont_shape!='C' && cont_shape!='r' && cont_shape!='t' && cont_shape!='c' ){

			cout<<"Container shape must be T or R or C"<<endl;

		}
		 if(cont_shape=='R' || cont_shape=='T' || cont_shape=='C' || cont_shape=='r' || cont_shape=='t' || cont_shape=='c')

			break;
	}
	while(1){
	cout<<"Enter the small shape" <<endl,
	cin>>small_shape;
		if(small_shape!='R' && small_shape!='T' && small_shape!='C' && small_shape!='r' && small_shape!='t' && small_shape!='c'){

		cout<<"Small shape must be T or R or C"<<endl;
		}

		if(small_shape=='R' || small_shape=='T' || small_shape=='C' || small_shape=='r' || small_shape=='t' || small_shape=='c')

			break;
	}
	if((cont_shape=='R' || cont_shape=='r') && ( small_shape=='c' || small_shape=='C')){
			
			r1.input();
			c1.input();
			ComposedShape cs1(r1,c1);
			cs1.optimalFit();
			cs1.draw(user_test);
	}

	else if((cont_shape=='R' || cont_shape=='r') && ( small_shape=='t' || small_shape=='T')){
			
			r1.input();
			t1.input();
			ComposedShape cs2(r1,t1);
			cs2.optimalFit();
			cs2.draw(user_test);
	}
	else if((cont_shape=='R' || cont_shape=='r') && ( small_shape=='r' || small_shape=='R')){
			
			r1.input();
			r2.input();
			ComposedShape cs3(r1,r2);
			cs3.optimalFit();
			cs3.draw(user_test);
	}
	else if((cont_shape=='T' || cont_shape=='t') && ( small_shape=='c' || small_shape=='C')){
			
			t1.input();
			c1.input();
			ComposedShape cs4(t1,c1);
			cs4.optimalFit();
			cs4.draw(user_test);
	}
	else if((cont_shape=='T' || cont_shape=='t') && ( small_shape=='r' || small_shape=='R')){
			
			t1.input();
			r1.input();
			ComposedShape cs5(t1,r1);
			cs5.optimalFit();
			cs5.draw(user_test);
	}
	else if((cont_shape=='T' || cont_shape=='t') && ( small_shape=='T' || small_shape=='t')){
			
			t1.input();
			t2.input();
			ComposedShape cs6(t1,t2);
			cs6.optimalFit();
			cs6.draw(user_test);
	}
	else if((cont_shape=='C' || cont_shape=='c') && ( small_shape=='T' || small_shape=='t')){
			
			c1.input();
			t1.input();
			ComposedShape cs7(c1,t1);
			cs7.optimalFit();
			cs7.draw(user_test);
	}
	else if((cont_shape=='C' || cont_shape=='c') && ( small_shape=='r' || small_shape=='R')){
			
			c1.input();
			r1.input();
			ComposedShape cs8(c1,r1);
			cs8.optimalFit();
			cs8.draw(user_test);
	}
	else if((cont_shape=='C' || cont_shape=='c') && ( small_shape=='c' || small_shape=='C')){
			
			c1.input();
			c2.input();
			ComposedShape cs9(c1,c2);
			cs9.optimalFit();
			cs9.draw(user_test);
	}

	user_test.close();


	


	return 0;
}
