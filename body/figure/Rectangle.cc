#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#endif

#include <iostream>
#include "Rectangle.hh"
#include "../../common/Point2D.hh"
#include "../../common/Point.hh"

using namespace std;

Rectangle::Rectangle(){
	height = 1;
	width = 1;
	vertex = new Point2D(0.0,0.0);
}

Rectangle::Rectangle(string n_Name) : Geometry(n_Name){
	height = 1;
	width = 1;
	vertex = new Point2D();
}

Rectangle::Rectangle(string n_Name, Point2D * n_Vertex, double n_Height, double n_Width) : Geometry(n_Name){
	height = n_Height;
	width = n_Width;
	vertex = n_Vertex;
}

Rectangle::~Rectangle(){
	delete vertex;
}

double Rectangle::getHeight(){
	return height;
}

double Rectangle::getWidth(){
	return width;
}

Point2D * Rectangle::getVertex(){
	return vertex;
}

void Rectangle::setHeight(double n_Height){
	height = n_Height;
}

void Rectangle::setWidth(double n_Width){
	width = n_Width;
}

void Rectangle::setVertex(Point2D * n_Vertex){
	vertex = n_Vertex;
}

