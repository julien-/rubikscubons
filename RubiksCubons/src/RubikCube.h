#ifndef RUBIKCUBE_H_
#define RUBIKCUBE_H_

#include "Cube.h"

class RubikCube {
private:
	int _size;
	//Tranche* _tbTranche[];//pointeur de tableaux de tranches (3  car x,y,z)
	Cube *_tbCube[];
public:
	RubikCube();
	RubikCube(int size);
	virtual ~RubikCube();
	int getSize() const;
	void setSize(int size);
	void afficher();
};

#endif /* RUBIKCUBE_H_ */
