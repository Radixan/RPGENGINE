
#include "TestScene.hpp"

TestScene::TestScene(Game* game) {
    this->m_game = game;
}


void TestScene::Init() {

}

void TestScene::Update() {
    sf::Event event;
    while (this->m_game->getWindow().pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            this->m_game->getWindow().close();
    }
}

void TestScene::Render() {

}

void TestScene::Delete() {

}
