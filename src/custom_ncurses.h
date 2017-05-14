/**
 * This header file came as a workaround to overcome differences in NCureses location on different platforms.
 * It's much easier to do and maintain such method as a compiler macro than to do it in a Makefile.
 */

#ifndef GEUS_CUSTOM_NCURSES_H
#define GEUS_CUSTOM_NCURSES_H

#ifdef __MINGW64__
	#include <ncurses/ncurses.h>
	
#elif defined __linux__ || defined __APPLE__
	#include <ncurses.h>
	
#endif

#endif //GEUS_CUSTOM_NCURSES_H
