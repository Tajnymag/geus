#ifndef GEUS_GAME_H
#define GEUS_GAME_H

#include <SDL2/SDL.h>
#include <map>
#include "sprite.h"
#include "hra.h"
#include "barva.h"

class Game {
public:
	Game(const char* jmeno_hry, const int sirka, const int vyska, const int cilene_fps, Barva barva_pozadi);
	~Game();
	void start();
	void stop() ;
	void vykresli();
	void vyplnObdelnik(SDL_Rect *rc, int r, int g, int b);
	void vykresliFPS(int fps);
	void ukonciSmycku();
	void onKeyDown( SDL_Event* event );
	void onKeyUp( SDL_Event* event );
	void spustit();
	void update();
	SDL_Renderer* renderer;
private:
	std::string m_jmeno_hry;

	int m_sirka_okna;
	int m_vyska_okna;
	int m_update_frekvence;
	int m_frameSkip;
	int m_ukoncit;

	int HERO_SPEED = 5; //TODO - smazat

	std::map<int,int> keys;
	SDL_Window* okno;

	Barva m_barva_pozadi;
};

#endif //GEUS_GAME_H