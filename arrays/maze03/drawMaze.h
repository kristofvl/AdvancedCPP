/* Drawing functions declared */
#ifndef H_DRAWMAZE
#define H_DRAWMAZE

#include <ncurses.h>  // functions to draw colored text in terminal

// initialize all the functions to start drawing in ncurses and use color
void initNCurses();

// clear the screen
void clearScreen(int maze[][15]);

// draw a symbol at (x,y) with color colorpair
void draw(int x, int y, char symbol, int colorpair);

#endif
