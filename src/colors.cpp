#include "custom_ncurses.h"
#include "colors.h"

void initPairs() {
	init_pair(0, COLOR_BLACK, COLOR_BLACK);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(8, COLOR_BLUE, COLOR_WHITE);
}

void setColor(color COLOR) {
	switch (COLOR) {
		case BLACK:
			attron(COLOR_PAIR(0));
			break;
		case RED:
			attron(COLOR_PAIR(1));
			break;
		case GREEN:
			attron(COLOR_PAIR(2));
			break;
		case YELLOW:
			attron(COLOR_PAIR(3));
			break;
		case BLUE:
			attron(COLOR_PAIR(4));
			break;
		case MAGENTA:
			attron(COLOR_PAIR(5));
			break;
		case CYAN:
			attron(COLOR_PAIR(6));
			break;
		case WHITE:
			attron(COLOR_PAIR(7));
			break;
		case HRAC:
			attron(COLOR_PAIR(8));
			break;
		default:
			attron(COLOR_PAIR(0));
			break;
	}
}

void resetColor(color COLOR) {
	switch (COLOR) {
		case BLACK:
			attroff(COLOR_PAIR(0));
			break;
		case RED:
			attroff(COLOR_PAIR(1));
			break;
		case GREEN:
			attroff(COLOR_PAIR(2));
			break;
		case YELLOW:
			attroff(COLOR_PAIR(3));
			break;
		case BLUE:
			attroff(COLOR_PAIR(4));
			break;
		case MAGENTA:
			attroff(COLOR_PAIR(5));
			break;
		case CYAN:
			attroff(COLOR_PAIR(6));
			break;
		case WHITE:
			attroff(COLOR_PAIR(7));
			break;
		case HRAC:
			attroff(COLOR_PAIR(8));
			break;
		default:
			attroff(COLOR_PAIR(0));
			break;
	}
}