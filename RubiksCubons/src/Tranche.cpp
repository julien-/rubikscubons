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
	//Creation des (size * size * size) cubes
	//   p4---------------p5
	//  /|               / |
	// / |              /  |
	//p0--------------p1   |
	//|  |             |   |
	//|  |             |   |
	//|  p7------------|--p6
	//|  /             |  /
	//| /              | /
	//|/               |/
	//p3---------------p2
	float decalage = 0.01;
	float xdepart = -0.9;
	float ydepart = 0.9;
	float zdepart = 0.9;
	float taille = 1.8/size;//environ 2.0 car de -1.0 à 1.0 et une marge pour pas que ca prenne tout l'écran
	int count = 0;//il y aura size*size*size cubes
	for (float x = xdepart; x <= -xdepart; x+=taille+decalage) {
		for (float y = ydepart; y >= -ydepart; y-=taille+decalage) {
			for (float z = zdepart; z >= -zdepart; z-=taille+decalage) {
				_tbCube[count] =  new Cube(taille, Point(x, y, z),tbCouleur[0],tbCouleur[1],tbCouleur[2],tbCouleur[3],tbCouleur[4],tbCouleur[5]);

				count++;
			}
		}
	}
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
		_tbCube[i]->afficher();
	}
}
