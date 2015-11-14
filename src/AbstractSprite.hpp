
#ifndef __ABSTRACTSPRITE_HPP__
#define __ABSTRACTSPRITE_HPP__

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Animation.hpp"

class AbstractSprite {
    private:
        sf::Sprite                m_sprite;
        sf::Texture               m_texture;
        uint16_t                  m_wide = 0;
        uint16_t                  m_hight = 0;
        uint16_t                  m_offsetX = 0;
        uint16_t                  m_offsetY = 0;
        uint16_t                  m_textureWide = 0;
        uint16_t                  m_textureHight = 0;
        int16_t                   m_x;
        int16_t                   m_y;

        std::vector<Animation>    m_frames;
        uint16_t                  m_actualFrame;
        sf::Time                  m_time;
        sf::Time                  m_currentTime;
        bool                      m_playing;

    public:
        void        load                  (const std::string filename);
        void        loadTexture           (sf::Texture& texture);
        void        render                (Game* game);
        void        setPosition           (int16_t x, int16_t y);
        void        setDimensions         (uint16_t wide, uint16_t hight);
        void        setTextureDimensions  (uint16_t wide, uint16_t hight);
        void        update                (sf::Time deltaTime);

        int         getX                  ();
        int         getY                  ();

        // Only if all parameters are set
        void        setIndex              (uint16_t index);
        void        setOffsets            (uint16_t x, uint16_t y);

        // Animated
        void        setSpeed              (sf::Time frameTime);
        void        setFrames             (std::vector<Animation> frames);
        void        setActualFrame        (uint16_t frame);

        void        playAnimation         ();
        void        stopAnimation         ();
};

#endif // __ABSTRACTSPRITE_HPP__
