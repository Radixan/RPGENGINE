#ifndef __MAP_HPP__
#define __MAP_HPP__

#include "AbstractVisibleMap.hpp"
class Game;

class Map {
  private:
    AbstractVisibleMap          m_visibleMaps[4]; // North, South, East, West
    Map*                        m_conections[4]; // North, South, East, West

  public:
    void            load              (std::string filename);
    void            centerOnXY        (unsigned int x, unsigned int y);
    Map*            getActualMap      ();

    void            update            (sf::Time deltaTime);
    void            render            (Game* game);

};

#endif // __MAP_HPP__
