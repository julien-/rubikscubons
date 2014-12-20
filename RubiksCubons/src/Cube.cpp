/*
 * Cube.cpp
 *
 *  Created on: 20 déc. 2014
 *      Author: Julien
 */

#include "Cube.h"

Cube::Cube() {
	// TODO Auto-generated constructor stub
}

Cube::~Cube() {
	// TODO Auto-generated destructor stub
}

const Face* Cube::getTbFace() const {
	return _tbFace;
}

Face Cube::getFace(int i) {
	return _tbFace[i];
}

Face Cube::getFace(Point p1, Point p2, Point p3, Point p4) {
	/*
	int f = 0;
	bool trouve = false;
	while (f < sizeof(_tbFace) && !trouve) {
		int p = 0;
		while (p < sizeof(_tbFace[f].getTbPoints()) && !trouve){

			if (_tbFace[f].getTbPoints()[p]

			trouve = true;
		else
			j++;
		}
		f++;
	}
	return _tbFace[f];
	*/
}

Face Cube::getFace(Face f) {
	/*
	int i = 0;
	bool trouve = false;
	while (i < sizeof(_tbFace) && !trouve) {
		if (_tbFace[i] == f)
			trouve = true;
		else
			i++;
	}
	return _tbFace[i];
	*/
}

Cube::Cube(Point p0, Point p1, Point p2, Point p3, Point p4, Point p5, Point p6, Point p7, Couleur c0, Couleur c1, Couleur c2, Couleur c3, Couleur c4, Couleur c5) {
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

	_tbFace[0] = Face(p0, p1, p2, p3, c0);	//devant nous
	_tbFace[1] = Face(p0, p1, p5, p4, c1);//haut
	_tbFace[2] = Face(p1, p5, p6, p2, c2);//droite
	_tbFace[3] = Face(p2, p6, p7, p3, c3);//bas
	_tbFace[4] = Face(p3, p0, p4, p7, c4);//gauche
	_tbFace[5] = Face(p4, p5, p6, p7, c5);//arriere
}

void Cube::afficher() {
	//Chaque face du cube se dessine
	for (int i=0;i<6;i++)
	{
		_tbFace[i].afficher();
	}

}
