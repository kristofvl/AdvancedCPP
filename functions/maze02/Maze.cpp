/* Second draft of Maze Game: drawing functions are our module "drawMaze" */
#include "drawMaze.h"  // functions related to drawing
int main() {
  auto c = ' ';         // used for user key input
  auto x = 10, y = 10;  // (x,y) position of player: start at (10,10)
  initNCurses();        // initialize ncurses functionality
  while ( c != 'q' ) {  // as long as the user doesn't press q ..
    clearScreen();
    draw(x, y, '@', 2);   // draw our player
    c = getch();          // capture the user's pressed key
    switch (c) {
      case 'w': y--; break;  // go up
      case 's': y++; break;  // go down
      case 'a': x--; break;  // go left
      case 'd': x++; break;  // go right
    }
  }
  endwin();          // ncurses function: close the ncurses window
  return 0;
}
