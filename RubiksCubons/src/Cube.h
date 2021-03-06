/*
 * Cube.h
 *
 *  Created on: 20 d�c. 2014
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
	vector<Face*> _tbFace;
	Point position;
public:
	Cube(GLfloat x, GLfloat y, GLfloat z);
	Cube(float size, Point p0);
	virtual ~Cube();
	const vector<Face*> getTbFace() const;

	Face getFace(int i);
	Face getFace(Point p1, Point p2, Point p3, Point p4);
	Face getFace(Face f);

	void afficher(bool textureMode);
	void setShining(bool arg);
	Point getPosition();
};

#endif /* CUBE_H_ */
