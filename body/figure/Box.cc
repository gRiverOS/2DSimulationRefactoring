#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#endif

#include <iostream>
#include "Box.hh"
#include "../../common/Point3D.hh"
#include "../../common/Point.hh"

using namespace std;

Box::Box(){
    width = 1;
    height = 1;
    depth = 1;
    vertex = new Point3D(0.5, 0.5, 0.5);
}

Box::Box(string n_Name) : Geometry(n_Name){
    width = 1;
    height = 1;
    depth = 1;
    vertex = new Point3D(0.5, 0.5, 0.5);
}


Box::Box(string n_Name, Point3D * n_Vertex, double n_Width, double n_Height, double n_Depth) : Geometry(n_Name){
    // cout << "Creando caja con v en: " << n_Vertex->toString() << endl;
    width = n_Width;
    height = n_Height;
    depth = n_Depth;
    vertex = n_Vertex;
}

Box::~Box(){
    delete vertex;
}

double Box::getWidth(){
    return width;
}

double Box::getHeight(){
    return height;
}

double Box::getDepth(){
    return depth;
}

Point3D * Box::getVertex(){
    return vertex;
}

void Box::setWidth(double n_Width){
    width = n_Width;
}
void Box::setHeight(double n_Height){
    height = n_Height;
}
void Box::setDepth(double n_Depth){
    depth = n_Depth;
}

void Box::setVertex(Point3D * n_Vertex){
    vertex = n_Vertex;
}

