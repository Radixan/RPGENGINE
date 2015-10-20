
#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <SFML/Graphics.hpp>
#include "SceneManager.hpp"

#define     WIN_X       1280
#define     WIN_Y       720
#define     WIN_TITLE   "Pokémon Iluminati"

class Game {
    private:
        sf::RenderWindow        m_window;
        SceneManager            m_scenemng;
        bool                    m_running       =       true;

    public:
                                Game            ();
        void                    start           ();
        sf::Window&             getWindow       ();
        SceneManager&           getSceneMng     ();
};

#endif // __GAME_HPP__
