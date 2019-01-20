#include "Polygon.h"
#include "PolygonVect.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;
vector<PolygonVect*> PolygonVect::new_vects;
PolygonVect::PolygonVect()
{
	
}
//Conversion constructor for rectangle
PolygonVect::PolygonVect (Rectangle my_rect){

	points_2D.push_back(Point2D (my_rect.get_x(),my_rect.get_y()));
	points_2D.push_back(Point2D(my_rect.get_x()+my_rect.get_width(), my_rect.get_y()));
	points_2D.push_back(Point2D(my_rect.get_x()+my_rect.get_width(), my_rect.get_y()+my_rect.get_height()));
	points_2D.push_back(Point2D(my_rect.get_x(), my_rect.get_y()+my_rect.get_height()));


}
//Conversion constructor for triangle
PolygonVect::PolygonVect (Triangle my_tri){

	points_2D.push_back(Point2D(my_tri.get_x(), my_tri.get_y()));
	points_2D.push_back(Point2D(my_tri.get_x()+(my_tri.get_edge()/2), my_tri.get_z()));
	points_2D.push_back(Point2D(my_tri.get_x()+my_tri.get_edge(), my_tri.get_y()));
}

//Conversion constructor for circle 
PolygonVect::PolygonVect (Circle my_circle){

	double my_x, my_y, my_radius, temp_x, temp_y, temp;
	double s=(2*PI)/100;
	my_x= my_circle.get_x();
	my_y=my_circle.get_y();
	my_radius=my_circle.get_radius();
	for (auto i=0; i<100; i++){

		temp=s*i;
		temp_x= (my_x)+ (my_radius *cos(temp));
		temp_y= (my_y)+ (my_radius *sin(temp));	
		points_2D.push_back(Point2D(temp_x,temp_y));
	
	}

}

PolygonVect::PolygonVect(vector<Polygon::Point2D> &my_points){

	
	for (auto i=0; i<my_points.size(); i++){

		points_2D.push_back(my_points[i]);
	}
}


void PolygonVect::draw(ofstream &fout){

				
		double my_x, my_y, vert;
		vert=points_2D.size();
		
		fout<<"<polygon points= \"";
		for(auto i=0; i<vert; i++){
		my_x=points_2D[i].get_x();
		my_y=points_2D[i].get_y();
		fout<<my_x<<","<<my_y<<" ";
		}
		fout<<" \"";
		fout<<" stroke=\"black\" stroke-width=\"3\" fill=\"rgb(121,0,121)\"" ;
		fout <<"/>"<<endl;
	

}

PolygonVect& PolygonVect::operator++(){

	for(auto i=1; i<points_2D.size(); i++){

		points_2D[i].set_x(points_2D[i].get_x()+1);
 		points_2D[i].set_y(points_2D[i].get_y()+1);
 	}
 	return *this;

}
PolygonVect& PolygonVect::operator--(){

	for(auto i=1; i<points_2D.size(); i++){

		points_2D[i].set_x(points_2D[i].get_x()-1);
 		points_2D[i].set_y(points_2D[i].get_y()-1);
 	}
 	return *this;

} 
PolygonVect& PolygonVect::operator--(int ignoreMe){

	vector <Polygon::Point2D> temp_vect;

	for(auto i=1; i<points_2D.size(); i++){

		temp_vect[i]=points_2D[i];
		temp_vect[i].set_x(points_2D[i].get_x()-1);
 		temp_vect[i].set_y(points_2D[i].get_y()-1);
 	}
 	PolygonVect* x=new PolygonVect(temp_vect);
 	new_vects.push_back(x);
 	return *x;

}
PolygonVect& PolygonVect::operator++(int ignoreMe){

	vector <Polygon::Point2D> temp_vect;

	for(auto i=1; i<points_2D.size(); i++){

		temp_vect[i]=points_2D[i];
		temp_vect[i].set_x(points_2D[i].get_x()+1);
 		temp_vect[i].set_y(points_2D[i].get_y()+1);
 	}
 	PolygonVect* x=new PolygonVect(temp_vect);
 	new_vects.push_back(x);
 	return *x;
}

double PolygonVect::area() const{

	double area=0, x=0, y=0, z=0;
	for(auto i=1; i<points_2D.size(); i++){

		x=(points_2D[i].get_x()*points_2D[i+1].get_y());
		y=(points_2D[i].get_y()*points_2D[i+1].get_x());
		z=x-y;
		area+=z;
	}
	x=(points_2D[0].get_x()*points_2D[points_2D.size()-1].get_y());
	y=(points_2D[0].get_y()*points_2D[points_2D.size()-1].get_x());
	z=x-y;
	area+=z;
	area=area/2;
	if(area<0)
		area=area*-1;
	return area; 

}


double PolygonVect::perimeter()const{

	double perimeter=0, x=0,y=0,z=0;

	for(auto i=1; i<points_2D.size(); i++){
		
		x=(points_2D[i].get_x()-points_2D[i-1].get_x())*(points_2D[i].get_x()-points_2D[i-1].get_x());
		y=(points_2D[i].get_y()-points_2D[i-1].get_y())*(points_2D[i].get_y()-points_2D[i-1].get_y());
		z=sqrt(x+y);
		perimeter+=z;
	}
	x=(points_2D[0].get_x()-points_2D[points_2D.size()-1].get_x())*(points_2D[0].get_x()-points_2D[points_2D.size()-1].get_x());
	y=(points_2D[0].get_y()-points_2D[points_2D.size()-1].get_y())*(points_2D[0].get_y()-points_2D[points_2D.size()-1].get_y());
	z=sqrt(x+y);
	perimeter+=z;
	if(perimeter<0)
		perimeter=perimeter*-1;
	return perimeter;


}

