
#ifndef TRANCHE_H_
#define TRANCHE_H_

#include "Cube.h"

class Tranche {
private:
	vector<Cube> _tbCube;

	int rotationAngle;
	int nbCubesInTranche;
	int * cubes;

public:

	Tranche(int nbCubesInTranche);
	Tranche();
	//Tranche(int axe, int size, Couleur tbCouleur[]);//axe =   0:x  1:y   2:z
	virtual ~Tranche();
	void afficher();
	void setAngle(int rotationAngle);
	int getAngle();
	int getCube(int i);
	void setCube(int pos, int val);
	int getnbCubesInTranche();
};

#endif /* TRANCHE_H_ */
