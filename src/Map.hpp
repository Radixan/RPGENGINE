
#ifndef __MAP_HPP__
#define __MAP_HPP__

#include "AbstractVisibleMap.hpp"

class Map {
  private:
    AbstractVisibleMap      m_visibleMap;
    Map*                    m_upMap;
    Map*                    m_downMap;
    Map*                    m_leftMap;
    Map*                    m_rightMap;

  public:
    void          load      (std::string filename);


};

/*
  Map HEX INFO
  BIG ENDIAN

  2 bytes map ID
  X bytes map Name
  FF
  2 bytes Up map ID
  2 bytes Down map ID
  2 bytes Left map ID
  2 bytes Right map ID
  2 bytes Tileset ID
  4 bytes Map Width (Tiles)
  4 bytes Map Hight (Tiles)
  Map Data
  FF
*/


#endif // __MAP_HPP__
