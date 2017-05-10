#ifndef GEUS_CUSTOM_NCURSES_H
#define GEUS_CUSTOM_NCURSES_H

#ifdef __MINGW64__
	#include <ncurses/ncurses.h>
#endif
#ifdef __linux__
	#include <ncurses.h>
#endif

#endif //GEUS_CUSTOM_NCURSES_H
