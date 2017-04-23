#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <string>
#include "sprite.h"

Sprite::Sprite(std::string cesta, SDL_Renderer* renderer) : obrazek(NULL){
	pozice_x = 0;
	pozice_y = 0;

	obrazek = SDL_CreateTextureFromSurface(renderer, IMG_Load(cesta.c_str()));

	fyzicky_objekt.x = pozice_x;
	fyzicky_objekt.y = pozice_y;
	fyzicky_objekt.w = sirka_textury;
	fyzicky_objekt.h = vyska_textury;
}
Sprite::~Sprite() {}