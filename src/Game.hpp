
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
        sf::Clock               m_frameClock;
        sf::Time                m_frameTime;

    public:
                                Game            ();
        void                    start           ();
        sf::RenderWindow&       getWindow       ();
        SceneManager&           getSceneMng     ();
        sf::Time                getFrameTime    ();
};

#endif // __GAME_HPP__
