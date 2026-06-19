/* Class Player: All data and functions related to a player */
#include "Player.h"  // class definition

void Player::move(char key, const Maze & maze) {
  if (key == up) { if (!maze.get(x, y-1) && y>0) y--; }
  else if (key == down) { if (!maze.get(x, y+1) && y<LINES-1) y++; }
  else if (key == left) { if (!maze.get(x-1, y) && x>0) x--; }
  else if (key == right) { if (!maze.get(x+1, y) && x<COLS-1) x++; }
}

// draw the player as symbol, in colorpair:
void Player::draw(char symbol, int colorpair, char key, const Maze & maze) {
  move(key, maze);
  attron(COLOR_PAIR(colorpair));  // set color pair
  mvaddch(y, x, symbol);  // draw player at (x,y)
  attroff(COLOR_PAIR(colorpair));
}
