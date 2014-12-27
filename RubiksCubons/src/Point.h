/*
 * Point.h
 *
 *  Created on: 19 déc. 2014
 *      Author: Julien
 */

#ifndef POINT_H_
#define POINT_H_

#include <GL/glut.h>.h>

class Point {
private:
	GLfloat _x, _y, _z;
public:
	Point(const Point& p);
	Point(GLfloat x, GLfloat y, GLfloat z);
	virtual ~Point();
	GLfloat getX() const;
	void setX(GLfloat x);
	GLfloat getY() const;
	void setY(GLfloat y);
	GLfloat getZ() const;
	void setZ(GLfloat z);

};

#endif /* POINT_H_ */
