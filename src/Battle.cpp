
#include "Battle.hpp"

Battle::Battle (Trainer* player, Trainer* enemy) {
  this->m_player = player;
  this->m_enemy = enemy;
  this->m_state = 0;
}


void Battle::update(sf::Time deltaTime) {
  if (this->m_state == 0) {
    this->startingBattle(deltaTime);
  }
}

void Battle::render(Game* game) {
  this->m_player->getBattleSprite()->render(game);
}

int u = 0;

void Battle::startingBattle (sf::Time deltaTime) {
  int _x = this->m_player->getBattleSprite()->getX();
  this->m_player->getBattleSprite()->setPosition(
    _x - (410)*deltaTime.asSeconds(), this->m_player->getBattleSprite()->getY());
  u++;
  if (u == 65) {
    u=0;
    this->m_player->getBattleSprite()->setActualFrame(0);
    this->m_player->getBattleSprite()->setPosition(100,210);
    //this->m_player->getBattleSprite()->setPosition(100,210);
    //this->m_player->getBattleSprite()->stopAnimation();
  }
  this->m_player->getBattleSprite()->update(deltaTime);
}
