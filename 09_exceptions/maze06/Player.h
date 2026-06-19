/** Class Player: All data and functions related to a player */
#ifndef H_PLAYER
#define H_PLAYER

#include <ncurses.h>  // functions to draw colored text in terminal
#include "Maze.h"

class Player {
 protected:
  uint16_t x, y;  // player position within the maze
  char up, down, left, right;
 public:
  Player(uint16_t x, uint16_t y,
         char up='w', char down='s', char left='a', char right='d')
        : x(x), y(y), up(up), down(down), left(left), right(right) {}
  virtual void move(char key, const Maze & maze);
  virtual void draw(char symbol, int colorpair, char key, const Maze & maze);
  uint16_t getX() const { return x; }
  uint16_t getY() const { return y; }
};

#endif  // H_PLAYER
