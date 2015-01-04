#include <cstdio>
#include "Face.h"
#include <new>
#include <GL/glut.h>

Face::Face(vector<Point> tbPoints, Couleur couleur) {
		for (unsigned int i = 0; i < sizeof(tbPoints); ++i) {
			_tbPoints.push_back(tbPoints[i]);
		}
		_couleur = couleur;
}
Face::Face(Point p1, Point p2, Point p3, Point p4, Couleur couleur) {
		_tbPoints.push_back(p1);
		_tbPoints.push_back(p2);
		_tbPoints.push_back(p3);
		_tbPoints.push_back(p4);
		_couleur = couleur;
}
Face::~Face() {
	_tbPoints.~vector();
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

bool Face::estFaitDe(Point p) {
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

vector<Point> Face::getTbPoints() {
	return _tbPoints;
}

void Face::afficher(bool modeTextures) {

	if (modeTextures) {
		glColor3f(255,255,255);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(_tbPoints[0].getX(), _tbPoints[0].getY(),
				_tbPoints[0].getZ());

		glTexCoord2d(0, 1);
		glVertex3d(_tbPoints[1].getX(), _tbPoints[1].getY(),
				_tbPoints[1].getZ());
		glTexCoord2d(1, 1);
		glVertex3d(_tbPoints[2].getX(), _tbPoints[2].getY(),
				_tbPoints[2].getZ());
		glTexCoord2d(1, 0);
		glVertex3d(_tbPoints[3].getX(), _tbPoints[3].getY(),
				_tbPoints[3].getZ());

		glEnd();
		afficherContour(Couleur::noir());
	} else {
		glColor3f(_couleur.getR(), _couleur.getV(), _couleur.getB());
		glBegin(GL_POLYGON);
		for (int i = 0; i < 4; i++) {
			glVertex3f(_tbPoints[i].getX(), _tbPoints[i].getY(),
					_tbPoints[i].getZ());
		}
		glEnd();
		//Affichage des contours noirs
		afficherContour(Couleur::noir());
	}


}

void Face::afficherContour(Couleur c){
	glColor3f(c.getR(), c.getV(), c.getB());
	glLineWidth(4.5);
	glBegin(GL_LINES);
	//relie 0-1
	glVertex3f(_tbPoints[0].getX(), _tbPoints[0].getY(),_tbPoints[0].getZ());
	glVertex3f(_tbPoints[1].getX(), _tbPoints[1].getY(),_tbPoints[1].getZ());
	//relie 1-2
	glVertex3f(_tbPoints[1].getX(), _tbPoints[1].getY(),_tbPoints[1].getZ());
	glVertex3f(_tbPoints[2].getX(), _tbPoints[2].getY(),_tbPoints[2].getZ());
	//relie 2-3
	glVertex3f(_tbPoints[2].getX(), _tbPoints[2].getY(),_tbPoints[2].getZ());
	glVertex3f(_tbPoints[3].getX(), _tbPoints[3].getY(),_tbPoints[3].getZ());
	//relie 3-0
	glVertex3f(_tbPoints[3].getX(), _tbPoints[3].getY(),_tbPoints[3].getZ());
	glVertex3f(_tbPoints[0].getX(), _tbPoints[0].getY(),_tbPoints[0].getZ());
	glEnd();
}

bool operator==(Face const& f1, Face const& f2) {
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
