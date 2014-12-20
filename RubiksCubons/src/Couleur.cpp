/*
 * Couleur.cpp
 *
 *  Created on: 20 déc. 2014
 *      Author: Julien
 */

#include "Couleur.h"

Couleur::Couleur() {
	// TODO Auto-generated constructor stub

}

float Couleur::getB() const {
	return _b;
}

void Couleur::setB(float b) {
	this->_b = b;
}

float Couleur::getR() const {
	return _r;
}

void Couleur::setR(float r) {
	this->_r = r;
}

float Couleur::getV() const {
	return _v;
}

Couleur::Couleur(float r, float v, float b) {
	_r = r;
	_v = v;
	_b = b;
}

void Couleur::setV(float v) {
	this->_v = v;
}

Couleur::~Couleur() {
	// TODO Auto-generated destructor stub
}

