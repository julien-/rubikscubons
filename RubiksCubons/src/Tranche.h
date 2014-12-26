
#ifndef TRANCHE_H_
#define TRANCHE_H_

#include "Cube.h"

class Tranche {
private:
	Cube *_tbCube[];
public:
	Tranche();
	Tranche(int axe, int size, Couleur tbCouleur[]);//axe =   0:x  1:y   2:z
	virtual ~Tranche();
	void afficher();
};

#endif /* TRANCHE_H_ */
