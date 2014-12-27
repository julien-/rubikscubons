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

RubikCube::RubikCube(int size) {
	try{
	_size = size;
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
		float taille = 1.0/size;//taille d'un cube(size est le nombre de cube de large)

		//_tbCube[0] =  Cube(taille, Point(xdepart, ydepart, zdepart),_tbCouleur[0],_tbCouleur[1],_tbCouleur[2],_tbCouleur[3],_tbCouleur[4],_tbCouleur[5]);
		//_tbCube[1] =  new Cube(taille, Point(xdepart+taille+decalage, ydepart, zdepart),_tbCouleur[0],_tbCouleur[1],_tbCouleur[2],_tbCouleur[3],_tbCouleur[4],_tbCouleur[5]);

		for (float x = xdepart; x < -xdepart; x+=taille+decalage) {
			//for (float y = ydepart; y > -ydepart; y-=taille+decalage) {
			//	for (float z = zdepart; z < -zdepart; z+=taille+decalage) {
					//_tbCube[count] =  Cube(taille, Point(x, y, z),_tbCouleur[0],_tbCouleur[1],_tbCouleur[2],_tbCouleur[3],_tbCouleur[4],_tbCouleur[5]);
			_tbCube.push_back(new Cube(taille, Point(x, ydepart, zdepart)));
				//}
			//}
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
	for (int i = 0; i < _tbCube.size(); ++i)
		_tbCube[i]->afficher();
}
	catch (bad_alloc& ba)
	{
		printf("###########################BAD ALLOC #######################################\n");
	}
}
