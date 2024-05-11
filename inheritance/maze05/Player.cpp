/* Class Player: All data and functions related to a player */
#include "Player.h"  // class definition

// initialize maze data and set up window in ncurses, use color
Player::Player(int16_t x, int16_t y) {
  // initialize player position:
  this->x = x; this->y = y;
	init_pair(3, COLOR_WHITE, COLOR_BLACK);  // player color
}

// draw the player as symbol, in colorpair:
void Player::draw(char symbol, int colorpair) {
	attron(COLOR_PAIR(colorpair));  // set color pair to 1
  mvaddch(y, x, symbol);  // draw player at (x,y)
  attroff(COLOR_PAIR(colorpair));
}
