/*
 * InputHandler.cc
 *
 *  Created on: 12/11/2012
 *      Author: hector
 */

#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#include  <uFile.h>
#endif

#include "InputHandler.hh"
#include <string.h>
#include "../body/Body.hh"
#include "../body/MaterialProperties.hh"
#include "../body/Material.hh"
#include "../body/figure/Circumference.hh"
#include "../body/figure/Rectangle.hh"
#include "../body/figure/Box.hh"
#include "../common/Point2D.hh"
#include "../common/Point3D.hh"


InputHandler::InputHandler(string file_name) {
    try {
        input_file = new ifstream(strdup(file_name.c_str()));           // open the first input file
    } catch (uFile::Failure ) {
        cerr << "Could not open input file \"" << file_name << "\"" << endl;
        exit(-1);
    } // try
}

InputHandler::~InputHandler() {
    delete input_file;
}

string InputHandler::findData() {
    string line;
    bool gotstring = 0;
    do {
        findline: if (input_file->good()) {
            getline(*input_file, line);
        } else {
            gotstring = 1;
        }
        if (!line.compare("") == 0) {
            for (size_t i = 0; i < line.length(); i++) {
                if (line.at(i) == '#') {
                    if (i == 0) {
                        goto findline;
                    }
                    line = line.substr(0, i);
                    break;
                }
            }
            break;
        }
    } while (!gotstring);

    return line;
}

void InputHandler::setHandlers(BodyContainer*& bodyContainer,
        SourceHandler*& sourceHandler, string &outfile_name, string &encoding,
        int& dimensions) {

    string data, geometryname, delimiter = "\t";
    vector<string> line;
    vector<string>::iterator it;
    int number_bodys, number_childrens, number_particles;
    double width, height, depth, radius;
    Body * body;
    Material * material;
    MaterialProperties * materialProperties;
    Point2D * v;
    Point3D * v3d;
    Rectangle * rectangle;
    Circumference * circumference;
    Box * box;
    Source * source;
    bool sensitive;

    /*Se obtiene el numero de dimensiones para determinar el tipo de simulacion 2D o 3D */
    /*Se obtiene el numero de cuerpos del universo de simulacion*/
    data = findData();
    try {
        dimensions = atoi(data.c_str());
        if (dimensions < 2 || dimensions > 3) {
            cerr
                    << "No ha sido posible obtener el numero de dimensiones para la simulacion"
                    << endl;
            exit(-1);
        }
    } catch (int ex) {
        cerr
                << "No ha sido posible obtener el numero de dimensiones para la simulacion"
                << endl;
        exit(-1);
    }

    /*Se obtiene el nombre y enconding del archivo de salida*/
    data = findData();
    line = this->split(strdup(data.c_str()), strdup(delimiter.c_str()));
    if (line.size() < 2) {
        cerr
                << "No se encuentra bien determinado el nombre y enconding del archivo de salida"
                << endl;
        exit(-1);
    }
    if (line[1].compare("A") != 0 && line[1].compare("B") != 15) {
        cerr
                << "El enconding del archivo de salida puedes ser A(Ascii) o B(Binario)"
                << endl;
        exit(-1);
    }
    outfile_name = line[0];
    encoding = line[1];

    /*Se obtiene el numero de cuerpos del universo de simulacion*/
    data = findData();
    try {
        number_bodys = atoi(data.c_str());
        if (number_bodys == 0) {
            cerr
                    << "No ha sido posible obtener el numero de cuerpos involucrados en la simulacion"
                    << endl;
            exit(-1);
        }
    } catch (int ex) {
        cerr
                << "No ha sido posible obtener el numero de cuerpos involucrados en la simulacion"
                << endl;
        exit(-1);
    }

    /*Se obtienen los datos de cada uno de los cuerpos*/
    for (int i = 0; i < number_bodys; i++) {
        data = findData();
        line = this->split(strdup(data.c_str()), strdup(delimiter.c_str()));
        if (line.size() < 5) {
            cerr << "No es posible obtener el las propiedades del cuerpo n°"
                    << i << endl;
            exit(-1);
        }

        /*Se instancia el material y sus propiedades*/
        materialProperties = new MaterialProperties();
        materialProperties->addProperty("absorption_coefficient",
                atof(line[0].c_str()));
        materialProperties->addProperty("scattering_coefficient",
                atof(line[1].c_str()));
        materialProperties->addProperty("anisotropy", atof(line[2].c_str()));
        material = new Material();
        material->setName(line[3]);
        material->setMaterialProperties(materialProperties);
        sensitive = atoi(line[4].c_str());
        materialProperties->addProperty("refractive_index",atof(line[5].c_str()));

        /*Se instancia la geometria del cuerpo*/
        data = findData();
        line = this->split(strdup(data.c_str()), strdup(delimiter.c_str()));
        if (line.size() < 1) {
            cerr << "No ha sido posible obtener la geometria del cuerpo"
                    << endl;
            exit(-1);
        }
        if (line[0].compare("rectangle") != 0 &&
            line[0].compare("circumference") != 0 &&
            line[0].compare("box") != 0) {
            cerr << "La geometria solo puede ser 'rectangle', 'circumference' o 'box'" << endl;
            exit(-1);
        }

        /*En el caso de ser un rectangulo*/
        if (line[0].compare("rectangle") == 0) {
            geometryname = line[1];
            number_childrens = atof(line[2].c_str());
            v = new Point2D(atof(line[3].c_str()), atof(line[4].c_str()));
            width = atof(line[5].c_str());
            height = atof(line[6].c_str());
            rectangle = new Rectangle(geometryname, v, height, width);
            body = new Body(rectangle, material, i + 1, sensitive);
            if (i == 0) {
                bodyContainer = new BodyContainer(body, number_childrens);
            } else {
                bodyContainer->addBody(body, number_childrens);
            }
        }
        /*En el caso de ser circunferencia*/
        else if (line[0].compare("circumference") == 0) {
            geometryname = line[1];
            number_childrens = atof(line[2].c_str());
            v = new Point2D(atof(line[3].c_str()), atof(line[4].c_str()));
            radius = atof(line[5].c_str());
            circumference = new Circumference(geometryname, v, radius);
            body = new Body(circumference, material, i + 1, sensitive);
            if (i == 0) {
                bodyContainer = new BodyContainer(body, number_childrens);
            } else {
                bodyContainer->addBody(body, number_childrens);
            }
        }

        /* 
         * En el caso de ser una caja
         * Para crear una caja se realiza un cambio. El usuario ingresa
         * el centro de la caja, y esto debe ser convertido al vertice mínimo
         */
        else if (line[0].compare("box") == 0) {
            geometryname = line[1];
            number_childrens = atof(line[2].c_str());
            width = atof(line[6].c_str());
            height = atof(line[7].c_str());
            depth = atof(line[8].c_str());
            v3d = new Point3D(
                atof(line[3].c_str()) - width / 2.0, 
                atof(line[4].c_str()) - height / 2.0,
                atof(line[5].c_str()) - depth / 2.0
            );
            
            // cout << "Vertice caja: " << v3d->toString() << endl;

            box = new Box(geometryname, v3d, width, height, depth);
            body = new Body(box, material, i + 1, sensitive);
            if (i == 0) {
                bodyContainer = new BodyContainer(body, number_childrens);
            } else {
                bodyContainer->addBody(body, number_childrens);
            }
        }
    }
    if (bodyContainer == NULL) {
        cerr
                << "Error: No ha sido posible inicializar el bodyHandler del sistema"
                << endl;
        exit(-1);
    }

    // cout << "Todas los cuerpos han sido creados..." << endl;

    /*Se cargan las fuentes del sistema*/
    int number_sources;
    /*Se obtiene el numero de fuentes del universo de simulacion*/
    data = findData();
    try {
        number_sources = atoi(data.c_str());
        if (number_sources == 0) {
            cerr
                    << "No ha sido posible obtener el numero de fuentes involucradas en la simulacion"
                    << endl;
            exit(-1);
        }
    } catch (int ex) {
        cerr
                << "No ha sido posible obtener el numero de fuentes involucradas en la simulacion"
                << endl;
        exit(-1);
    }
    for (int i = 0; i < number_sources; i++) {
        data = findData();
        try {
            number_particles = atoi(data.c_str());
            if (number_particles == 0) {
                cerr << "No ha sido posible obtener el numero de particulas de la fuente " << i << endl;
                exit(-1);
            }
        } catch (int ex) {
            cerr << "No ha sido posible obtener el numero de particulas de la fuente " << i << endl;
            exit(-1);
        }

        data = findData();

        line = this->split(strdup(data.c_str()), strdup(delimiter.c_str()));
        if (line.size() < 1) {
            cerr << "No ha sido posible obtener la geometria del cuerpo" << endl;
            exit(-1);
        }
        if (line[0].compare("rectangle") != 0 &&
            line[0].compare("circumference") != 0 &&
            line[0].compare("box") != 0) {
            cerr << "La geometria solo puede ser 'rectangle', 'circumference' o 'box'" << endl;
            exit(-1);
        }

        if (line[0].compare("rectangle") == 0) {
            geometryname = line[1];
            v = new Point2D(atof(line[2].c_str()), atof(line[3].c_str()));
            width = atof(line[4].c_str());
            height = atof(line[5].c_str());
            rectangle = new Rectangle(geometryname, v, height, width);
            source = new Source(rectangle, number_particles, i + 1);
            sourceHandler->addSource(source);
        }
        else if (line[0].compare("circumference") == 0) {
            geometryname = line[1];
            v = new Point2D(atof(line[2].c_str()), atof(line[3].c_str()));
            radius = atof(line[4].c_str());
            circumference = new Circumference(geometryname, v, radius);
            source = new Source(circumference, number_particles, i + 1);
            sourceHandler->addSource(source);
        }
        else if (line[0].compare("box") == 0) {

            geometryname = line[1];

            width = atof(line[5].c_str());
            height = atof(line[6].c_str());
            depth = atof(line[7].c_str());

            v3d = new Point3D(
                atof(line[2].c_str()) - width / 2.0, 
                atof(line[3].c_str()) - height / 2.0,
                atof(line[4].c_str()) - depth / 2.0
            );

            // cout << "Vertice fuente: " << v3d->toString() << endl;

            box = new Box(geometryname, v3d, width, height, depth);
            source = new Source(box, number_particles, i + 1);

            // Se analiza si la fuente es direccionada
            // cout << "Analizando si es fuente direccionada..." << endl;
            if (line.size() >= 12) {
                // cout << "Fuente direccionada..." << endl;
                source->setDirection(
                    new Point3D(
                        atof(line[8].c_str()), 
                        atof(line[9].c_str()), 
                        atof(line[10].c_str())
                    )
                );
                source->setAngularAperture(atof(line[11].c_str()));

                // cout << source->getDirection()->toString() << endl;
            }
            // cout << "Fin de analisis..." << endl;
            sourceHandler->addSource(source);
        }
    }
    // cout << "Todas las fuentes han sido creadas..." << endl;
    // exit(-1);
}

vector<string> InputHandler::split(char* str, char* delim) {
    char* token = strtok(str, delim);

    vector<string> result;

    while (token != NULL) {
        result.push_back(token);
        token = strtok(NULL, delim);
    }
    return result;
}
