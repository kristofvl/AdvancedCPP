/* Sixth draft of Maze Game: we now use class "Player" and use a file */
#include "Maze.h"  // class that holds everything related to the maze
#include "Player.h"  // class that holds everything related to the player
#include "EnemyPlayer.h"  // class that holds everything related to the enemy

int main() {
  auto c = ' ';  // used for user key input
  std::string mapFile("maze.csv");
  Maze maze(mapFile);  // initialize a maze object from this file
  init_pair(1, COLOR_BLACK, COLOR_BLACK);   // coridors
  init_pair(2, COLOR_YELLOW, COLOR_GREEN);  // walls
  init_pair(3, COLOR_WHITE, COLOR_BLACK); // color pair for player
  init_pair(4, COLOR_WHITE, COLOR_RED);   // color pair for enemy
  Player player(9, 9, 'w', 's', 'a', 'd');
  EnemyPlayer enemy(10,7);
  while ( c != 'q' ) {  // as long as the user doesn't press q ..
    maze.draw('#', 2);  // draw maze as # with color pair 2
    player.draw('@', 3, c, maze);  // draw player as a '@' with color pair 3
    enemy.draw('$', 4, player, maze);  // draw enemy as a 'X' with color pair 4
    c = getch();          // capture the user's pressed key
  }
}
