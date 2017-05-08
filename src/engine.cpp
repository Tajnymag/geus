#include <ncurses/ncurses.h>
#include <thread>
#include "sprite.h"
#include "engine.h"

Engine::Engine(const int cileny_framerate) {
	m_obnovovaci_frekvence = 1000 / cileny_framerate;

	initscr();
	clear();
	noecho();
	curs_set(0);
	cbreak();
	nodelay(stdscr, true);
}
Engine::~Engine() {
	for (auto gfx_objekt : m_seznam_gfx_objektu) {
		delete gfx_objekt;
	}

	m_seznam_gfx_objektu.clear();
}

int Engine::getSirkaOkna() const {
	return m_sirka_okna;
}
int Engine::getVyskaOkna() const {
	return m_vyska_okna;
}

void Engine::pridejGFXObjekt(Sprite* objekt) {
	m_seznam_gfx_objektu.push_back(objekt);
}
void Engine::vykresliVse() {
	clear();
	for (auto gfx_objekt : m_seznam_gfx_objektu) {
		gfx_objekt->handleKolizeOkna(m_sirka_okna, m_vyska_okna);
		gfx_objekt->vykresli();
	}
	//refresh();
}
void Engine::smazNeviditelneObjekty() {
	for (int i = 0; i < (int)m_seznam_gfx_objektu.size(); ++i) {
		if (!m_seznam_gfx_objektu[i]->viditelny()) {
			delete m_seznam_gfx_objektu[i];
			m_seznam_gfx_objektu.erase(m_seznam_gfx_objektu.begin() + i);
		}
	}
}
void Engine::cekejFPS() {
	std::this_thread::sleep_for(std::chrono::milliseconds(m_obnovovaci_frekvence));
}
void Engine::ukonciNcurses() {
	endwin();
}
void Engine::nactiVelikostOkna() {
	getmaxyx(stdscr, m_vyska_okna, m_sirka_okna);
}