/* Class Maze: All data and functions related to upkeeing a maze */
#ifndef H_MAZE
#define H_MAZE

#include <ncurses.h>  // functions to draw colored text in terminal

class Maze {
 public:
  Maze(int16_t x, int16_t y);  // set up and draw maze with player at (x,y)
  ~Maze();  // cleans up ncurses window

  // (re)draw the maze with player as symbol, in colorpair:
  void draw(char symbol, int colorpair);

  // methods to move the player around in the maze:
  inline void up() { if (!maze[(y-1)%mazeYlen][x%mazeXlen] && y>0) y--;  };
  inline void down() { if (!maze[(y+1)%mazeYlen][x%mazeXlen] && y<LINES-1) y++; };
  inline void left() { if (!maze[y%mazeYlen][(x-1)%mazeXlen] && x>0) x--; };
  inline void right() { if (!maze[y%mazeYlen][(x+1)%mazeXlen] && x<COLS-1) x++; };

 private:
  static const int16_t mazeXlen = 15, mazeYlen = 10;  // maze dimensions
  uint8_t maze[mazeYlen][mazeXlen];  // maze walls will be held here
  int16_t x, y;  // player position within the maze
  void clearScreen();  // clear and redraw the maze itself
};

#endif  // H_MAZE
