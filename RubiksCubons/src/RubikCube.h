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
	int nbCubesInTranche;

	const char* filename[2]; //Path to texture
	bool textureMode;
	int selectedTexture = 0;
	int isCustomAnimPlaing; //0 =no, 1 = fisrt activated, 2 second is activated
	float offset;
	bool animationDirectionFlag;



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
	void loadTexture(int index);
	int getSelectedtexture();
	void setShining(bool arg);
	void StartCustomtAnimation1();
	void StartCustomtAnimation2();
	void updateAnim(int animID);
	void StopCustomAnimation();
	float Random( float min, float max);
};

#endif /* RUBIKCUBE_H_ */
