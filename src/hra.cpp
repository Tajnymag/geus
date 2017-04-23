#include <SDL2/SDL.h>
#include <map>
#include <SDL_image.h>
#include "sprite.h"
#include "hra.h"

Game::Game(const char* jmeno_hry, const int sirka, const int vyska, const int cilene_fps, Barva barva_pozadi) : m_jmeno_hry(jmeno_hry), okno(NULL), renderer(NULL){
	m_frameSkip = 0;
	m_ukoncit = 0;
	m_sirka_okna = sirka;
	m_vyska_okna = vyska;
	m_update_frekvence = 1000 / cilene_fps;

	m_barva_pozadi = barva_pozadi;
}

Game::~Game() {
	this->stop();
}

void Game::start() {
	if (SDL_Init(SDL_INIT_EVERYTHING)) {
		throw "Nepovedlo se nacist nejaky SDL modul";
	}

	okno = SDL_CreateWindow(m_jmeno_hry.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_sirka_okna, m_vyska_okna, SDL_WINDOW_ALLOW_HIGHDPI);
	renderer = SDL_CreateRenderer(okno, -1, SDL_RENDERER_ACCELERATED);

	m_ukoncit = 0;
	spustit();
}

void Game::vykresli() {
	// Clear screen
	SDL_SetRenderDrawColor(renderer, m_barva_pozadi.r, m_barva_pozadi.g, m_barva_pozadi.b, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}

void Game::stop() {
	if (renderer != NULL) {
		SDL_DestroyRenderer(renderer);
		renderer = NULL;
	}
	if (okno != NULL) {
		SDL_DestroyWindow(okno);
		okno = NULL;
	}
	SDL_Quit();
}

void Game::vyplnObdelnik(SDL_Rect *rc, int r, int g, int b) {
	SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(renderer, rc);
}

void Game::vykresliFPS(int fps) {
	std::string nadpis_okna = m_jmeno_hry + " - fps: " + std::to_string(fps);
	SDL_SetWindowTitle(okno, nadpis_okna.c_str());
}

void Game::ukonciSmycku() {
	m_ukoncit = 1;
}

void Game::spustit() {
	int past = SDL_GetTicks();
	int now = past;
	int pastFps = past;
	int fps = 0;
	int framesSkipped = 0;

	Sprite hero("fff.bmp", renderer);

	SDL_Event event;
	while (!m_ukoncit) {
		int timeElapsed = 0;
		if (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT:
					ukonciSmycku();
					break;
				case SDL_KEYDOWN:
					onKeyDown(&event);
					break;
				case SDL_KEYUP:
					onKeyUp(&event);
					break;
				case SDL_MOUSEBUTTONDOWN:
				case SDL_MOUSEBUTTONUP:
				case SDL_MOUSEMOTION:
					break;
			}
		}
		// update/vykresli
		timeElapsed = (now = SDL_GetTicks()) - past;
		if (timeElapsed >= m_update_frekvence) {
			past = now;
			update();
			if (framesSkipped++ >= m_frameSkip) {
				vykresli();
				++fps;
				framesSkipped = 0;
			}
		}
		// fps
		if (now - pastFps >= 1000) {
			pastFps = now;
			vykresliFPS(fps);
			fps = 0;
		}
		// sleep?
		SDL_Delay(1);
	}
}

void Game::update() {
	if (keys[SDLK_LEFT] || keys[SDLK_a]) {
		//hero.pozice_x -= HERO_SPEED;
	} else if (keys[SDLK_RIGHT]) {
		//hero.pozice_x += HERO_SPEED;
	}

	if (keys[SDLK_UP]) {
		//hero.pozice_y -= HERO_SPEED;
	} else if (keys[SDLK_DOWN]) {
		//hero.pozice_y += HERO_SPEED;
	}
}

void Game::onKeyDown(SDL_Event *evt) {
	keys[evt->key.keysym.sym] = 1;
}

void Game::onKeyUp(SDL_Event *evt) {
	keys[evt->key.keysym.sym] = 0;
}