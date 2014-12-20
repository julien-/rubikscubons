/*
 * Face.cpp
 *
 *  Created on: 19 déc. 2014
 *      Author: Julien
 */

#include "Face.h"

#include <GL/glut.h>

Face::Face() {
	// TODO Auto-generated constructor stub
}
Face::~Face() {
	// TODO Auto-generated destructor stub
}
Face::Face(Point tbPoints[4], Couleur couleur){
	for (unsigned int i = 0; i < sizeof(tbPoints); ++i) {
		_tbPoints[i] = tbPoints[i];
	}
	_couleur = couleur;
}
Face::Face(Point p1, Point p2, Point p3, Point p4, Couleur couleur){
	_tbPoints[0] = p1;
	_tbPoints[1] = p2;
	_tbPoints[2] = p3;
	_tbPoints[3] = p4;
	_couleur = couleur;
}
Couleur Face::getCouleur() const {
	return _couleur;
}

void Face::setCouleur(Couleur couleur) {
	_couleur = couleur;
}




Point Face::getPoint(int i) {
	return _tbPoints[i];
}

/*
 Point Face::getPoint(GLfloat x, GLfloat y, GLfloat z) {
 int i = 0;
 bool trouve = false;
 while (i < sizeof(_tbPoints) && !trouve) {
 if (_tbPoints[i].getX() == x && _tbPoints[i].getY() == y
 && _tbPoints[i].getZ() == z)
 trouve = true;
 else
 i++;
 }
 return _tbPoints[i];
 }*/

Point Face::getPoint(Point p) {
	/*
	int i = 0;
	bool trouve = false;
	while (i < sizeof(_tbPoints) && !trouve) {
		if (_tbPoints[i] == p)
			trouve = true;
		else
			i++;
	}
	return _tbPoints[i];
	*/
}

bool Face::estFaitDe(Point p){
	/*
	int i = 0;
	while (i < sizeof(_tbPoints)) {
		if (_tbPoints[i] == p)
			return true;
		else
			i++;
	}
	return false;*/
}

Point* Face::getTbPoints() {
	return _tbPoints;
}

void Face::afficher(){
	glColor3f(_couleur.getR(), _couleur.getV(), _couleur.getB());
	glBegin(GL_POLYGON);
		for (int i=0;i<4;i++)
		{
			glVertex3f(_tbPoints[i].getX(),_tbPoints[i].getY(), _tbPoints[i].getZ());
		}
	glEnd();
}

bool operator==(Face const& f1, Face const& f2){
	/*bool existe = false;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			Point p = Point(f2.getTbPoints()[i]);

			if(! f1.estFaitDe(p) )
				return true;
		}
	}

	//return (p1.getX() == p2.getX() && p1.getY() == p2.getY() && p1.getZ() == p2.getZ());
	 *
	 */
	return true;
}
