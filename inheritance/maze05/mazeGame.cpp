/* Fifth draft of Maze Game: we now use class "Player" and use a file */
#include "Maze.h"  // class that holds everything related to the maze
#include "Player.h"  // class that holds everything related to the player

int main() {
  auto c = ' ';  // used for user key input
  std::string mapFile("maze.csv");
  Maze maze(mapFile);  // initialize a maze object from this file
  Player player1(10, 5);
  Player player2(20, 7);
  while ( c != 'q' ) {  // as long as the user doesn't press q ..
    maze.draw('#', 2);    // draw maze
    player1.draw('@', 3);  // draw player 1 as a '@' with color pair 3
    player2.draw('X', 3);  // draw player 2 as a 'X' with color pair 3
    c = getch();          // capture the user's pressed key
    switch (c) {
      case 'w': player1.up(maze); break;  // go up
      case 's': player1.down(maze); break;  // go down
      case 'a': player1.left(maze); break;  // go left
      case 'd': player1.right(maze); break;  // go right
      case 'i': player2.up(maze); break;  // go up
      case 'k': player2.down(maze); break;  // go down
      case 'j': player2.left(maze); break;  // go left
      case 'l': player2.right(maze); break;  // go right
    }
  }
  return 0;
}
