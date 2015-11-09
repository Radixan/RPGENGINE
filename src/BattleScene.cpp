#include "BattleScene.hpp"
#include <iostream>

BattleScene::BattleScene(Game* game, Battle* battle) {
  this->m_game = game;
  this->m_battle = battle;
  std::cout << "Battle Scene" << std::endl;
}

void BattleScene::Update () {
  sf::Event event;
  while (this->m_game->getWindow().pollEvent(event))
  {
    if (event.type == sf::Event::Closed) {
      this->m_game->getSceneMng().markToRemove(this);
      //this->m_game->getSceneMng().markToAdd(new TestScene(this->m_game));
    }
  }
  this->m_battle->update();
}

void BattleScene::Render () {
  this->m_battle->render(this->m_game);
}

BattleScene::~BattleScene () {

}
