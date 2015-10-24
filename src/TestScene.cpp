#include <iostream>
#include "TestScene.hpp"

int numscenes = 0;
int spriteIndex = 0;
int x = 0, y = 0;

TestScene::TestScene(Game* game) {
    this->m_game = game;
    this->m_num = numscenes;
    numscenes++;
}


void TestScene::Init() {
    std::cout << "Creada la escena numero: " << this->m_num << std::endl;
    this->m_sprite.load("Data/Pokemon.png");
    this->m_sprite.setTextureDimensions(2240, 1440);
    this->m_sprite.setDimensions(80,80);
}

void TestScene::Update() {
  sf::Event event;
  while (this->m_game->getWindow().pollEvent(event))
  {
    if (event.type == sf::Event::Closed) {
      this->m_game->getWindow().close();
      //this->m_game->getSceneMng().markToRemove(this);
      //this->m_game->getSceneMng().markToAdd(new TestScene(this->m_game));
    }
    if (event.type == sf::Event::KeyPressed) {
      if (event.key.code == sf::Keyboard::Right) {
        spriteIndex++;
        x+=80;
        std::cout << "Index: " << spriteIndex << std::endl;
      }
      if (event.key.code == sf::Keyboard::Left) {
        spriteIndex--;
        x-=80;
        std::cout << "Index: " << spriteIndex << std::endl;
      }
      if (event.key.code == sf::Keyboard::Down) {
        spriteIndex++;
        y+=80;
        std::cout << "Index: " << spriteIndex << std::endl;
      }
      if (event.key.code == sf::Keyboard::Up) {
        spriteIndex--;
        y-=80;
        std::cout << "Index: " << spriteIndex << std::endl;
      }
    }
  }

  //this->m_sprite.setIndex(spriteIndex);
  this->m_sprite.setPosition(x,y);
  this->m_sprite.setIndex(spriteIndex);
  this->m_sprite.update();
}

void TestScene::Render() {
  this->m_sprite.render(this->m_game);
}

void TestScene::Delete() {
    std::cout << "Destruida la escena numero: " << this->m_num << std::endl;
}
