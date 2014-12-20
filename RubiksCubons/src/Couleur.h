#ifndef COULEUR_H_
#define COULEUR_H_

class Couleur {
private:
	float _r, _v, _b;
public:
	Couleur();
	Couleur(float r, float v, float b);
	virtual ~Couleur();
	float getB() const;
	void setB(float b);
	float getR() const;
	void setR(float r);
	float getV() const;
	void setV(float v);
};

#endif /* COULEUR_H_ */
