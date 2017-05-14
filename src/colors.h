/**
 * This header file contains helper functions to ease coloring of my custom sprites.
 */

#ifndef GEUS_COLORS_H
#define GEUS_COLORS_H

enum color {
	PLAYER, HPOWER, TPOWER, CPOWER, FPOWER
};

/// Initialiases our custom color palette
void initPairs();

/// Sets current color used for all the drawing
void setColor(color COLOR);

/// Resets current color used for all the drawing
void resetColor(color COLOR);

#endif //GEUS_COLORS_H
