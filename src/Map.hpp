#ifndef __MAP_HPP__
#define __MAP_HPP__

#include "AbstractVisibleMap.hpp"
class Game;

class Map {
  private:
    AbstractVisibleMap*         m_visibleMap;
    //Map*                        m_conections[4]; // North, South, East, West

    uint16_t***                 m_map;
    uint16_t                    m_width;
    uint16_t                    m_height;
    int16_t                     m_scrollx;
    int16_t                     m_scrolly;
    uint8_t                     m_layers;
    uint16_t                    m_renderWidth;
    uint16_t                    m_renderHeight;

  public:
    Map                               ();
    // Get Map data, metadata is proporcionated by World
    void            load              (std::string filename);
    void            setTileset        (Tileset* tileset);
    void            setScroll         (int16_t x, int16_t y);
    //void            setConnections    (Map* north, Map* south, Map* east, Map* west);
    //void            setDimensions     (uint16_t width, uint16_t height);

    void            update (sf::Time deltaTime, uint16_t startTileX, uint16_t startTileY, uint16_t width, uint16_t hight);
    void            render            (Game* game);
    ~Map                              ();
};

#endif // __MAP_HPP__
