#include <SDL2/SDL.h>
#include "engine.h"

int Engine::noveOkno(const char* nazev_okna, const int sirka, const int vyska, bool fullscreen) {
    // Inicializace všech modulů knihovny SDL2
    SDL_Init(SDL_INIT_EVERYTHING);

    // Vytvoření nového okna
    if (fullscreen) {
        okno = SDL_CreateWindow(nazev_okna, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, sirka, vyska, SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_ALLOW_HIGHDPI);
    } else {
        okno = SDL_CreateWindow(nazev_okna, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, sirka, vyska, SDL_WINDOW_ALLOW_HIGHDPI);
    }

    // Přiřazení renderovacího manažera k oknu
    renderer = SDL_CreateRenderer(okno, -1, 0);
}

int Engine::premazOkno(const unsigned int red, const unsigned int green, const unsigned int blue) {
    // Nastavení barvy, kterou použijeme při příští operaci
    SDL_SetRenderDrawColor(renderer, red, green, blue, 255);

    // Přemazání všeho námi zvolenou barvou
    SDL_RenderClear(renderer);

    // Zobrazení obrazu z bufferu na displej
    SDL_RenderPresent(renderer);
}