/*
 * Face.h
 *
 *  Created on: 19 d�c. 2014
 *      Author: Julien
 */

#ifndef FACE_H_
#define FACE_H_

using namespace std;
#include <vector>
#include <GL/gl.h>
#include "Point.h"
#include "Couleur.h"

class Face {
private:
	vector<Point> _tbPoints;
	Couleur _couleur;
public:
	virtual ~Face();
	Face(vector<Point> tbPoints, Couleur couleur);
	Face(Point p1, Point p2, Point p3, Point p4, Couleur couleur);
	Point getPoint(int i);
	Point getPoint(Point p);
	Point getPoint(GLfloat x, GLfloat y, GLfloat z);

	Couleur getCouleur() const;
	void setCouleur(Couleur couleur);
	vector<Point> getTbPoints();
	bool estFaitDe(Point p);
	void afficher(bool modeTextures);
	void afficherContour(Couleur c);

};

#endif /* FACE_H_ */
