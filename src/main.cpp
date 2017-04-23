#include <iostream>
#include "hra.h"
#include "barva.h"

using namespace std;

int main(int argc, char** argv){
	int sirka_okna = 720;
	int vyska_okna = 1024;
	int cilene_fps = 60;

	Barva barva_pozadi;
	barva_pozadi.r = 255;
	barva_pozadi.g = 255;
	barva_pozadi.b = 0;

	if (argc > 2) {
		sirka_okna = atoi(argv[1]);
		vyska_okna = atoi(argv[2]);

		if (argc > 3) {
			cilene_fps = atoi(argv[3]);
		}

		cout << sirka_okna << "x" << vyska_okna << " pri " << cilene_fps << "fps" << endl;
	}

	Game game("Geus", sirka_okna, vyska_okna, cilene_fps, barva_pozadi);
	game.start();
	return 0;
}