#include <ncurses.h>  // functions to draw colored text

void bluetooth(int width) {
  // first set background to blue:
  attron(COLOR_PAIR(1));
  for ( auto line = 0; line < LINES; line++) {
    for ( auto col = 0; col < COLS; col++) {
      mvaddch(line, col, ' ');
    }
  }
  attroff(COLOR_PAIR(1));
  // then draw the icon:
  attron(COLOR_PAIR(2));
  for ( auto line = 0; line < width*2-1; line++) {
    for ( auto col = 0; col < width; col++) {
    }
  }
  attroff(COLOR_PAIR(2));
}

int main() {
  initscr(); curs_set(0);  // ncurses: initialize window, hide cursor
  noecho();  // don't show keys pressed in terminal
  start_color();  // use color
  init_pair(1, COLOR_BLACK, COLOR_BLUE);
  init_pair(2, COLOR_BLACK, COLOR_WHITE);
  bluetooth(9);  // draw a bluetooth icon of width 9
  char c = ' ';
  while ( c != 'q' )  c = getch();  // wait until user presses q
  endwin();  // ncurses function: close the ncurses window
}
