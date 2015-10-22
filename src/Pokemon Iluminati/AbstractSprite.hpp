
#ifndef __ABSTRACTSPRITE_HPP__
#define __ABSTRACTSPRITE_HPP__

#include "SFML/Graphics.hpp"

class AbstractSprite {
    private:
        sf::RenderTexture&  m_texture;
        sf::Sprite          m_sprite;
        unsigned int        m_wide;
        unsigned int        m_hight;
        unsigned int        m_index;

    public:
        void            setTexture      (const std::string filename);
        void            setWide         (unsigned int w);
        void            setHight        (unsigned int h);
        void            setIndex        (unsigned int index);

        sf::Sprite&     getSprite       ();
        unsigned int    getWide         ();
        unsigned int    getHight        ();
        unsigned int    getIndex        ();
};

#endif // __ABSTRACTSPRITE_HPP__
