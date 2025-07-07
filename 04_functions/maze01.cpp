/* First draft of Maze Game: draw the player, respond to key presses
   Result of the in-class programming code (see YouTube video of the lecture)
*/
#include <ncurses.h> // functions to draw colored text in terminal

// initialize all the functions to start drawing in ncurses
void initNCurses() {
  initscr();
  curs_set(0);   // ncurses: initialize window, then hide cursor
  noecho();      // don't show keys pressed in terminal
  start_color(); // use color
  init_pair(1, COLOR_BLUE, COLOR_GREEN);
  init_pair(2, COLOR_RED, COLOR_YELLOW);
}

void clearScreen() {
  attron(COLOR_PAIR(1)); // set color pair to 1
  for (auto line = 0; line < LINES; line++) {
    for (auto col = 0; col < COLS; col++) {
      mvaddch(line, col, '.'); // ncurses function: draw '.' at (x,y)
    }
  }
  attroff(COLOR_PAIR(1));
}

// draw a symbol at (x,y) with color colorpair
void draw(int x, int y, char symbol, int colorpair) {
  attron(COLOR_PAIR(colorpair)); // set color pair to 1
  mvaddch(y, x, symbol);         // ncurses function: draw '.' at (x,y)
  attroff(COLOR_PAIR(colorpair));
}

int main() {
  auto c = ' ';        // used for user key input
  auto x = 10, y = 10; // (x,y) position of player: start at (10,10)
  initNCurses();       // initialize ncurses functionality
  while (c != 'q') {   // as long as the user doesn't press q ..
    clearScreen();
    draw(x, y, '@', 2); // draw our player
    c = getch();        // capture the user's pressed key
    switch (c) {
    case 'w':
      y--;
      break; // go up
    case 's':
      y++;
      break; // go down
    case 'a':
      x--;
      break; // go left
    case 'd':
      x++;
      break; // go right
    }
  }
  endwin(); // ncurses function: close the ncurses window
  return 0;
}
