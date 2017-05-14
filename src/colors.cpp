#include "custom_ncurses.h"
#include "colors.h"

void initPairs() {
	init_pair(5, COLOR_BLUE, COLOR_WHITE); ///< Colors of player's rocket
	init_pair(1, COLOR_GREEN, COLOR_BLACK); ///< Colors of HugeBullets power-up
	init_pair(2, COLOR_RED, COLOR_BLACK); ///< Colors of FastBullets power-up
	init_pair(3, COLOR_CYAN, COLOR_BLACK); ///< Colors of TripleShot power-up
	init_pair(4, COLOR_YELLOW, COLOR_BLUE); ///< Colors of ClassicBullets power-down
}

void setColor(color COLOR) {
	switch (COLOR) {
		case PLAYER:
			attron(COLOR_PAIR(5));
			break;
		case HPOWER:
			attron(COLOR_PAIR(1));
			break;
		case FPOWER:
			attron(COLOR_PAIR(2));
			break;
		case TPOWER:
			attron(COLOR_PAIR(3));
			break;
		case CPOWER:
			attron(COLOR_PAIR(4));
			break;
		default:
			break;
	}
}

void resetColor(color COLOR) {
	switch (COLOR) {
		case PLAYER:
			attroff(COLOR_PAIR(5));
			break;
		case HPOWER:
			attroff(COLOR_PAIR(1));
			break;
		case FPOWER:
			attroff(COLOR_PAIR(2));
			break;
		case TPOWER:
			attroff(COLOR_PAIR(3));
			break;
		case CPOWER:
			attroff(COLOR_PAIR(4));
			break;
		default:
			break;
	}
}