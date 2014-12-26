/*
 * Cube.h
 *
 *  Created on: 20 déc. 2014
 *      Author: Julien
 */

#ifndef CUBE_H_
#define CUBE_H_

using namespace std;
#include "Face.h"
#include "Point.h"
#include "Couleur.h"

class Cube {
private:
	Face _tbFace[6];
public:
	Cube();
	Cube(GLfloat x, GLfloat y, GLfloat z);
	Cube(float size, Point p0,Couleur c0, Couleur c1, Couleur c2, Couleur c3, Couleur c4, Couleur c5);
	virtual ~Cube();
	const Face* getTbFace() const;

	Face getFace(int i);
	Face getFace(Point p1, Point p2, Point p3, Point p4);
	Face getFace(Face f);

	void afficher();
};

#endif /* CUBE_H_ */
