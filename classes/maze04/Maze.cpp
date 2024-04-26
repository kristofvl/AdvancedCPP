/* Class Maze: All data and functions related to upkeeing a maze */
#include "Maze.h"  // class definition

// initialize maze data and set up window in ncurses, use color
Maze::Maze(int16_t x, int16_t y) {
  // set up the maze data:
  uint8_t myMaze[mazeYlen][mazeXlen] = {  // maze's walls:
    {1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
    {1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
    {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1},
    {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0},
    {1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0}
  };
  for (auto line = 0; line < mazeYlen; line++)
    for (auto col = 0; col < mazeXlen; col++)
      maze[line][col] = myMaze[line][col];  // fill in our maze
  // initialize player position:
  this->x = x; this->y = y;
  // set up everything for drawing:
  initscr(); curs_set(0);  // init ncurses window, hide cursor
  noecho();  // don't show keys pressed in terminal
  start_color();  // use color, with these color pairs:
  init_pair(1, COLOR_YELLOW, COLOR_GREEN);  // walls
  init_pair(2, COLOR_BLACK, COLOR_BLACK);   // coridors
  init_pair(3, COLOR_WHITE, COLOR_BLACK);  // player
}

Maze::~Maze() {
  endwin();  // close ncurses window
}

// clear the screen and draw the maze as a background
void Maze::clearScreen() {
  for ( auto line = 0; line < LINES; line++) {
    for ( auto col = 0; col < COLS; col++) {
      if (maze[line%mazeYlen][col%mazeXlen]) { // 1 = wall
        attron(COLOR_PAIR(1));  // set color pair to 1
        mvaddch(line, col, '#');  // draw '#' as a wall
        attroff(COLOR_PAIR(1));
      } else {
        attron(COLOR_PAIR(2));  // set color pair to 2
        mvaddch(line, col, ':');  // leave empty space
        attroff(COLOR_PAIR(2));
      }
    }
  }
}

// (re)draw the maze with player as symbol, in colorpair:
void Maze::draw(char symbol, int colorpair) {
  clearScreen();
  attron(COLOR_PAIR(colorpair));  // set color pair to 1
  mvaddch(y, x, symbol);  // draw player at (x,y)
  attroff(COLOR_PAIR(colorpair));
}
