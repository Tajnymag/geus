#ifndef GEUS_COLORS_H
#define GEUS_COLORS_H

enum color {
	BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, HRAC
};

void initPairs();
void setColor(color COLOR);
void resetColor(color COLOR);

#endif //GEUS_COLORS_H
