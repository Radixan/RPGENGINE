
#include "SceneManager.hpp"

void SceneManager::addScene (AbstractScene* scene) {
    this->m_sceneList.push_back(scene);
}

SceneManager::SceneManager() {
    this->m_sceneList.clear();
    this->m_addList.clear();
    this->m_removeList.clear();
}

AbstractScene* SceneManager::getLastScene () {
    if (this->m_sceneList.size() == 0) return nullptr;
    return this->m_sceneList.back();
}

AbstractScene* SceneManager::getSceneByIndex (uint16_t index) {
    if (index > this->m_sceneList.size() - 1) return nullptr;
    return this->m_sceneList.at(index);
}

uint16_t SceneManager::getLastSceneIndex() {
    if (this->m_sceneList.size() > 0) return this->m_sceneList.size() - 1;
    else return -1;
}

void SceneManager::removeLast() {
    if (this->m_sceneList.size() > 0) {
        delete this->m_sceneList.back();
        this->m_sceneList.pop_back();
    }
}

void SceneManager::removeByIndex(uint16_t index) {
    if (index <= this->m_sceneList.size() - 1) {
        delete this->m_sceneList.at(index);
        this->m_sceneList.erase(this->m_sceneList.begin()+index);
    }
}

void SceneManager::removePrevious() {
    delete this->m_sceneList.at(this->m_sceneList.size() - 2);
    this->m_sceneList.erase(this->m_sceneList.end() - 1);
}

uint16_t SceneManager::getSceneIndex(AbstractScene* scene) {
    for (uint16_t i = 0; i < this->m_sceneList.size(); i++)
        if (this->m_sceneList.at(i) == scene)
            return i;
    return -1;
}

void SceneManager::clear() {
  for (uint16_t i = 0; i < this->m_sceneList.size(); i++)
    delete this->m_sceneList.at(i);

  for (uint16_t i = 0; i < this->m_removeList.size(); i++)
    delete this->m_removeList.at(i);

  for (uint16_t i = 0; i < this->m_addList.size(); i++)
    delete this->m_addList.at(i);

  this->m_sceneList.clear();
  this->m_addList.clear();
  this->m_removeList.clear();
}

void SceneManager::markToRemove (AbstractScene* scene) {
    this->m_removeList.push_back(scene);
}

void SceneManager::deleteMarked () {
    for (uint16_t i = 0; i < this->m_removeList.size(); i++) {
        int x = this->getSceneIndex(this->m_removeList.at(i));
        if (x != -1)
        this->removeByIndex(x);
        this->m_removeList.erase(this->m_removeList.begin() + i);
    }
}

void SceneManager::markToAdd (AbstractScene* scene) {
    this->m_addList.push_back(scene);
}

void SceneManager::addMarked () {
    for (uint16_t i = 0; i < this->m_addList.size(); i++) {
        this->addScene(this->m_addList.at(i));
        this->m_addList.erase(this->m_addList.begin() + i);
    }
}
