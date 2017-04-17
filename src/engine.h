#ifndef GEUS_ENGINE_H
#define GEUS_ENGINE_H

class Engine {
private:
    // Deklarování objektu okna a rendereru
    SDL_Window* okno = NULL;
    SDL_Renderer* renderer = NULL;
public:
    int noveOkno(const char* nazev_okna, const int sirka, const int vyska, bool fullscreen);
    int premazOkno(const unsigned int red, const unsigned int green, const unsigned int blue);
};

extern Engine engine;
#endif //GEUS_ENGINE_H