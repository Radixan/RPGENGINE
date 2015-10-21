#include <iostream>
#include "TestScene.hpp"

int numscenes = 0;

TestScene::TestScene(Game* game) {
    this->m_game = game;
    this->m_num = numscenes;
    numscenes++;
}


void TestScene::Init() {
    std::cout << "Creada la escena numero: " << this->m_num << std::endl;
}

void TestScene::Update() {
    sf::Event event;
    while (this->m_game->getWindow().pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            //this->m_game->getWindow().close();
            this->m_game->getSceneMng().removeLast();
    }
}

void TestScene::Render() {

}

void TestScene::Delete() {
    std::cout << "Destruida la escena numero: " << this->m_num << std::endl;
}
