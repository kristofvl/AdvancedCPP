/* Class Player: All data and functions related to a player */
#ifndef H_PLAYER
#define H_PLAYER

#include <ncurses.h>  // functions to draw colored text in terminal
#include "Maze.h"

class Player {
 public:
  Player(int16_t x, int16_t y);  // set up and draw player at (x,y)
  // (re)draw the player as symbol, in colorpair:
  void draw(char symbol, int colorpair);
  // methods to move the player around in the maze:
  inline void up(const Maze &maze) { if (!maze.get(x, y-1) && y>0) y--;  };
  inline void down(const Maze &maze) { if (!maze.get(x, y+1) && y<LINES-1) y++; };
  inline void left(const Maze &maze) { if (!maze.get(x-1, y) && x>0) x--; };
  inline void right(const Maze &maze) { if (!maze.get(x+1, y) && x<COLS-1) x++; };

 private:
  int16_t x, y;  // player position within the maze
};

#endif  // H_PLAYER
