#ifndef COULEUR_H_
#define COULEUR_H_

class Couleur {
private:
	float _r, _v, _b;
public:
	Couleur();
	Couleur(const Couleur &c);
	Couleur(float r, float v, float b);
	virtual ~Couleur();
	float getB() const;
	void setB(float b);
	float getR() const;
	void setR(float r);
	float getV() const;
	void setV(float v);
	static Couleur blanc();
	static Couleur rouge();
	static Couleur vert();
	static Couleur bleu();
	static Couleur jaune();
	static Couleur orange();

};

#endif /* COULEUR_H_ */
