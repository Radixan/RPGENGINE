
#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <SFML/Graphics.hpp>
#include "defines.hpp"
#include "SceneManager.hpp"

class Game {
    private:
        sf::RenderWindow        m_window;
        SceneManager            m_scenemng;
        bool                    m_running       =       true;

    public:
                                Game            ();
        void                    start           ();
        sf::RenderWindow&       getWindow       ();
        SceneManager&           getSceneMng     ();
};

#endif // __GAME_HPP__
