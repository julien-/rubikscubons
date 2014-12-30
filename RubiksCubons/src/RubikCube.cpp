#include <cstdio>
#include <new>

#include "Couleur.h"
#include "Point.h"

/*
 * RubikCube.cpp
 *
 *  Created on: 24 déc. 2014
 *      Author: Julien
 */
using namespace std;
#include <new>

#include "RubikCube.h"

RubikCube::RubikCube(int size) {
	_size = size;
	_centre = new Point(0.0, 0.0, 0.0);
	//Creation des (size * size * size) cubes
	//   p4---------------p5
	//  /|               / |
	// / |              /  |
	//p0--------------p1   |
	//|  |             |   |
	//|  |             |   |
	//|  p7------------|--p6
	//|  /             |  /
	//| /              | /
	//|/               |/
	//p3---------------p2
	float decalage = 0.01;
	float xdepart = -0.5;
	float ydepart = 0.5;
	float zdepart = -0.5;
	float taille = 1.0 / size;//largeur d'un cube(size est le nombre de cube de large)

	for (float x = xdepart; x < -xdepart; x += taille + decalage) {
		for (float y = ydepart; y > -ydepart; y -= taille + decalage) {
			for (float z = zdepart; z < -zdepart; z += taille + decalage) {
				_tbCube.push_back(new Cube(taille, Point(x, y, z)));
			}
		}
	}

	//_tbTranche est un tableau de tranches (size*3  car x,y,z)
	//_tbTranche[0] = new Tranche(0, _size, _tbCouleur);//axe des X
	//_tbTranche[1] = new Tranche(1, _size, _tbCouleur);//axe des Y
	//_tbTranche[2] = new Tranche(2, _size, _tbCouleur);//axe des Z
}

int RubikCube::getSize() const {
	return _size;
}

void RubikCube::setSize(int size) {
	_size = size;
}

RubikCube::~RubikCube() {
	_tbCube.~vector();
}

void RubikCube::afficher() {
	glEnable(GL_LINE_SMOOTH);//Active l'antialiasing pour les lignes
	for (unsigned int i = 0; i < _tbCube.size(); ++i)
		_tbCube[i]->afficher();
}

const Point* RubikCube::getCentre() const {
	return _centre;
}

void RubikCube::setCentre(const Point* centre) {
	*_centre = *centre;
}

void RubikCube::Rotation(char XYZ, int angle){
	switch (XYZ) {
	    case 'x' :
	    	glRotatef(angle,1.0,0.0,0.0);
			break ;
	    case 'y' :
	    	glRotatef(angle,0.0,1.0,0.0);
			break ;
	    case 'z' :
	    	glRotatef(angle,0.0,0.0,1.0);
	    	break;
	}
}


void RubikCube::Deplacement(GLfloat x, GLfloat y, GLfloat z){
	GLfloat Xcentre = _centre->getX() + x;
	GLfloat Ycentre = _centre->getY() - y;
	GLfloat Zcentre = _centre->getZ() + z;
	_centre->setX(Xcentre);
	_centre->setY(Ycentre);
	_centre->setZ(Zcentre);
	glTranslatef(-x,-y,z);
}
