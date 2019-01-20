#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "ComposedShape.h"
#include "Polygon.h"
#include "Shape.h"
#include "PolygonDyn.h"
#include "PolygonVect.h"

void printAll(const vector<Shape*> &shapeVect, ofstream &fout);
bool helper(const Shape* a, const Shape* b);
void sortShapes(const vector<Shape*> &shapeVect);
vector <Polygon*> convertAll(vector <Shape*> shapeVect);
void printPoly(const vector<Shape*> shapeVect, ofstream &fout);
/* Global printAll function takes a vector 
* of Shape pointers and prints all shapes to an SVG file */
void printAll(const vector<Shape*> &shapeVect, ofstream &fout){

	for (auto i=0; i<shapeVect.size(); i++){

		fout<<*shapeVect[i];
	}
	
}
/* Global sortShapes takes a vector of Shape pointers
* and increasingly sorts them with respect to their areas. */
void sortShapes(const vector<Shape*> &shapeVect){

	vector<Shape*> sortVector;
	cout<<"\nBefore sorting\n"<<endl;

	for (auto i=0; i<shapeVect.size(); i++){
		cout<<shapeVect[i]->shapeName()<<endl;
		for(auto j=i+1; j<shapeVect.size(); j++){

			
			if(shapeVect[i]>shapeVect[j]){

				if(i==0 && j==1){
					sortVector.push_back(shapeVect[j]);
					sortVector.push_back(shapeVect[i]);
				}
				else{
					sortVector.pop_back();
					sortVector.push_back(shapeVect[j]);
					sortVector.push_back(shapeVect[i]);
				}
			}	
		}
	}
	cout<<"\nAfter sorting\n "<<endl;
	for (auto i=0; i<sortVector.size(); i++){

			cout<<sortVector[i]->shapeName()<<endl;
	}

}
/* Global convertAll function takes a vector of Shape pointers, 
*converts all shapes to Polygons and returns a new vector with the new shapes.*/ 
vector <Polygon*> convertAll(vector <Shape*> shapeVect){

	vector<Polygon*> poly;
	PolygonVect *ptr;
    for (auto i=0; i<shapeVect.size(); i++){

        if(shapeVect[i]->shapeName()=="Rectangle")
    
            ptr = new PolygonVect(*dynamic_cast<Rectangle *>(shapeVect[i]));
            	
        else if(shapeVect[i]->shapeName()=="Triangle")
           
            ptr = new PolygonVect(*dynamic_cast<Triangle *>(shapeVect[i]));
            	
        else if (shapeVect[i]->shapeName()=="Circle")

            ptr= new PolygonVect(*dynamic_cast<Circle *>(shapeVect[i]));
            	
   		 poly.push_back(ptr);
    }

    return poly;
}
/*Global printPoly function takes a vector of Shape pointers 
*and prints all Polygon shapes to an SVG file */
void printPoly(const vector<Shape*> shapeVect, ofstream &fout){

	vector<Polygon*> new_vect;
	new_vect=convertAll(shapeVect);
	for (auto i=0; i<new_vect.size(); i++){

		fout<<*new_vect[i];
	}

}

int main(){

	using std::cout;
	using std::cin;
	using std::endl;
	using PolygonNameS::Polygon;
	using RectangleNameS::Rectangle;
	using TriangleNameS::Triangle;
	using CircleleNameS::Circle;
	using ComposedShapeNameS::ComposedShape;
	using ShapeNameS::Shape;
	
	ofstream user_test, CStest1, CStest2, CStest3, CStest4, CStest5,CStest6, CStest7,CStest8, CStest9;
	ofstream file1, file2, file3, file4, file5, file6, file7, file8, file9, file10, file11,file12;
	int decl;
	decltype(decl) set_radius=40, set_width=60, set_height=40, set_edge=50, circle_counter, rect_count, tri_count;
	decltype(decl) vect_count, dyn_count;
	try {
	Circle circle_array[4];
	Rectangle rectangle_array[4];
	Triangle triangle_array[4];
	ComposedShape composed_array[5];
	/*Fill the circle_array objects*/
	for(auto i=0; i<4; i++){
		
		circle_array[i].set_radius(set_radius); //test the set_radius(int my_radius) function  
		circle_array[i].set_x(set_radius); //test the set_x(double my_x) function 
		circle_array[i].set_y(set_radius);// test the set_y(double my_y) function
		set_radius+=50;

	}
	/*Fill the rectangle_array objects*/
	for(auto i=0; i<4; i++){
		
		rectangle_array[i].set_height_width(set_width,set_height); 
		rectangle_array[i].set_positions(0,0); // test the set_positions(double my_x, double my_y)
		set_width+=150;
		set_height+=100;
	
	}
	for(auto i=0; i<4; i++){

		triangle_array[i].set_edge(set_edge); // test the set_edge(int my_edge) function  
		triangle_array[i].set_positions(0,(set_edge*sqrt(3)/2),0); 
		set_edge+=100;
	
	}
	
	cout<<"TEST PART FOR COMPOSED SHAPE CLASS"<<endl;

	composed_array[0]=ComposedShape(rectangle_array[3], circle_array[0]);
	composed_array[0].optimalFit();
	cout<<composed_array[0];
	CStest1.open("CStest1.svg");
	composed_array[0].draw(CStest1);
	CStest1.close();
	cout<<"\n";

	composed_array[1]=ComposedShape(rectangle_array[3],rectangle_array[0]);
	composed_array[1].optimalFit();
	cout<<composed_array[1];
	CStest2.open("CStest2.svg");
	composed_array[1].draw(CStest2);
	CStest2.close();
	cout<<"\n";

	composed_array[2]=ComposedShape(rectangle_array[3],triangle_array[0]);
	composed_array[2].optimalFit();
	cout<<composed_array[2];
	CStest3.open("CStest3.svg");
	composed_array[2].draw(CStest3);
	CStest3.close();
	cout<<"\n";

	composed_array[3]=ComposedShape(circle_array[3],circle_array[0]);
	composed_array[3].optimalFit();
	cout<<composed_array[3];
	CStest4.open("CStest4.svg");
	composed_array[3].draw(CStest4);
	CStest4.close();
	cout<<"\n";

	composed_array[4]=ComposedShape(circle_array[3],rectangle_array[0]);
	composed_array[4].optimalFit();
	cout<<composed_array[4];
	CStest5.open("CStest5.svg");
	composed_array[4].draw(CStest5);
	CStest5.close();
	cout<<"\n";
	
	composed_array[0]=ComposedShape(circle_array[3],triangle_array[0]);
	composed_array[0].optimalFit();
	cout<<composed_array[0];
	CStest6.open("CStest6.svg");
	composed_array[0].draw(CStest6);
	CStest6.close();
	cout<<"\n";

	composed_array[1]=ComposedShape(triangle_array[3],circle_array[0]);
	composed_array[1].optimalFit();
	cout<<composed_array[1];
	CStest7.open("CStest7.svg");
	composed_array[1].draw(CStest7);
	CStest7.close();
	cout<<"\n";

	composed_array[2]=ComposedShape(triangle_array[3],rectangle_array[0]);
	composed_array[2].optimalFit();
	cout<<composed_array[2];
	CStest8.open("CStest8.svg");
	composed_array[2].draw(CStest8);
	CStest8.close();
	cout<<"\n";

	composed_array[3]=ComposedShape(triangle_array[3],triangle_array[1]);
	composed_array[3].optimalFit();
	cout<<composed_array[3];
	CStest9.open("CStest9.svg");
	composed_array[3].draw(CStest9);
	CStest9.close();
	cout<<"\n";

	cout<<"END OF TEST PART FOR COMPOSED SHAPE CLASS \n"<<endl;

	cout<<"TEST PART FOR POLYGONDYN & POLYGONVECT\n"<<endl;

	vector<PolygonDyn::Point2D> test_poly3;
	PolygonDyn::Point2D a1(0,200);
	test_poly3.push_back(a1);
	PolygonDyn::Point2D b1(100,125);
	test_poly3.push_back(b1);
	PolygonDyn::Point2D c1(100,200);
	test_poly3.push_back(c1);
	PolygonDyn::Point2D d1(200,0);
	test_poly3.push_back(d1);
	file5.open("PolygonDynTest.svg");
	file5<< "<svg height=\"300\" width=\"300\">"<<endl;
	PolygonDyn l(test_poly3);
	l.draw(file5);
	file5 << "</svg>" << endl;
	file5.close();

	vector<PolygonVect::Point2D> test_poly;
	PolygonVect::Point2D a(100,10);
	test_poly.push_back(a);
	PolygonVect::Point2D b(40,198);
	test_poly.push_back(b);
	PolygonVect::Point2D c(190,78);
	test_poly.push_back(c);
	PolygonVect::Point2D d(10,78);
	test_poly.push_back(d);
	PolygonVect::Point2D e(160,198);
	test_poly.push_back(e);
	file2.open("PolygonVectTest.svg");
	file2<< "<svg height=\"210\" width=\"500\">"<<endl;
	PolygonVect vect2(test_poly);
	vect2.draw(file2);
	file2 << "</svg>" << endl;
	file2.close();

	PolygonVect vect;
	Rectangle test2(400,200,0,0);
	vect=PolygonVect(test2);
	file3.open("PolygonVectTest2.svg");
	file3<< "<svg height=\"210\" width=\"500\">"<<endl;
	vect.draw(file3);
	file3 << "</svg>" << endl;
	file3.close();
	cout<<"PolygonVectTest2's perimeter:"<<vect.perimeter()<<endl;
	cout<<"PolygonVectTest2's area:"<<vect.area()<<endl;
	cout<<"Test two PolygonVect's are equal or not"<<endl;
	if(vect!=vect2){
		cout<<"Two polygons are not equal, because polygon 1's area:"<<vect.area()<<endl;
		cout<<" polygon 2's area: "<<vect2.area()<<endl;
	}

	PolygonDyn dyn2;
	Circle test3(200,200,200);
	dyn2=PolygonDyn(test3);
	file4.open("PolygonDynTest2.svg");
	file4<< "<svg height=\"400\" width=\"400\">"<<endl;
	dyn2.draw(file4);
	file4 << "</svg>" << endl;
	file4.close();
	cout<<"PolygonDynTest2's perimeter:"<<dyn2.perimeter()<<endl;
	cout<<"PolygonDynTest2's area:"<<dyn2.area()<<endl;
	cout<<"\nEND OF TEST PART FOR POLYGONDYN & POLYGONVECTS \n"<<endl;

	cout<<"TEST PART FOR SHAPE CLASS OPERATORS"<<endl;
	
	cout<<"\n Test operators for CIRCLE :"<<endl;
	cout<<"Before increment (postfix)  "<< "x:" <<circle_array[0].get_x()<< "y:" << circle_array[0].get_y()<<endl;
	circle_array[0]++;
	cout<<"After:"<< "x: " <<circle_array[0].get_x()<< "y:" << circle_array[0].get_y()<<endl;

	cout<<"Before decrement (prefix)  "<< "x:" <<circle_array[0].get_x()<<" "<< "y:" << circle_array[0].get_y()<<endl;
	--circle_array[0];
	cout<<"After:"<< "x:" <<circle_array[0].get_x()<<" "<< "y:" << circle_array[0].get_y()<<endl;

	cout<<"== , =! test & also area test"<<endl;
	if(circle_array[0]!=circle_array[1]){
		cout<<"not equal circles, circle 1's area:" << circle_array[0].area();
		cout<<" "<<"circle 2's area:" << circle_array[1].area()<<endl;
	}
	if(circle_array[0]==circle_array[0]){
		cout<<"equal circles, circle 1's area:" << circle_array[0].area();
		cout<<" "<<" circle 2's area:" << circle_array[0].area()<<endl;
	}
	cout<<"\n Test operators for RECTANGLE :"<<endl;
	cout<<"Before increment(postfix)  "<< "x:" <<rectangle_array[0].get_x()<<" "<< "y:" << rectangle_array[0].get_y()<<endl;
	rectangle_array[0]++;
	cout<<"After: "<< "x:" <<rectangle_array[0].get_x()<<" "<< "y:" << rectangle_array[0].get_y()<<endl;

	cout<<"Before decrement (prefix) "<< "x:" <<rectangle_array[0].get_x()<<" "<< "y:" << rectangle_array[0].get_y()<<endl;
	--rectangle_array[0];
	cout<<"After:"<< "x: " <<rectangle_array[0].get_x()<<" " <<"y:" << rectangle_array[0].get_y()<<endl;

	cout<<"== , =! test & also area test"<<endl;
	if(rectangle_array[0]!=rectangle_array[1]){
		cout<<"not equal rectangles, rectangle 1's area:"<<rectangle_array[0].area();
		cout<<" rectangle 2's area:"<<rectangle_array[1].area()<<endl;
	}
	if(rectangle_array[0]==rectangle_array[0]){

		cout<<"equal rectangles, rectangle 1's area:"<<rectangle_array[0].area();
		cout<<" rectangle 2's area:"<<rectangle_array[0].area()<<endl;
	}

	cout<<"\n Test operators for TRIANGLE:"<<endl;

	cout<<"Before increment  "<< "x:" <<triangle_array[0].get_x()<< "y:" << triangle_array[0].get_y()<<endl;
	triangle_array[0]++;
	cout<<"After:"<< "x: " <<triangle_array[0].get_x()<<" "<< "y:" << triangle_array[0].get_y()<<endl;

	cout<<"Before decrement  "<< "x:" <<triangle_array[0].get_x()<<" "<< "y:" << triangle_array[0].get_y()<<endl;
	--triangle_array[0];
	cout<<"After:"<< "x: " <<triangle_array[0].get_x()<<" "<<"y:" << triangle_array[0].get_y()<<endl;

	cout<<"== , =! test & also area test"<<endl;
	if(triangle_array[0]!=triangle_array[1]){

		cout<<"not equal triangles, triangle 1's area:"<<triangle_array[0].area();
		cout<<" triangle 2's area:"<<triangle_array[1].area()<<endl;
	}
	if(triangle_array[0]==triangle_array[0]){

		cout<<"equal triangles, triangle 1's area:"<<triangle_array[0].area();
		cout<<" triangle 2's area:"<<triangle_array[0].area()<<endl;
		
	}

	cout<<"\n TEST TWO DIFFERENT SHAPES IF THEY ARE EQUAL OR NOT"<<endl;

	if(rectangle_array[0]!=triangle_array[1]){

		cout<<"not equal shapes, shape 1's area:"<<rectangle_array[0].area();
		cout<<" shape 2's area:"<<triangle_array[1].area()<<endl;
	}

	cout<<"\nEND OF THE TEST PART FOR SHAPE CLASS OPERATORS"<<endl;

	cout<<"\nTEST PART FOR GLOBAL FUNCTIONS"<<endl;

	//Test printAll function
	vector<Shape*> v;
	file1.open("printAllfile.svg");
	Circle testcir(50,300,200);
	Triangle testtri(150,250,(150*sqrt(3)/2),0);
	v.push_back(&rectangle_array[1]);
	v.push_back(&testcir);
	v.push_back(&testtri);
	file1<< "<svg version=\"1.1\" baseProfile=\"full\"  xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
	rectangle_array[3].draw(file1);
	file1<< " <rect width=\"100%\" height=\"100%\" fill=\"red\" /> "<< endl;
	printAll(v,file1);
	file1 << "</svg>" << endl;
	file1.close();

	//Test printPoly function
	file8.open("printPollyfile.svg");
	file8<< "<svg version=\"1.1\" baseProfile=\"full\"  xmlns=\"http://www.w3.org/2000/svg\"> "<<endl;
	rectangle_array[3].draw(file8);
	file8<< " <rect width=\"100%\" height=\"100%\" fill=\"red\" /> "<< endl;
	printPoly(v,file8);
	file8 << "</svg>" << endl;
	file8.close();

	cout<<"\nTest the sortShapes function"<<endl;
	cout<<"Information:"<<endl;
	cout<<"Rectangle's area:"<<rectangle_array[1].area()<<endl;
	cout<<"Triangle's area:"<<testtri.area()<<endl;
	cout<<"Circle's area:"<<testcir.area()<<endl;
	sortShapes(v);
	}
	catch(...)
	{
		cout<<"An exception occurred"<<endl;
		exit(1);
	}
	/*I am doing this stuff for avoid of memory leaks
	*from postfix increment & decrement pointers  */
	circle_counter=Circle::new_circles.size();
	for(int i=0; i<circle_counter; ++i){
		delete Circle::new_circles[i];
	}
	while(Circle::new_circles.size()!=0){ 
		Circle::new_circles.pop_back();
	}

	rect_count=Rectangle::new_rects.size();
	for(int i=0; i<rect_count; ++i){
		delete Rectangle::new_rects[i];
	}
	while(Rectangle::new_rects.size()!=0){ 
		Rectangle::new_rects.pop_back();
	}

	tri_count=Triangle::new_tri.size();
	for(int i=0; i<tri_count; ++i){
		delete Triangle::new_tri[i];
	}
	while(Triangle::new_tri.size()!=0){ 
		Triangle::new_tri.pop_back();
	}

	vect_count=PolygonVect::new_vects.size();
	for(int i=0; i<vect_count; ++i){
		delete PolygonVect::new_vects[i];
	}
	while(PolygonVect::new_vects.size()!=0){ 
		PolygonVect::new_vects.pop_back();
	}

	dyn_count=PolygonDyn::new_dyns.size();
	for(int i=0; i<dyn_count; ++i){
		delete PolygonDyn::new_dyns[i];
	}
	while(PolygonDyn::new_dyns.size()!=0){ 
		PolygonDyn::new_dyns.pop_back();
	}


	return 0;
}

