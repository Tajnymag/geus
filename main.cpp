#include <ncurses/ncurses.h>
#include "src/engine.h"

using namespace std;

int main() {
	int max_x;
	int max_y;

	Engine engine(30);
	Hrac* hrac = new Hrac();
	engine.pridejGFXObjekt(hrac);

	while (1) {
		engine.nactiVelikostOkna();
		char c = getch();

		if (c == 'a') {
			hrac->rychlostX -= 1;
		} else if(c == 'd') {
			hrac->rychlostX += 1;
		}

		if (c == 'w') {
			hrac->rychlostY -= 1;
		} else if (c == 's') {
			hrac->rychlostY += 1;
		}

		if (c == 32) {
			engine.pridejGFXObjekt(new Strela("|", hrac->poziceX(), hrac->poziceY() - 1));
		}

		if (c == 27) {
			break;
		}

		engine.smazNeviditelneObjekty();
		engine.vykresliVse();
		engine.cekejFPS();
	}

	engine.ukonciNcurses();

	return 0;
}