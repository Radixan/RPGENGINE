
#ifndef __TILESET_HPP__
#define __TILESET_HPP__

#include <SFML/Graphics.hpp>

class Tileset {
  private:
    uint16_t       m_ID;
    sf::Texture   m_texture;
    uint16_t       m_tileWide;
    uint16_t       m_tileHight;
    uint16_t       m_wide;
    uint16_t       m_hight;

    void        Construct ();

  public:
    Tileset();
    Tileset(std::string filename);

    void        load            (std::string filename);

    uint16_t       getID       ();
    uint16_t       getWide       ();
    uint16_t       getHight      ();
    uint16_t       getTileWide   ();
    uint16_t       getTileHight  ();

    sf::Texture&  getTexture    ();
};

#endif // __TILESET_HPP__
