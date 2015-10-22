
#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <SFML/Graphics.hpp>
#include "defines.hpp"
#include "SceneManager.hpp"
#include "RenderManager.hpp"

class Game {
    private:
        sf::RenderWindow        m_window;
        SceneManager            m_scenemng;
        RenderManager*          m_rendermng;
        bool                    m_running       =       true;

    public:
                                Game            ();
        void                    start           ();
        sf::Window&             getWindow       ();
        SceneManager&           getSceneMng     ();
};

#endif // __GAME_HPP__
