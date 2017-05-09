#ifdef __MINGW64__ 
    #include <ncurses/ncurses.h>
#endif
#ifdef __linux__
    #include <ncurses.h>
#endif
#include <cmath>
#include "sprite.h"

Sprite::Sprite(const char* reprezentujici_znak) : m_reprezentujici_znak(reprezentujici_znak){
	m_viditelny = true;
	m_x = 0;
	m_y = 0;

	rychlostX = 0;
	rychlostY = 0;
	m_treni = 0.2;
}
Sprite::~Sprite() {}

void Sprite::vypocitejNovouPozici() {
	if (rychlostX > 0) {
		m_x += ceil(rychlostX -= m_treni);
	} else {
		m_x += (rychlostX += m_treni);
	}
	if (rychlostY > 0) {
		m_y += ceil(rychlostY -= m_treni);
	} else {
		m_y += (rychlostY += m_treni);
	}
}
bool Sprite::viditelny() const {
	return m_viditelny;
}
int Sprite::poziceX() const {
	return m_x;
}
int Sprite::poziceY() const {
	return m_y;
}

void Sprite::vykresli() {
	vypocitejNovouPozici();

	if (m_viditelny) {
		mvprintw(m_y, m_x, m_reprezentujici_znak);
	}
}
void Sprite::handleKolizeOkna(const int sirka_okna, const int vyska_okna) {
	if (this->m_x >= sirka_okna) {
		m_viditelny = false;
	} else if (this->m_x < 0) {
		m_viditelny = false;
	}

	if (this->m_y >= vyska_okna) {
		m_viditelny = false;
	} else if (this->m_y < 0) {
		m_viditelny = false;
	}
}

/** -------------------------------------------------------------------- **/

Hrac::Hrac() : Sprite("") {
	power_up = 0;
	m_x = 1;
	m_y = 1;
}
Hrac::~Hrac() {}
void Hrac::vykresli() {
	vypocitejNovouPozici();

	if (m_viditelny) {
		mvprintw(m_y - 1, m_x, ".");
		mvprintw(m_y, m_x - 1, "/#\\");
	}
}
void Hrac::handleKolizeOkna(const int sirka_okna, const int vyska_okna) {
	if (this->m_x + 1 >= sirka_okna) {
		this->m_x = sirka_okna - 2;
		this->rychlostX *= -1;
	} else if (this->m_x - 1 < 0) {
		this->m_x = 1;
		this->rychlostX *= -1;
	}

	if (this->m_y + 1 >= vyska_okna) {
		this->m_y = vyska_okna - 1;
		this->rychlostY *= -1;
	} else if (this->m_y - 1 < 0) {
		this->m_y = 1;
		this->rychlostY *= 1;
	}
}

/** -------------------------------------------------------------------- **/

Strela::Strela(const char* reprezentujici_znak, const int poc_x, const int poc_y) : Sprite(reprezentujici_znak) {
	m_viditelny = true;
	m_x = poc_x;
	m_y = poc_y;

	rychlostX = 0;
	rychlostY = -1;
	m_treni = 0;
}
Strela::~Strela() {

}