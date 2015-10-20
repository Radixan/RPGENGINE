
#ifndef __SCENEMANAGER_HPP__
#define __SCENEMANAGER_HPP__

#include <vector>
#include "AbstractScene.hpp"

class SceneManager {
    private:
        std::vector<AbstractScene*>         m_sceneList;

    public:
        void                addScene            (AbstractScene* scene);     // Execute Init before add
        void                removeLast          ();                         // Execute Delete before remove
        void                removeByIndex       (unsigned int index);       // Execute Delete before remove
        AbstractScene*      getLastScene        ();
        AbstractScene*      getSceneByIndex     (unsigned int index);
        int                 getLastSceneIndex   ();
        int                 getSceneIndex       (AbstractScene* scene);
        void                clear               ();
};

#endif // __SCENEMANAGER_HPP__
