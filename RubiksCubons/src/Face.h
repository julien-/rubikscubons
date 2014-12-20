/*
 * Face.h
 *
 *  Created on: 19 déc. 2014
 *      Author: Julien
 */

#ifndef FACE_H_
#define FACE_H_
using namespace std;

#include <gl.h>
#include "Point.h"
#include "Couleur.h"

class Face {
private:
	Point _tbPoints[4];
	Couleur _couleur;
public:
	Face();
	virtual ~Face();
	Face(Point tbPoints[], Couleur couleur);
	Face(Point p1, Point p2, Point p3, Point p4, Couleur couleur);
	Point getPoint(int i);
	Point getPoint(Point p);
	Point getPoint(GLfloat x, GLfloat y, GLfloat z);

	Couleur getCouleur() const;
	void setCouleur(Couleur couleur);
	Point* getTbPoints();
	bool estFaitDe(Point p);
	void afficher();

};

#endif /* FACE_H_ */
