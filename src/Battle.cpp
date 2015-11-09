
#include "Battle.hpp"

Battle::Battle (Trainer* player, Trainer* enemy) {
  this->m_player = player;
  this->m_enemy = enemy;
  this->m_state = 0;
}


void Battle::update() {
  if (this->m_state == 0) {
    this->startingBattle();
  }
}

void Battle::render(Game* game) {
  this->m_player->getBattleSprite()->render(game);
}

int u = 0;

void Battle::startingBattle () {
  this->m_player->getBattleSprite()->update();
  int _x = this->m_player->getBattleSprite()->getX();
  this->m_player->getBattleSprite()->setPosition(
    _x - 3, this->m_player->getBattleSprite()->getY());
  u++;
  if (u == 40) {
    u=0;
    this->m_player->getBattleSprite()->setActualFrame(0);
    this->m_player->getBattleSprite()->setPosition(50,50);
  }
}
