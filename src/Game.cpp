
#include <iostream>
#include "Game.hpp"
#include "TestScene.hpp"
#include "BattleScene.hpp"

Game::Game() {
    this->m_window.create(sf::VideoMode(WIN_X, WIN_Y), WIN_TITLE);
    this->m_window.setFramerateLimit(60);

    std::cout << "Creating Scenes " << std::endl;
    this->m_scenemng.addScene(new TestScene(this));

    AbstractSprite* player = new AbstractSprite();
    player->load("Data/Silver.png");
    player->setPosition(50,50);
    player->setDimensions(80,80);
    player->setTextureDimensions(640,80);
    std::vector<unsigned int> frames;
    frames.push_back(0);
    frames.push_back(1);
    frames.push_back(2);
    frames.push_back(3);
    frames.push_back(4);
    frames.push_back(5);
    frames.push_back(6);
    frames.push_back(7);
    player->setFrames(frames);
    player->setSpeed(5);

    AbstractSprite* enemy = new AbstractSprite();
    this->m_scenemng.addScene(new BattleScene(this, new Battle(new Trainer(player), new Trainer(enemy))));
}

sf::RenderWindow& Game::getWindow() {
    return this->m_window;
}

SceneManager& Game::getSceneMng () {
    return this->m_scenemng;
}

void Game::start() {

    AbstractScene* actualScene = nullptr;

    while(this->m_running && this->m_window.isOpen()) {

        actualScene = this->m_scenemng.getLastScene();
        if (actualScene != nullptr) actualScene->Update();

        this->m_window.clear();

        if (actualScene != nullptr) actualScene->Render();

        this->m_window.display();

        this->m_scenemng.deleteMarked();
        this->m_scenemng.addMarked();
    }
    this->m_scenemng.clear();
}
