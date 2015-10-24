
#ifndef __ABSTRACTSPRITE_HPP__
#define __ABSTRACTSPRITE_HPP__

#include "SFML/Graphics.hpp"
#include "Game.hpp"

class AbstractSprite {
    private:
        sf::Sprite                m_sprite;
        sf::Texture               m_texture;
        unsigned int              m_wide = 0;
        unsigned int              m_hight = 0;
        unsigned int              m_offsetX = 0;
        unsigned int              m_offsetY = 0;
        unsigned int              m_textureWide = 0;
        unsigned int              m_textureHight = 0;
        int                       m_x;
        int                       m_y;

    public:
        void        load                  (const std::string filename);
        void        render                (Game* game);
        void        setPosition           (int x, int y);
        void        setDimensions         (unsigned int wide, unsigned int hight);
        void        setTextureDimensions  (unsigned int wide, unsigned int hight);
        void        update                ();

        // Only if all parameters are set
        void        setIndex              (unsigned int index);
        void        setOffsets            (unsigned int x, unsigned int y);
};

#endif // __ABSTRACTSPRITE_HPP__
