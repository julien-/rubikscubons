/*
 * Cube.cpp
 *
 *  Created on: 20 déc. 2014
 *      Author: Julien
 */

#include <cstdio>
#include <new>

using namespace std;

#include "Cube.h"

Cube::Cube() {
	// TODO Auto-generated constructor stub
}

Cube::~Cube() {
	// TODO Auto-generated destructor stub
}

const Face* Cube::getTbFace() const {
	return *_tbFace;
}

Face Cube::getFace(int i) {
	return *_tbFace[i];
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
/*
Cube::Cube(GLfloat x, GLfloat y, GLfloat z){
	//avant
	Point(-largCube + decalage, -largCube + decalage, largCube + decalage),	//haut gauche
	Point(-largCube + decalage, largCube + decalage, largCube + decalage),	//haut droite
	Point(largCube + decalage, largCube + decalage, largCube + decalage),		//bas droite
	Point(largCube + decalage, -largCube + decalage, largCube + decalage),	//bas gauche
	//arriere
	Point(-largCube + decalage, -largCube + decalage, -largCube + decalage),	//haut gauche
	Point(-largCube + decalage, largCube + decalage, -largCube + decalage),	//haut droite
	Point(largCube + decalage, largCube + decalage, -largCube + decalage),	//bas droite
	Point(largCube + decalage, -largCube + decalage, -largCube + decalage),	//bas gauche
	tbCouleur[0], tbCouleur[1], tbCouleur[2], tbCouleur[3], tbCouleur[4], tbCouleur[5]);
}*/
Cube::Cube(float size, Point p0, Couleur c0, Couleur c1, Couleur c2, Couleur c3, Couleur c4, Couleur c5) {
	try{
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
	Point *p1 = new Point(p0.getX()+size, 	p0.getY(), 			p0.getZ());
	Point *p2 = new Point(p1->getX(), 		p1->getY()-size, 	p0.getZ());
	Point *p3 = new Point(p0.getX(), 		p2->getY(), 		p0.getZ());
	Point *p4 = new Point(p0.getX(), 		p0.getY(), 			p0.getZ()+size);
	Point *p5 = new Point(p1->getX(), 		p1->getY(), 		p4->getZ());
	Point *p6 = new Point(p2->getX(), 		p2->getY(), 		p4->getZ());
	Point *p7 = new Point(p3->getX(), 		p3->getY(), 		p4->getZ());

	_tbFace[0] = new Face(p0, *p1, *p2, *p3, c0);	//devant nous
	_tbFace[1] = new Face(p0, *p1, *p5, *p4, c1);//haut
	_tbFace[2] = new Face(*p1, *p5, *p6, *p2, c2);//droite
	_tbFace[3] = new Face(*p2, *p6, *p7, *p3, c3);//bas
	_tbFace[4] = new Face(*p3, p0, *p4, *p7, c4);//gauche
	_tbFace[5] = new Face(*p4, *p5, *p6, *p7, c5);//arriere
	}
		catch (bad_alloc& ba)
		{
			printf("###########################BAD ALLOC #######################################\n");
		}
}

void Cube::afficher() {
	try{
	//Chaque face du cube se dessine
	for (int i=0;i<6;i++)
	{
		_tbFace[i]->afficher();
	}
	}
		catch (bad_alloc& ba)
		{
			printf("###########################BAD ALLOC #######################################\n");
		}
}
