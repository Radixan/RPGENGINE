
#ifndef __RENDERMANAGER_HPP__
#define __RENDERMANAGER_HPP__

#include "AbstractScreenMap.hpp"
class Game;

class RenderManager {
    private:
        Game*   m_game;

    public:

                RenderManager   (Game* game);
        void    renderMap       (AbstractScreenMap* map);
        void    renderSprite    ();
        void    renderImg       ();
        void    renderText      ();
        void    renderSaticTiled();
        void    renderNPC       ();
        void    renderPlayer    ();
};

#endif // __RENDERMANAGER_HPP__
