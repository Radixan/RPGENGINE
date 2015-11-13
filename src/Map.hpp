#ifndef __MAP_HPP__
#define __MAP_HPP__

class Game;

class Map {
  private:
    AbstractVisibleMap          m_visibleMap;
    Map*                        m_conections[4]; // North, South, East, West
    Tileset*                    m_tileset;

    unsigned int**              m_map;
    unsigned int                m_width;
    unsigned int                m_height;
    unsigned int                m_scrollx;
    unsigned int                m_scrolly;

  public:
    void            load              (std::string filename);
    void            scroll            (unsigned int x, unsigned int y);
    Map*            getActualMap      ();

    void            update            (sf::Time deltaTime);
    void            render            (Game* game);

};

#endif // __MAP_HPP__
