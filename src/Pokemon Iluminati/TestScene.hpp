
#ifndef __TESTSCENE_HPP__
#define __TESTSCENE_HPP__

#include "AbstractScene.hpp"
#include "Game.hpp"

class TestScene : public AbstractScene {
    private:
        Game*           m_game;
        int             m_num;

    public:

        TestScene(Game* game);

        void            Init            ();
        void            Update          ();
        void            Render          ();
        void            Delete          ();

};

#endif // __TESTSCENE_HPP__

