/* First draft of Maze Game: draw the player, respond to key presses */
#include <ncurses.h> // functions to draw colored text in terminal
int main() {
  char c = ' ';       // used for user key input
  auto x = 10, y = 5; // (x,y) position of player: start at (10,10)
  initscr();
  curs_set(0);          // ncurses: initialize window, then hide cursor
  while (c != 'q') {    // as long as the user doesn't press q ..
    mvaddch(y, x, '@'); // ncurses function: draw a @ at position (x,y)
    c = getch();        // capture the user's pressed key
    // handle here the moving
  }
  endwin(); // ncurses function: close the ncurses window
  return 0;
}
