#include <iostream>
#include "TestScene.hpp"

int numscenes = 0;
int spriteIndex = 0;
int x = 0, y = 0;

unsigned int ** map;

TestScene::TestScene(Game* game) {
    this->m_game = game;
    this->m_num = numscenes;
    numscenes++;
    map = new unsigned int*[5];
    for (int i = 0; i < 5; i++) {
      map[i] = new unsigned int [5];
      map[i][0] = 1;
      map[i][1] = 2;
      map[i][2] = 1;
      map[i][3] = 2;
      map[i][4] = 4;
    }
}


void TestScene::Init() {
    std::cout << "Creada la escena numero: " << this->m_num << std::endl;
    this->m_sprite.load("Data/Pokemon.png");
    this->m_sprite.setTextureDimensions(2240, 1440);
    this->m_sprite.setDimensions(80,80);
    this->m_tileset.load("Data/Tileset.til");
    this->m_map.loadTileset(this->m_tileset);

    std::cout << std::endl
              << "ID: " << this->m_tileset.getID()
              << " tileWide: " << this->m_tileset.getTileWide()
              << " tilehight: " << this->m_tileset.getTileHight()
              << " wide: " << this->m_tileset.getWide()
              << " hight: " << this->m_tileset.getHight() << std::endl;
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
        x++;
        std::cout << "Index: " << spriteIndex << std::endl;
      }
      if (event.key.code == sf::Keyboard::Left) {
        spriteIndex--;
        x--;
        std::cout << "Index: " << spriteIndex << std::endl;
      }
      if (event.key.code == sf::Keyboard::Down) {
        spriteIndex++;
        y++;
        std::cout << "Index: " << spriteIndex << std::endl;
      }
      if (event.key.code == sf::Keyboard::Up) {
        spriteIndex--;
        y--;
        std::cout << "Index: " << spriteIndex << std::endl;
      }
    }
  }

  //this->m_sprite.setIndex(spriteIndex);
  this->m_sprite.setPosition(x,y);
  this->m_sprite.setIndex(spriteIndex);
  this->m_sprite.update();
  this->m_map.setOffset(x, y);
}

void TestScene::Render() {
  this->m_map.render(this->m_game, map, 5, 5);
  this->m_sprite.render(this->m_game);
}
// FIX: Delete no execute
void TestScene::Delete() {
    std::cout << "Destruida la escena numero: " << this->m_num << std::endl;
    for (int i = 0; i < 5; i++)
      delete[] map[i];
    delete[] map;
}
