#ifndef RUBIKCUBE_H_
#define RUBIKCUBE_H_

#include "Tranche.h"

class RubikCube {
private:
	int _size;
	Tranche *_tbTranche[];
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
