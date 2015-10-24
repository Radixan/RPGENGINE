
#include "SceneManager.hpp"

void SceneManager::addScene (AbstractScene* scene) {
    scene->Init();
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

AbstractScene* SceneManager::getSceneByIndex (unsigned int index) {
    if (index > this->m_sceneList.size() - 1) return nullptr;
    return this->m_sceneList.at(index);
}

int SceneManager::getLastSceneIndex() {
    if (this->m_sceneList.size() > 0) return this->m_sceneList.size() - 1;
    else return -1;
}

void SceneManager::removeLast() {
    if (this->m_sceneList.size() > 0) {
        this->m_sceneList.back()->Delete();
        delete this->m_sceneList.back();
        this->m_sceneList.pop_back();
    }
}

void SceneManager::removeByIndex(unsigned int index) {
    if (index <= this->m_sceneList.size() - 1) {
        this->m_sceneList.at(index)->Delete();
        delete this->m_sceneList.at(index);
        this->m_sceneList.erase(this->m_sceneList.begin()+index);
    }
}

void SceneManager::removePrevious() {
    this->m_sceneList.at(this->m_sceneList.size() - 2)->Delete();
    delete this->m_sceneList.at(this->m_sceneList.size() - 2);
    this->m_sceneList.erase(this->m_sceneList.end() - 1);
}

int SceneManager::getSceneIndex(AbstractScene* scene) {
    for (unsigned int i = 0; i < this->m_sceneList.size(); i++)
        if (this->m_sceneList.at(i) == scene)
            return i;
    return -1;
}

void SceneManager::clear() {
  for (int i = 0; i < this->m_sceneList.size(); i++)
    delete this->m_sceneList.at(i);

  for (int i = 0; i < this->m_removeList.size(); i++)
    delete this->m_removeList.at(i);

  for (int i = 0; i < this->m_addList.size(); i++)
    delete this->m_addList.at(i);
  
  this->m_sceneList.clear();
  this->m_addList.clear();
  this->m_removeList.clear();
}

void SceneManager::markToRemove (AbstractScene* scene) {
    this->m_removeList.push_back(scene);
}

void SceneManager::deleteMarked () {
    for (unsigned int i = 0; i < this->m_removeList.size(); i++) {
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
    for (unsigned int i = 0; i < this->m_addList.size(); i++) {
        this->addScene(this->m_addList.at(i));
        this->m_addList.erase(this->m_addList.begin() + i);
    }
}
