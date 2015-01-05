/*
 * Face.h
 *
 *  Created on: 19 dйc. 2014
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
	bool isShining;
	int index;
public:
	virtual ~Face();
	Face(vector<Point> tbPoints, Couleur couleur);
	Face(Point p1, Point p2, Point p3, Point p4, Couleur couleur, int i );

	Point getPoint(int i);
	Point getPoint(Point p);
	Point getPoint(GLfloat x, GLfloat y, GLfloat z);
	GLfloat mat_color[4];
	GLfloat no_mat[4] = { 0.0F, 0.0F, 0.0F, 1.0F }; // utilise pour les lignes


	Couleur getCouleur() const;
	void setCouleur(Couleur couleur);
	vector<Point> getTbPoints();
	bool estFaitDe(Point p);
	void afficher(bool modeTextures);
	void afficherContour(Couleur c);
	void setShining(bool arg);

};

#endif /* FACE_H_ */
