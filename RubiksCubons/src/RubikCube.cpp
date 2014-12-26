/*
 * RubikCube.cpp
 *
 *  Created on: 24 déc. 2014
 *      Author: Julien
 */

#include "RubikCube.h"

RubikCube::RubikCube() {
	// TODO Auto-generated constructor stub

}

RubikCube::RubikCube(int size, Couleur c1, Couleur c2, Couleur c3, Couleur c4, Couleur c5, Couleur c6 ) {
	_size = size;

	//Creation des 6 différentes couleurs
	_tbCouleur[0] = c1;	//Couleur *rouge = new Couleur(1.0, 0.0, 0.0);
	_tbCouleur[1] = c2; //Couleur *vert = new Couleur(0.0, 1.0, 0.0);
	_tbCouleur[1] = c3; //Couleur *bleu = new Couleur(0.0, 0.0, 1.0);
	_tbCouleur[1] = c4; //Couleur *jaune = new Couleur(1.0, 1.0, 0.0);
	_tbCouleur[1] = c5; //Couleur *blanc = new Couleur(1.0, 1.0, 1.0);
	_tbCouleur[1] = c6; //Couleur *orange = new Couleur(1.0, 0.5, 0.0);

	//_tbTranche est un tableau de tranches (size*3  car x,y,z)
	_tbTranche[0] = new Tranche(0, _size, _tbCouleur);//axe des X
	//_tbTranche[1] = new Tranche(1, _size, _tbCouleur);//axe des Y
	//_tbTranche[2] = new Tranche(2, _size, _tbCouleur);//axe des Z

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
	//On affiche que "size" tranches car les tranches restantes seront déjà visibles avec celles affichées
	//car tous leurs cubes font parties d'autres tranches
	//for (int axe = 0; axe < 3; ++axe)
			_tbTranche[0]->afficher();

}
