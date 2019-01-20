#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "ComposedShape.h"
#include "Polygon.h"
#include "Polyline.h"

int main(){

	using std::cout;
	using std::cin;
	using std::endl;
	using PolygonNameS::Polygon;
	using PolylineNameS::Polyline;
	using RectangleNameS::Rectangle;
	using TriangleNameS::Triangle;
	using CircleleNameS::Circle;
	using ComposedShapeNameS::ComposedShape;

	
	ofstream user_test, CStest1, CStest2, CStest3, CStest4, CStest5,CStest6, CStest7,CStest8, CStest9;
	ofstream file1, file2, file3, file4, file5, file6, file7, file8, file9, file10, file11,file12;
	int decl;
	decltype(decl) set_radius=40, set_width=60, set_height=40, set_edge=50;
	Circle circle_array[4];
	Rectangle rectangle_array[4];
	Triangle triangle_array[4];
	ComposedShape composed_array[5];
	Polygon polygon_array[5];
	Polyline polyline_array[5];

	/*Fill the circle_array objects*/
	for(auto i=0; i<4; i++){
		
		// If you want to enter your own input
		//circle_array[i].input();
		circle_array[i].set_radius(set_radius); //test the set_radius(int my_radius) function  
		circle_array[i].set_x(set_radius); //test the set_x(double my_x) function 
		circle_array[i].set_y(set_radius);// test the set_y(double my_y) function
		set_radius+=50;

	}
	/*Fill the rectangle_array objects*/
	for(auto i=0; i<4; i++){
		
		// If you want to enter your own input
		//rectangle_array[i].input();
		rectangle_array[i].set_height_width(set_width,set_height); 
		rectangle_array[i].set_positions(0,0); // test the set_positions(double my_x, double my_y)
		set_width+=150;
		set_height+=100;
	
	}
	for(auto i=0; i<4; i++){

		// If you want to enter your own input
		//triangle_array[i].input();
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

	cout<<"TEST PART FOR POLYGON CLASS\n"<<endl;

	Rectangle test1(400,200,0,0);
	polygon_array[0]=Polygon(test1);
	file1.open("Polygon1.svg");
	file1<< "<svg height=\"210\" width=\"500\">"<<endl;
	file1<<polygon_array[0];
	file1 << "</svg>" << endl;
	file1.close();


	vector<Polygon::Point2D> test_poly;
	Polygon::Point2D a(100,10);
	test_poly.push_back(a);
	Polygon::Point2D b(40,198);
	test_poly.push_back(b);
	Polygon::Point2D c(190,78);
	test_poly.push_back(c);
	Polygon::Point2D d(10,78);
	test_poly.push_back(d);
	Polygon::Point2D e(160,198);
	test_poly.push_back(e);

	file2.open("Polygon2.svg");
	file2<< "<svg height=\"210\" width=\"500\">"<<endl;
	Polygon j(test_poly);
	polygon_array[1]=j;
	file2<< polygon_array[1];
	file2 << "</svg>" << endl;
	file2.close();

	Circle test2(200,200,200);
	polygon_array[2]=Polygon(test2);
	file3.open("Polygon3.svg");
	file3<< "<svg height=\"400\" width=\"400\">"<<endl;
	file3<<polygon_array[2];
	file3 << "</svg>" << endl;
	file3.close();

	vector<Polygon::Point2D> test_poly2;
	Polygon::Point2D aa(220,10);
	test_poly2.push_back(aa);
	Polygon::Point2D bb(300,210);
	test_poly2.push_back(bb);
	Polygon::Point2D cc(170,250);
	test_poly2.push_back(cc);
	Polygon::Point2D dd(123,234);
	test_poly2.push_back(dd);

	file4.open("Polygon4.svg");
	file4<< "<svg height=\"300\" width=\"500\">"<<endl;
	Polygon k(test_poly2);
	polygon_array[3]=k;
	file4<< polygon_array[3];
	file4 << "</svg>" << endl;
	file4.close();


	vector<Polygon::Point2D> test_poly3;
	Polygon::Point2D a1(0,200);
	test_poly3.push_back(a1);
	Polygon::Point2D b1(100,125);
	test_poly3.push_back(b1);
	Polygon::Point2D c1(100,200);
	test_poly3.push_back(c1);
	Polygon::Point2D d1(200,0);
	test_poly3.push_back(d1);

	file5.open("Polygon5.svg");
	file5<< "<svg height=\"300\" width=\"300\">"<<endl;
	Polygon l(test_poly3);
	polygon_array[4]=l;
	file5<< polygon_array[4];
	file5 << "</svg>" << endl;
	file5.close();

	file6.open("Polygon+Polygon.svg");
	file6<< "<svg height=\"300\" width=\"320\">"<<endl;
	Polygon deneme;
	deneme=polygon_array[3]+polygon_array[1];
	file6<<deneme;
	file6 << "</svg>" << endl;
	file6.close();

	if(polygon_array[0]!=polygon_array[1])
		cout<<"Polygon1 is not equal to polygon2"<<endl;
		cout<<"\n";
	if(polygon_array[0]==polygon_array[0])
		cout<<"Polygon1 is equal to polygon1"<<endl;
		cout<<"\n";

	cout<<"END OF TEST PART FOR POLYGON CLASS\n"<<endl;

	cout<<"TEST PART FOR POLYLINE CLASS\n"<<endl;

	Triangle test_tri(150,0,(150*sqrt(3)/2),0);
	polyline_array[0]=Polyline(test_tri);
	file7.open("Polyline1.svg");
	file7<< "<svg height=\"210\" width=\"500\">"<<endl;
	file7<<polyline_array[0];
	file7 << "</svg>" << endl;
	file7.close();

	vector<Polyline::Point2D> test_poly4;
	Polyline::Point2D a2(220,10);
	test_poly4.push_back(a2);
	Polyline::Point2D b2(300,210);
	test_poly4.push_back(b2);
	Polyline::Point2D c2(170,250);
	test_poly4.push_back(c2);
	Polyline::Point2D d2(123,234);
	test_poly4.push_back(d2);

	file8.open("Polyline2.svg");
	file8<< "<svg height=\"300\" width=\"500\">"<<endl;
	Polyline s(test_poly4);
	polyline_array[1]=s;
	file8<< polyline_array[1];
	file8 << "</svg>" << endl;
	file8.close();

	Rectangle test4(400,200,0,0);
	polyline_array[2]=Polyline(test4);
	file9.open("Polylne3.svg");
	file9<< "<svg height=\"210\" width=\"500\">"<<endl;
	file9<<polyline_array[2];
	file9 << "</svg>" << endl;
	file9.close();

	Circle test_c(170,170,170);
	polyline_array[3]=Polyline(test_c);
	file10.open("Polylne4.svg");
	file10<< "<svg height=\"400\" width=\"400\">"<<endl;
	file10<<polyline_array[3];
	file10 << "</svg>" << endl;

	vector<Polyline::Point2D> test_poly5;
	Polyline::Point2D a3(80,120);
	test_poly5.push_back(a3);
	Polyline::Point2D b3(120,120 );
	test_poly5.push_back(b3);
	Polyline::Point2D c3(120,160);
	test_poly5.push_back(c3);
	Polyline::Point2D d3(160,160);
	test_poly5.push_back(d3);
	Polyline::Point2D e3(160,160);
	test_poly5.push_back(e3);

	file11.open("Polyline5.svg");
	file11<< "<svg height=\"300\" width=\"500\">"<<endl;
	Polyline w(test_poly5);
	polyline_array[4]=w;
	file11<< polyline_array[4];
	file11 << "</svg>" << endl;
	file11.close();

	file12.open("Polyline+Polyline.svg");
	file12<< "<svg height=\"210\" width=\"300\">"<<endl;
	Polyline deneme2;
	deneme2=polyline_array[0]+polyline_array[4];
	file12<<deneme2;
	file12 <<" fill=\"none\" stroke=\"black\"  stroke-width=\"3\"";
	file12 <<"/>"<<endl;
	file12 << "</svg>" << endl;
	file12.close();


	if(polyline_array[0]!=polyline_array[1])
		cout<<"Polyline1 is not equal to polyline2"<<endl;
		cout<<"\n";
	if(polyline_array[0]==polyline_array[0])
		cout<<"Polyline1 is equal to polyline1"<<endl;
		cout<<"\n";

	cout<<"END OF TEST PART FOR POLYLINE CLASS \n"<<endl;

	return 0;
}

