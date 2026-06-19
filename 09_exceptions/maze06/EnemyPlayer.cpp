#include "EnemyPlayer.h"

void EnemyPlayer::moveToward(const Player& player, const Maze & maze) {
  bool random_bool = std::rand() & 1;  // randomly select up-down or left-right
  if (random_bool) {
    if (player.getX() > x) {
      if (!maze.get(x+1, y) && x<COLS-1) x++;
    } else if (player.getX() < x) {
      if (!maze.get(x-1, y) && x>0) x--;
    }
  } else {
    if (player.getY() > y) {
      if (!maze.get(x, y+1) && y<LINES-1) y++;
    } else if (player.getY() < y) {
      if (!maze.get(x, y-1) && y>0) y--;
    }
  }
}

void EnemyPlayer::draw(char symbol, int colorpair, const Player& player, const Maze & maze) {
  moveToward(player, maze);
  attron(COLOR_PAIR(colorpair));
  mvaddch(y, x, symbol);
  attroff(COLOR_PAIR(colorpair));
}

