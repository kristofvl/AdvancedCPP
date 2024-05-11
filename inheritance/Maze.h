/* Class Maze: All data and functions related to upkeeing a maze */
#ifndef H_MAZE
#define H_MAZE

#include <ncurses.h>  // functions to draw colored text in terminal
#include <fstream>

class Maze {
 public:
  Maze(std::string mazeFile);  // set up and draw maze from mazeFile
  ~Maze();  // cleans up ncurses window
  // (re)draw the maze with walls as symbol, in colorpair:
  void draw(char symbol, int colorpair);
  // return the contents of the maze at position (x,y)
  uint8_t get(uint16_t x, uint16_t y) const { return maze[(y%mazeYlen)*mazeXlen+(x%mazeXlen)]; }

 private:
  int16_t mazeXlen, mazeYlen;  // maze dimensions
  uint8_t *maze;  // maze walls will be held here
};

#endif  // H_MAZE
