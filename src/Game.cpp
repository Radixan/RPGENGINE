
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
    player->setPosition(100,210);
    player->setDimensions(80*4,80*4);
    player->setTextureDimensions(400*4,80*4);
    std::vector<Animation> frames;
    Animation a;
    a.frame = 0;
    a.time = sf::seconds(0.5); // Min: 0.000001
    frames.push_back(a);
    a.frame = 1;
    a.time = sf::seconds(0.2);
    frames.push_back(a);
    a.frame = 2;
    //a.time = sf::seconds(0.2);
    frames.push_back(a);
    a.frame = 3;
    //a.time = sf::seconds(0.01);
    frames.push_back(a);
    a.frame = 4;
    a.time = sf::seconds(1.2);
    frames.push_back(a);
    player->playAnimation();
  /*  a.frame = 5;
    //a.time = sf::seconds(0.30);
    frames.push_back(a);
    a.frame = 6;
    //a.time = sf::seconds(0.15);
    frames.push_back(a);
    a.frame = 7;
    //a.time = sf::seconds(2);
    frames.push_back(a);*/

    player->setFrames(frames);
    player->setActualFrame(0);
    player->setSpeed(sf::seconds(0.15));

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

        // Reset frame clock
        this->m_frameTime = this->m_frameClock.restart();

        if (actualScene != nullptr) actualScene->Update();

        this->m_window.clear();

        if (actualScene != nullptr) actualScene->Render();

        this->m_window.display();

        this->m_scenemng.deleteMarked();
        this->m_scenemng.addMarked();
    }
    this->m_scenemng.clear();
}

sf::Time Game::getFrameTime () {
  return this->m_frameTime;
}
