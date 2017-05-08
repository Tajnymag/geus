#ifndef GEUS_ENGINE_H
#define GEUS_ENGINE_H

#include <vector>
#include <memory>
#include "sprite.h"

class Engine {
private:
	int m_sirka_okna;
	int m_vyska_okna;

	int m_obnovovaci_frekvence;

	std::vector<Sprite*> m_seznam_gfx_objektu;
public:
	Engine(const int cileny_framerate);
	~Engine();

	int getSirkaOkna() const;
	int getVyskaOkna() const;

	void pridejGFXObjekt(Sprite* objekt);
	void vykresliVse();
	void smazNeviditelneObjekty();
	void cekejFPS();
	void ukonciNcurses();
	void nactiVelikostOkna();
};

#endif //GEUS_ENGINE_H
