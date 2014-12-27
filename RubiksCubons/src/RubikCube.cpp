#include <cstdio>
#include <new>

#include "Couleur.h"
#include "Point.h"

/*
 * RubikCube.cpp
 *
 *  Created on: 24 déc. 2014
 *      Author: Julien
 */
using namespace std;
#include <new>

#include "RubikCube.h"

RubikCube::RubikCube() {
	// TODO Auto-generated constructor stub

}

RubikCube::RubikCube(int size, Couleur c1, Couleur c2, Couleur c3, Couleur c4, Couleur c5, Couleur c6 ) {
	try{
	_size = size;

	//Creation des 6 différentes couleurs
	_tbCouleur[0] = c1;	//Couleur *rouge = new Couleur(1.0, 0.0, 0.0);
	_tbCouleur[1] = c2; //Couleur *vert = new Couleur(0.0, 1.0, 0.0);
	_tbCouleur[2] = c3; //Couleur *bleu = new Couleur(0.0, 0.0, 1.0);
	_tbCouleur[3] = c4; //Couleur *jaune = new Couleur(1.0, 1.0, 0.0);
	_tbCouleur[4] = c5; //Couleur *blanc = new Couleur(1.0, 1.0, 1.0);
	_tbCouleur[5] = c6; //Couleur *orange = new Couleur(1.0, 0.5, 0.0);


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
		float xdepart = -0.5;
		float ydepart = 0.5;
		float zdepart = -0.5;
		float taille = 1.0/size;//environ 2.0 car de -1.0 à 1.0 et une marge pour pas que ca prenne tout l'écran
		int count = 0;//il y aura size*size*size cubes

		//_tbCube[0] =  Cube(taille, Point(xdepart, ydepart, zdepart),_tbCouleur[0],_tbCouleur[1],_tbCouleur[2],_tbCouleur[3],_tbCouleur[4],_tbCouleur[5]);
		//_tbCube[1] =  new Cube(taille, Point(xdepart+taille+decalage, ydepart, zdepart),_tbCouleur[0],_tbCouleur[1],_tbCouleur[2],_tbCouleur[3],_tbCouleur[4],_tbCouleur[5]);

		for (float x = xdepart; x <= -xdepart; x+=taille+decalage) {
			for (float y = ydepart; y >= -ydepart; y-=taille+decalage) {
				for (float z = zdepart; z <= -zdepart; z+=taille+decalage) {
					_tbCube[count] =  Cube(taille, Point(x, y, z),_tbCouleur[0],_tbCouleur[1],_tbCouleur[2],_tbCouleur[3],_tbCouleur[4],_tbCouleur[5]);

					count++;
				}
			}
		}




	//_tbTranche est un tableau de tranches (size*3  car x,y,z)
	//_tbTranche[0] = new Tranche(0, _size, _tbCouleur);//axe des X
	//_tbTranche[1] = new Tranche(1, _size, _tbCouleur);//axe des Y
	//_tbTranche[2] = new Tranche(2, _size, _tbCouleur);//axe des Z
	}
	catch (bad_alloc& ba)
	{
		printf("###########################BAD ALLOC #######################################\n");
	}
}

int RubikCube::getSize() const {
	return _size;
}

void RubikCube::setSize(int size) {
	_size = size;
}

RubikCube::~RubikCube() {
	// TODO Auto-generated destructor stub
}

void RubikCube::afficher() {
	try{
		//_tbCube[0].afficher();
	//	int u1 = sizeof(*_tbCube);
		//int u2 = sizeof(_tbCube);
	for (unsigned int i = 0; i < _size*_size*_size; ++i)
		_tbCube[i].afficher();
}
	catch (bad_alloc& ba)
	{
		printf("###########################BAD ALLOC #######################################\n");
	}
}
