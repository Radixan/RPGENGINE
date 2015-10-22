
#ifndef __WORLDSCENE_HPP__
#define __WORLDSCENE_HPP__

#include "AbstractScene.hpp"
#include "Game.hpp"
#include "World.hpp"

class WorldScene : public AbstractScene {
    private:
        Game*           m_game;
        World           m_world;

    public:

                        WorldScene      (Game* game);

        void            Init            ();
        void            Update          ();
        void            Render          ();
        void            Delete          ();

                        ~WorldScene     ();
};

#endif // __WORLDSCENE_HPP__
