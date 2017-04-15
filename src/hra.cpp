#include <iostream>
#include <SDL2/SDL.h>
#include "hra.h"
#include "engine.h"

int CHra::menu() {
    primarniSmycka();
}

int CHra::primarniSmycka() {
    bool ukoncit = false;
    SDL_Event event;

    while (!ukoncit) {
        // Načtení eventu
        SDL_WaitEvent(&event);

        // Kontrola o jaký event šlo
        switch (event.type) {
            case SDL_QUIT:
                ukoncit = true;
                break;
        }
    }

    // Ukončení celého grafického kontextu SDL2
    SDL_Quit();
    return 0;
}

int CHra::start() {
    Engine engine;
    engine.noveOkno("NULL", 360, 640, false);
    engine.premazOkno(0, 0, 0);

    menu();
}