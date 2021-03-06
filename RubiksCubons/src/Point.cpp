/*
 * Point.cpp
 *
 *  Created on: 19 d�c. 2014
 *      Author: Julien
 */

#include "Point.h"
Point::Point(){
	_x = 0;
		_y = 0;
		_z = 0;
}
Point::Point(const Point &p) {
	_x = p._x;
	_y = p._y;
	_z = p._z;
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



