/*
 * Tranche.cpp
 *
 *  Created on: 24 déc. 2014
 *      Author: Julien
 */

#include "Tranche.h"

Tranche::Tranche() {
	// TODO Auto-generated constructor stub

}


Tranche::Tranche(int axe, int size, Couleur tbCouleur[]){

	//for (GLfloat x = -1.f; x <= +1.f; x += largCube)
	        //for (GLfloat y = -1.f; y <= +1.f; y += largCube)
	            //for (GLfloat z = -1.f; z <= +1.f; z += largCube){
	                //if (x != y || y != z || z != 0.f)

	                	//c++;
	            //}


}

Tranche::~Tranche() {
	// TODO Auto-generated destructor stub
}

void Tranche::afficher(){
	for (unsigned int i = 0; i < sizeof(_tbCube); ++i) {
		_tbCube[i].afficher();
	}
}
