
#ifndef __TILESET_HPP__
#define __TILESET_HPP__

#include <SFML/Graphics.hpp>

class Tileset {
  private:
    int16_t       m_ID;
    sf::Texture   m_texture;
    int16_t       m_tileWide;
    int16_t       m_tileHight;
    int16_t       m_wide;
    int16_t       m_hight;

  public:
    void        load            (std::string filename);

    int16_t       getID       ();
    int16_t       getWide       ();
    int16_t       getHight      ();
    int16_t       getTileWide   ();
    int16_t       getTileHight  ();

    sf::Texture&  getTexture    ();
};

/*
  Map HEX INFO
  BIG ENDIAN

  2 bytes Tileset ID
  x bytes Tileset filename
  FF
  2 bytes Tile Width
  2 bytes Tile Hight
  2 bytes Tileset Width
  2 bytes Tileset Hight
*/

#endif // __TILESET_HPP__
