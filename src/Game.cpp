
#include <iostream>
#include "Game.hpp"
#include "TestScene.hpp"
#include "BattleScene.hpp"

Game::Game() {
    this->m_window.create(sf::VideoMode(WIN_X, WIN_Y), WIN_TITLE);
    this->m_window.setFramerateLimit(60);

    std::cout << "Creating Scenes " << std::endl;
    this->m_scenemng.addScene(new TestScene(this));
    this->m_scenemng.addScene(new BattleScene(this));
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
