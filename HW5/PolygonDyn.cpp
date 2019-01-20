#include "Polygon.h"	
#include "PolygonDyn.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;
vector<PolygonDyn*> PolygonDyn::new_dyns;
PolygonDyn::PolygonDyn()
{
	
}

PolygonDyn::PolygonDyn(vector<Polygon::Point2D> &my_points){

	vertices=my_points.size();
	points_2D= new Point2D[my_points.size()];
	for (auto i=0; i<my_points.size(); i++){

		points_2D[i]=my_points[i];
	}

}
//Conversion constructor for rectangle
PolygonDyn::PolygonDyn (Rectangle my_rect){

	vertices=4;
	points_2D= new Point2D[4];
	points_2D[0]= Point2D(my_rect.get_x(), my_rect.get_y());
	points_2D[1]= Point2D(my_rect.get_x()+my_rect.get_width(), my_rect.get_y());
	points_2D[2]= Point2D(my_rect.get_x()+my_rect.get_width(), my_rect.get_y()+my_rect.get_height());
	points_2D[3]= Point2D(my_rect.get_x(), my_rect.get_y()+my_rect.get_height());



}
//Conversion constructor for triangle
PolygonDyn::PolygonDyn (Triangle my_tri){

	vertices=3;
	points_2D= new Point2D[3];
	points_2D[0]= Point2D(my_tri.get_x(), my_tri.get_y());
	points_2D[1]= Point2D(my_tri.get_x()+(my_tri.get_edge()/2), my_tri.get_z());
	points_2D[2]= Point2D(my_tri.get_x()+my_tri.get_edge(), my_tri.get_y());
}

//Conversion constructor for circle 
PolygonDyn::PolygonDyn (Circle my_circle){

	vertices=100;
	points_2D= new Point2D[100];
	double my_x, my_y, my_radius, temp_x, temp_y, temp;
	double s=(2*PI)/100;
	my_x= my_circle.get_x();
	my_y=my_circle.get_y();
	my_radius=my_circle.get_radius();
	for (auto i=0; i<100; i++){

		temp=s*i;
		temp_x= (my_x)+ (my_radius *cos(temp));
		temp_y= (my_y)+ (my_radius *sin(temp));	
		points_2D[i].set_x(temp_x);
		points_2D[i].set_y(temp_y);
	}

}

//Copy constructor
PolygonDyn::PolygonDyn(const PolygonDyn &my_poly){

	vertices=my_poly.get_vert();
	points_2D=new Point2D[vertices];
	for(auto i=0; i<vertices; i++){

		points_2D[i]=my_poly.points_2D[i];
	}
}

//destructor
PolygonDyn::~PolygonDyn(){

	delete[]points_2D;
}
// = operator
void PolygonDyn::set_vertices(int vert)
{
	if(vert>0){
		
			vertices=vert;
		}
	else
		exit(1);
}

PolygonDyn& PolygonDyn::operator=(const PolygonDyn &my_poly){

	if(vertices!= my_poly.vertices){

		delete[] points_2D;
		points_2D=new Point2D[my_poly.vertices];
	}
	vertices=my_poly.vertices;
	for(auto i=0; i<vertices; i++)
		points_2D[i]=my_poly.points_2D[i];
	return *this;
}

void PolygonDyn::draw(ofstream &fout){

				
		double my_x, my_y, vert;
		vert=vertices;
		
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

PolygonDyn& PolygonDyn::operator++(){

	for(auto i=1; i<vertices; i++){

		points_2D[i].set_x(points_2D[i].get_x()+1);
 		points_2D[i].set_y(points_2D[i].get_y()+1);
 	}
 	return *this;

}
PolygonDyn& PolygonDyn::operator--(){

	for(auto i=1; i<vertices; i++){

		points_2D[i].set_x(points_2D[i].get_x()-1);
 		points_2D[i].set_y(points_2D[i].get_y()-1);
 	}
 	return *this;


} 
PolygonDyn& PolygonDyn::operator--(int ignoreMe){

	vector <Polygon::Point2D> temp_vect;

	for(auto i=1; i<vertices; i++){

		temp_vect[i]=points_2D[i];
		temp_vect[i].set_x(points_2D[i].get_x()-1);
 		temp_vect[i].set_y(points_2D[i].get_y()-1);
 	}
 	PolygonDyn* x=new PolygonDyn(temp_vect);
 	new_dyns.push_back(x);
 	return *x;



}
PolygonDyn& PolygonDyn::operator++(int ignoreMe){

	vector <Polygon::Point2D> temp_vect;

	for(auto i=1; i<vertices; i++){

		temp_vect[i]=points_2D[i];
		temp_vect[i].set_x(points_2D[i].get_x()+1);
 		temp_vect[i].set_y(points_2D[i].get_y()+1);
 	}
 	PolygonDyn* x=new PolygonDyn(temp_vect);
 	new_dyns.push_back(x);
 	return *x;
}

double PolygonDyn::area() const{

	double area=0, x=0, y=0, z=0;
	for(auto i=1; i<vertices; i++){

		x=(points_2D[i].get_x()*points_2D[i+1].get_y());
		y=(points_2D[i].get_y()*points_2D[i+1].get_x());
		z=x-y;
		area+=z;
	}
	x=(points_2D[0].get_x()*points_2D[vertices-1].get_y());
	y=(points_2D[0].get_y()*points_2D[vertices-1].get_x());
	z=x-y;
	area+=z;
	area=area/2;
	if(area<0)
		area=area*-1;
	return area; 

}


double PolygonDyn::perimeter()const{

	double perimeter, x=0,y=0,z=0;

	for(auto i=0; i<vertices; i++){

		x=(points_2D[i].get_x()-points_2D[i-1].get_x())*(points_2D[i].get_x()-points_2D[i-1].get_x());
		y=(points_2D[i].get_y()-points_2D[i-1].get_y())*(points_2D[i].get_y()-points_2D[i-1].get_y());
		z=sqrt(x+y);
		perimeter+=z;
	}
	x=(points_2D[0].get_x()-points_2D[vertices-1].get_x())*(points_2D[0].get_x()-points_2D[vertices-1].get_x());
	y=(points_2D[0].get_y()-points_2D[vertices-1].get_y())*(points_2D[0].get_y()-points_2D[vertices-1].get_y());
	z=sqrt(x+y);
	perimeter+=z;
	if(perimeter<0)
		perimeter=perimeter*-1;
	return perimeter;
}

