
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
        void                markToRemove        (AbstractScene* scene);
        void                deleteMarked        ();
        void                markToAdd           (AbstractScene* scene);
        void                addMarked           ();

        /*
            No Control Adds and Delete
        */
        void                addScene            (AbstractScene* scene);
        void                removeLast          ();
        void                removeByIndex       (unsigned int index);
        void                removePrevious      ();                   
        AbstractScene*      getLastScene        ();
        AbstractScene*      getSceneByIndex     (unsigned int index);
        int                 getLastSceneIndex   ();
        int                 getSceneIndex       (AbstractScene* scene);
        void                clear               ();
};

#endif // __SCENEMANAGER_HPP__
