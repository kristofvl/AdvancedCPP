/* Third draft of Maze Game: drawing functions are in our module "drawMaze" */
#include "drawMaze.h"  // functions related to drawing

const int mazeXlen = 15, mazeYlen = 10;

// we will tile this background as our maze:
int maze[mazeYlen][mazeXlen] = {
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
};  // array for drawing a maze as a background

int main() {
  auto c = ' ';         // used for user key input
  auto x = 10, y = 5;  // (x,y) position of player: start at (10,10)
  initNCurses();        // initialize ncurses functionality
  while ( c != 'q' ) {  // as long as the user doesn't press q ..
    clearScreen(maze);
    draw(x, y, '@', 3);   // draw our player
    c = getch();          // capture the user's pressed key
    switch (c) {
      case 'w': if (!maze[(y-1)%10][x%15] && y>0) y--; break;  // go up
      case 's': if (!maze[(y+1)%10][x%15] && y<LINES-1) y++; break;  // go down
      case 'a': if (!maze[y%10][(x-1)%15] && x>0) x--; break;  // go left
      case 'd': if (!maze[y%10][(x+1)%15] && x<COLS-1) x++; break;  // go right
    }
  }
  endwin();          // ncurses function: close the ncurses window
  return 0;
}
