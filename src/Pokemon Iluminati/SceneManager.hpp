
#ifndef __SCENEMANAGER_HPP__
#define __SCENEMANAGER_HPP__

#include <vector>
#include "AbstractScene.hpp"

class SceneManager {
    private:
        std::vector<AbstractScene*>         m_sceneList;
        std::vector<AbstractScene*>         m_removeList;
        std::vector<AbstractScene*>         m_addList;

    public:
                            SceneManager        ();

        /*
            Use This (Loop controlled)
        */
        void                markToRemove        (AbstractScene* scene);     // Execute Delete before remove
        void                deleteMarked        ();
        void                markToAdd           (AbstractScene* scene);     // Execute Init before add
        void                addMarked           ();

        /*
            No Control Adds and Delete
        */
        void                addScene            (AbstractScene* scene);     // Execute Init before add
        void                removeLast          ();                         // Execute Delete before remove
        void                removeByIndex       (unsigned int index);       // Execute Delete before remove
        void                removePrevious      ();                         // Execute Delete before remove
        AbstractScene*      getLastScene        ();
        AbstractScene*      getSceneByIndex     (unsigned int index);
        int                 getLastSceneIndex   ();
        int                 getSceneIndex       (AbstractScene* scene);
        void                clear               ();
};

#endif // __SCENEMANAGER_HPP__
