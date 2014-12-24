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

RubikCube::RubikCube(int size){
	//_tbCube a la taille de _size*_size*_size
	//_tbTranche a la taille de _size*_size

	//Creation des 6 différentes couleurs
	  Couleur *rouge = new Couleur(1.0, 0.0, 0.0);
	  Couleur *vert = new Couleur(0.0, 1.0, 0.0);
	  Couleur *bleu = new Couleur(0.0, 0.0, 1.0);
	  Couleur *jaune = new Couleur(1.0, 1.0, 0.0);
	  Couleur *blanc = new Couleur(1.0, 1.0, 1.0);
	  Couleur *orange = new Couleur(1.0, 0.5, 0.0);

	  for (int i = 0; i < size*size*size; ++i) {
	  //Creation d'un cube
	  _tbCube[i] =  new Cube(
	    		Point(-0.5+i, -0.5+i, 0.5+i),
	    		Point(-0.5+i, 0.5+i, 0.5+i),
	    		Point(0.5+i, 0.5+i, 0.5+i),
	    		Point(0.5+i,-0.5+i, 0.5+i),
	    		Point(-0.5+i,-0.5+i,-0.5+i),
	    		Point(-0.5+i, 0.5+i,-0.5+i),
	    		Point(0.5+i, 0.5+i,-0.5+i),
	    		Point(0.5+i,-0.5+i,-0.5+i),
	    		*rouge,
	    		*vert,
	    		*bleu,
	    		*jaune,
	    		*blanc,
	    		*orange);
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

void RubikCube::afficher(){
	for (int i = 0; i < _size*_size*_size; ++i) {
		_tbCube[i]->afficher();
	}
}
