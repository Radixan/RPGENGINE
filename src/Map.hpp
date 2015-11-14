#ifndef __MAP_HPP__
#define __MAP_HPP__

#include "AbstractVisibleMap.hpp"
class Game;

class Map {
  private:
    AbstractVisibleMap*         m_visibleMap;
    Map*                        m_conections[4]; // North, South, East, West
    Tileset*                    m_tileset;

    uint16_t***                 m_map;
    uint16_t                    m_width;
    uint16_t                    m_height;
    int16_t                     m_scrollx;
    int16_t                     m_scrolly;

  public:
    Map                               ();
    // Get Map data, metadata is proporcionated by World
    void            load              (std::string filename);
    void            setScroll         (int16_t x, int16_t y);
    void            setConnections    (Map* north, Map* south, Map* east, Map* west);
    void            setDimensions     (uint16_t m_width, uint16_t m_height);

    // Screen Positions
    int16_t         getXRegardingMap  (int16_t x);
    int16_t         getYRegardingMap  (int16_t y);

    void            update            (sf::Time deltaTime);
    void            render            (Game* game);
    ~Map                              ();
};

#endif // __MAP_HPP__
