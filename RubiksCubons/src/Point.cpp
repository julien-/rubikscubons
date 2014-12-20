/*
 * Point.cpp
 *
 *  Created on: 19 déc. 2014
 *      Author: Julien
 */

#include "Point.h"
Point::Point() {
	// TODO Auto-generated constructor stub
}
Point::Point(GLfloat x, GLfloat y, GLfloat z){
	_x = x;
	_y = y;
	_z = z;
}

Point::~Point() {
	// TODO Auto-generated destructor stub
}

GLfloat Point::getX() const {
	return _x;
}

void Point::setX(GLfloat x) {
	_x = x;
}

GLfloat Point::getY() const {
	return _y;
}

void Point::setY(GLfloat y) {
	_y = y;
}

GLfloat Point::getZ() const {
	return _z;
}

void Point::setZ(GLfloat z) {
	_z = z;
}


bool operator==(Point const& p1, Point const& p2){
	return (p1.getX() == p2.getX() && p1.getY() == p2.getY() && p1.getZ() == p2.getZ());
}



