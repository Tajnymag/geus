#ifndef GEUS_SPRITE_H
#define GEUS_SPRITE_H

class Sprite {
private:
	SDL_Texture* obrazek;
	SDL_Rect fyzicky_objekt;

	int sirka_textury;
	int vyska_textury;
public:
	int pozice_x;
	int pozice_y;
	Sprite(std::string cesta, SDL_Renderer* renderer);
	~Sprite();

	void render(SDL_Renderer* renderer) {
		SDL_RenderCopy(renderer, obrazek, NULL, NULL);
	}
};

#endif //GEUS_SPRITE_H