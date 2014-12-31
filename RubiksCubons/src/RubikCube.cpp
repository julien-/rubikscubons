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


	/*
	this->rotationAngles[0] = 0;
	this->rotationAngles[1] = 0;
	this->rotationAngles[2] = 0;
	*/

	for (float x = xdepart; x < -xdepart; x += taille + decalage) {
		for (float y = ydepart; y > -ydepart; y -= taille + decalage) {
			for (float z = zdepart; z < -zdepart; z += taille + decalage) {
				_tbCube.push_back(new Cube(taille, Point(x, y, z)));
			}
		}
	}

	int nbCubesInTranche;
	if (_size == 5) {
		nbCubesInTranche = 25;
	} else if (_size == 3)
		nbCubesInTranche = 9;

	tranches = new Tranche *[NTranches];
	for (int i = 0; i < NTranches; ++i) {
		tranches[i] = new Tranche(nbCubesInTranche);
		for (int j = 0; j < nbCubesInTranche; j++) {
				tranches[i]->setCube(j, i*nbCubesInTranche+j);
			}
	}


	//_tbTranche est un tableau de tranches (size*3  car x,y,z)
	//_tbTranche[0] = new Tranche(0, _size, _tbCouleur);//axe des X
	//_tbTranche[1] = new Tranche(1, _size, _tbCouleur);//axe des Y
	//_tbTranche[2] = new Tranche(2, _size, _tbCouleur);//axe des Z
}
/////////////////////////////////////////////////:



void RubikCube::afficher() {

	glEnable(GL_LINE_SMOOTH);	//Active l'antialiasing pour les lignes

	bool fl;
	for (int i = 0; i < _tbCube.size(); ++i) {
		fl = false;

		for (int j = 0; j < NTranches; ++j) {

			for (int var = 0; var < tranches[j]->getnbCubesInTranche(); ++var) {//traitement de la tranche 1
				int tmp = tranches[j]->getCube(var);
				if (tranches[j]->getCube(var) == i) {
					fl = true;
					glPushMatrix();
					glRotatef(tranches[j]->getAngle(), 1.0, 0.0, 0.0);
					_tbCube[i]->afficher();
					glPopMatrix();

				}
			}
		}
		if (fl == false) {//si le cube n'appartient pas a tranche on fais pas de rotation
			_tbCube[i]->afficher();
		}

	}

}
//////////////////////////////////////////////////

int RubikCube::getSize() const {
	return _size;
}

void RubikCube::setSize(int size) {
	_size = size;
}

RubikCube::~RubikCube() {
	_tbCube.~vector();

	for (int var = 0; var < this->NTranches; ++var) {
			delete tranches[var];
	}
	delete [] tranches;

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


void RubikCube::RotateTranche(int angle, int tranche){
	tranches[tranche]->setAngle(angle);
//this->rotationAngles[tranche] = angle;
}

int RubikCube::getAngle(int tranche){

	return tranches[tranche]->getAngle();
	//return this->rotationAngles[tranche];

}

