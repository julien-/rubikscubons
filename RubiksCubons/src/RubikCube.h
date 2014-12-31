#ifndef RUBIKCUBE_H_
#define RUBIKCUBE_H_

#include "Cube.h"
#include "Point.h"
#include "Tranche.h"

class RubikCube {
private:
	int _size;
	Point *_centre;
	//Tranche* _tbTranche[];//pointeur de tableaux de tranches (3  car x,y,z)
	vector<Cube *> _tbCube;

	Tranche ** tranches;
	int NTranches = 3;

public:
	RubikCube(int size);
	virtual ~RubikCube();
	int getSize() const;
	void setSize(int size);
	void afficher();
	const Point* getCentre() const;
	void setCentre(const Point* centre);
	void Rotation(char XYZ, int angle);
	void Deplacement(GLfloat x, GLfloat y, GLfloat z);
	void RotateTranche( int angle, int tranche);
	int getAngle(int tranche);
};

#endif /* RUBIKCUBE_H_ */
