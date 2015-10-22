
#include <iostream>
#include "Game.hpp"
#include "TestScene.hpp"

Game::Game() {
    this->m_window.create(sf::VideoMode(WIN_X, WIN_Y), WIN_TITLE);
    this->m_rendermng = new RenderManager(this);

    std::cout << "Creating Scenes " << std::endl;
    this->m_scenemng.addScene(new TestScene(this));
}

sf::Window& Game::getWindow() {
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
}
