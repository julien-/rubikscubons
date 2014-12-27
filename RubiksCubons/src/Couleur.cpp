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

Couleur::Couleur(const Couleur &c){
	_r = c._r;
	_v = c._v;
	_b = c._b;
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

Couleur Couleur::blanc(){
	return Couleur(1.0, 1.0, 1.0);
}

Couleur Couleur::rouge(){
	return Couleur(1.0, 0.0, 0.0);
}

Couleur Couleur::vert(){
	return Couleur(0.0, 1.0, 0.0);
}

Couleur Couleur::bleu(){
	return Couleur(0.0, 0.0, 1.0);
}

Couleur Couleur::jaune(){
	return Couleur(1.0, 1.0, 0.0);
}

Couleur Couleur::orange(){
	return Couleur(1.0, 0.5, 0.0);
}

Couleur Couleur::noir(){
	return Couleur(0.0, 0.0, 0.0);
}
