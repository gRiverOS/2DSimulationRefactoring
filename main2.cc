#include <iostream>
#include <vector>
#include <string>
#include "body/BodyHandler.hh"
#include "body/Body.hh"
#include "body/Geometry.hh"
#include "body/figure/Rectangle.hh"
#include "body/figure/Circumference.hh"
#include "body/CustomBodyHandler.hh"
#include "utils/GeometryAlgorithms.hh"
#include "utils/Random.hh"

#define NUMBER_PROCESSORS 2

using namespace std;

#ifdef UC_PLUSPLUS
void uMain::main() {
#else
int main2(int argc, char *argv[]) {
#endif
	/*Material * material = new Material();
	Point2D * v = new Point2D(0.0, 0.0);
	Rectangle * rectangle = new Rectangle("rectangle mother", v, 10, 10);
	srand ( time(NULL) );

	Point * randomPoint = rectangle->getRandomPoint();
	cout << "random : " << dynamic_cast<Point2D*>(randomPoint)->getX() << "," << dynamic_cast<Point2D*>(randomPoint)->getY() << endl;
	if(rectangle->insideGeometry(randomPoint))
		cout << "si esta" << endl;
	else
		cout << "no esta " << endl;

	Body * body = new Body(rectangle, material, 1);
	int number_childrens = 1;
	CustomBodyHandler * cbh = new CustomBodyHandler(body, number_childrens);

	v = new Point2D(50.0, 50.0);
	Circumference * cirumference = new Circumference("circumference 1", v,
			45.0);

	randomPoint = cirumference->getRandomPoint();
	cout << "random : " << dynamic_cast<Point2D*>(randomPoint)->getX() << "," << dynamic_cast<Point2D*>(randomPoint)->getY() << endl;
	if(cirumference->insideGeometry(randomPoint))
		cout << "si esta" << endl;
	else
		cout << "no esta " << endl;

	body = new Body(cirumference,material,2);
	cbh->addBody(body, 2);

	Point2D * aa = new Point2D(13.3457,10.3457);
	if(cirumference->insideGeometry(aa))
		cout << "esta dentro" << endl;
	else
		cout << "no esta adentro" << endl;

	v = new Point2D(50.0, 25.0);
	cirumference = new Circumference("Circumference 2", v, 12);
	body = new Body(cirumference, material, 3);
	cbh->addBody(body, 1);

	v = new Point2D(50.0, 25.0);
	rectangle = new Rectangle("rectangle 2", v, 5.0, 5.0);
	body = new Body(rectangle, material, 4);
	cbh->addBody(body, 0);

	v = new Point2D(50.0, 50.0);
	rectangle = new Rectangle("rectangle 3", v, 20.0, 20.0);
	body = new Body(rectangle, material, 5);
	cbh->addBody(body, 0);

	cbh->setUniverseAsCurrentBody();
	cbh->showTree(cbh->getUniverseBody());

	cbh->setUniverseAsCurrentBody();
	cbh->showTree(cbh->getUniverseBody());

	cbh->setUniverseAsCurrentBody();
	v = new Point2D(1, 1);
	body = cbh->getBody(v);
	if (body != NULL)
		cout << "Para el vector (" << v->getX() << "," << v->getY()
				<< ") el body es: " << body->getID() << endl;
	else
		cout << "not found !" << endl;

	cbh->setUniverseAsCurrentBody();
	v = new Point2D(51, 51);
	body = cbh->getBody(v);
	if (body != NULL)
		cout << "Para el vector (" << v->getX() << "," << v->getY()
				<< ") el body es: " << body->getID() << endl;
	else
		cout << "not found !" << endl;

	cbh->setUniverseAsCurrentBody();
	v = new Point2D(50, 24);
	body = cbh->getBody(v);
	if (body != NULL)
		cout << "Para el vector (" << v->getX() << "," << v->getY()
				<< ") el body es: " << body->getID() << endl;
	else
		cout << "not found !" << endl;

	cbh->setUniverseAsCurrentBody();
	v = new Point2D(1, 1);
	body = cbh->getBody(v);
	if (body != NULL)
		cout << "Para el vector (" << v->getX() << "," << v->getY()
				<< ") el body es: " << body->getID() << endl;
	else
		cout << "not found !" << endl;

	cbh->setUniverseAsCurrentBody();
	v = new Point2D(51, 26);
	body = cbh->getBody(v);
	if (body != NULL)
		cout << "Para el vector (" << v->getX() << "," << v->getY()
				<< ") el body es: " << body->getID() << endl;
	else
		cout << "not found !" << endl;

	cbh->setUniverseAsCurrentBody();
	v = new Point2D(57, 60);
	body = cbh->getBody(v);
	if (body != NULL)
		cout << "Para el vector (" << v->getX() << "," << v->getY()
				<< ") el body es: " << body->getID() << endl;
	else
		cout << "not found !" << endl;

	cbh->setUniverseAsCurrentBody();
	v = new Point2D(10, 12);
	body = cbh->getBody(v);
	if (body != NULL)
		cout << "Para el vector (" << v->getX() << "," << v->getY()
				<< ") el body es: " << body->getID() << endl;
	else
		cout << "not found !" << endl;

	cbh->setUniverseAsCurrentBody();
	v = new Point2D(43, 40);
	body = cbh->getBody(v);
	if (body != NULL)
		cout << "Para el vector (" << v->getX() << "," << v->getY()
				<< ") el body es: " << body->getID() << endl;
	else
		cout << "not found !" << endl;

	cbh->setUniverseAsCurrentBody();
	v = new Point2D(57, 60);
	body = cbh->getBody(v);
	if (body != NULL)
		cout << "Para el vector (" << v->getX() << "," << v->getY()
				<< ") el body es: " << body->getID() << endl;
	else
		cout << "not found !" << endl;

	cbh->setUniverseAsCurrentBody();
	v = new Point2D(50, 24);
	body = cbh->getBody(v);
	if (body != NULL)
		cout << "Para el vector (" << v->getX() << "," << v->getY()
				<< ") el body es: " << body->getID() << endl;
	else
		cout << "not found !" << endl;

	cbh->setUniverseAsCurrentBody();
	v = new Point2D(43, 40);
	body = cbh->getBody(v);
	if (body != NULL)
		cout << "Para el vector (" << v->getX() << "," << v->getY()
				<< ") el body es: " << body->getID() << endl;
	else
		cout << "not found !" << endl;


	Point2D * direction = new Point2D(1, 1);
	Point2D * position = new Point2D(43, 40);
	Step * step = new Step(-100);
	bool hit;
	Point * next_position  = cbh->getNextPosition(position,direction,step,hit);
	if (hit)
		cout << "hited! en" << dynamic_cast<Point2D*>(next_position)->getX() << "," <<
		dynamic_cast<Point2D*>(next_position)->getY() << endl;
	else
		cout << "not hited! en"  << dynamic_cast<Point2D*>(next_position)->getX() << "," <<
		dynamic_cast<Point2D*>(next_position)->getY() << endl;

	GeometryAlgorithms * ga = new GeometryAlgorithms();
	Point2D * v1 = new Point2D(2, 0);
	Point2D * v2 = new Point2D(2, 4);
	Point2D * v3 = new Point2D(-2, -0);
	Point2D * v4 = new Point2D(-2, -5.3);
	Point2D * result = ga->getLineLineIntersection(v1, v2, v3, v4);
	if (result == NULL)
		cout << "no intersecto" << endl;
	else
		cout << "interseccion : (" << result->getX() << "," << result->getY()
				<< ")";

	v1 = new Point2D(0, -10);
	v2 = new Point2D(100, 200);
	v3 = new Point2D(23, 30);
	Circumference * circum1 = new Circumference("hola", v3, 5);
	Point * resultado = circum1->getIntersectionPoint(v1, v2);
	if (resultado == NULL)
		cout << "no intersecto la circunferencia" << endl;
	else
		cout << "point  es: (" << dynamic_cast<Point2D*>(resultado)->getX()
				<< "," << dynamic_cast<Point2D*>(resultado)->getY() << ")"
				<< endl;

	v1 = new Point2D(3, 0);
	v2 = new Point2D(3, 50);
	v3 = new Point2D(2, 2);
	Rectangle * recntag1 = new Rectangle("rect1", v3, 4, 4);

	resultado = recntag1->getIntersectionPoint(v2, v1);
	if (resultado == NULL)
		cout << "no intersecto el rectangulos" << endl;
	else
		cout << "point  es: (" << dynamic_cast<Point2D*>(resultado)->getX()
				<< "," << dynamic_cast<Point2D*>(resultado)->getY() << ")"
				<< endl;

	/*delete v;
	 delete cbh;
	 delete rectangle;
	 delete body;*/
}
