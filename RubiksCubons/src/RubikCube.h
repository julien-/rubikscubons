#ifndef RUBIKCUBE_H_
#define RUBIKCUBE_H_

#include "Cube.h"

class RubikCube {
private:
	int _size;
	//Tranche* _tbTranche[];//pointeur de tableaux de tranches (3  car x,y,z)
	Cube _tbCube[];
	Couleur _tbCouleur[6];//6 couleurs car 6 faces du rubikcube
public:
	RubikCube();
	RubikCube(int size, Couleur c1, Couleur c2, Couleur c3, Couleur c4, Couleur c5, Couleur c6 );
	virtual ~RubikCube();
	int getSize() const;
	void setSize(int size);
	void afficher();
};

#endif /* RUBIKCUBE_H_ */
