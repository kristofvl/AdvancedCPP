/* Fourth draft of Maze Game: we now use class "Maze" */
#include "Maze.h"  // class that holds everything related to the maze
#include <iostream>

int main() {
  auto c = ' ';  // used for user key input
  Maze maze(10, 5);  // initialize a maze object with player at (10,5)
  while ( c != 'q' ) {  // as long as the user doesn't press q ..
    maze.draw('@', 3);    // draw player as a '@' with color pair 3
    c = getch();          // capture the user's pressed key
    switch (c) {
      case 'w': maze.up(); break;  // go up
      case 's': maze.down(); break;  // go down
      case 'a': maze.left(); break;  // go left
      case 'd': maze.right(); break;  // go right
    }
  }
  return 0;
}
