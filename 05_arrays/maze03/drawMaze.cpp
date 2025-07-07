/* Drawing functions implemented */
#include "drawMaze.h"  // functions to draw colored text in terminal

// initialize all the functions to start drawing in ncurses
void initNCurses() {
  initscr(); curs_set(0);  // ncurses: initialize window, then hide cursor
  noecho();  // don't show keys pressed in terminal
  start_color();  // use color
  init_pair(1, COLOR_YELLOW, COLOR_GREEN);
  init_pair(2, COLOR_BLACK, COLOR_BLACK);
  init_pair(3, COLOR_WHITE, COLOR_BLACK);
}

// clear the screen and draw the maze as a background
void clearScreen(int maze[][15]) {
  for ( auto line = 0; line < LINES; line++) {
    for ( auto col = 0; col < COLS; col++) {
      if (maze[line%10][col%15]) { // 1 = wall
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

// draw a symbol at (x,y) with color colorpair
void draw(int x, int y, char symbol, int colorpair) {
  attron(COLOR_PAIR(colorpair));  // set color pair to 1
  mvaddch(y, x, symbol);  // ncurses function: draw '.' at (x,y)
  attroff(COLOR_PAIR(colorpair));
}
