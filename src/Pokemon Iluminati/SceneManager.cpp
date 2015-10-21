
#include "SceneManager.hpp"

void SceneManager::addScene (AbstractScene* scene) {
    scene->Init();
    this->m_sceneList.push_back(scene);
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
    this->m_sceneList.clear();
}
