/** Class EnemyPlayer for an enemy following the player in a maze */
#ifndef H_ENEMYPLAYER
#define H_ENEMYPLAYER

#include "Player.h"
#include "Maze.h"

class EnemyPlayer : public Player {
 public:
  EnemyPlayer(uint16_t x, uint16_t y) : Player(x, y) {}
  void moveToward(const Player& player, const Maze & maze);
  void draw(char symbol, int colorpair, const Player& player, const Maze & maze);
};

#endif  // H_ENEMYPLAYER
