/*
 * Tranche.cpp
 *
 *  Created on: 24 déc. 2014
 *      Author: Julien
 */

#include "Tranche.h"

Tranche::Tranche(int nbCubesInTranche) {

	this->cubes = new int[nbCubesInTranche];

	this->nbCubesInTranche = nbCubesInTranche;
	this->rotationAngle =0;
}
Tranche::Tranche(){
	this->nbCubesInTranche =  0;
	this->rotationAngle =0;
}
/*
Tranche::Tranche(int axe, int size, Couleur tbCouleur[]){

	//for (GLfloat x = -1.f; x <= +1.f; x += largCube)
	        //for (GLfloat y = -1.f; y <= +1.f; y += largCube)
	            //for (GLfloat z = -1.f; z <= +1.f; z += largCube){
	                //if (x != y || y != z || z != 0.f)

	                	//c++;
	            //}


}*/

Tranche::~Tranche() {
	// TODO Auto-generated destructor stub
	delete [] cubes;
}

void Tranche::afficher() {
	for (unsigned int i = 0; i < sizeof(_tbCube); ++i) {
		_tbCube[i].afficher();
	}
}

void Tranche::setAngle(int rotationAngle) {
	this->rotationAngle = rotationAngle;
}

int Tranche::getAngle() {
	return this->rotationAngle;
}

int Tranche::getCube(int i) {
	return this->cubes[i];
}
void Tranche::setCube(int pos, int val){
	this->cubes[pos] = val;
}
int Tranche::getnbCubesInTranche(){
	return this->nbCubesInTranche;
}
