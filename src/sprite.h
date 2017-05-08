#ifndef GEUS_SPRITE_H
#define GEUS_SPRITE_H

class Sprite {
protected:
	const char* m_reprezentujici_znak;
	bool m_viditelny;

	int m_x;
	int m_y;

	double m_treni;
public:
	double rychlostX;
	double rychlostY;

	Sprite(const char* reprezentujici_znak);
	virtual ~Sprite();

	virtual void vypocitejNovouPozici();
	bool viditelny() const;
	int poziceX() const;
	int poziceY() const;

	virtual void vykresli();
	virtual void handleKolizeOkna(const int sirka_okna, const int vyska_okna);
};

class Hrac : public Sprite {
private:
	int power_up;
public:
	Hrac();
	~Hrac();

	void vykresli();
	void handleKolizeOkna(const int sirka_okna, const int vyska_okna);
};

class Strela : public Sprite {
public:
	Strela(const char* reprezentujici_znak, const int poc_x, const int poc_y);
	~Strela();
};

#endif //GEUS_SPRITE_H
