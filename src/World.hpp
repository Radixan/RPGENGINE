
#ifndef __WORLD_HPP__
#define __WORLD_HPP__

#include "defines.hpp"
#include "Map.hpp"
#include "Tileset.hpp"
#include <unordered_map>

class World {
    private:
      //Map**                   m_maps;
      std::unordered_map<uint16_t, Map*>      m_maps;
      std::unordered_map<uint16_t, Tileset*>  m_tilesets;

      Map*                                    m_actualMap;
      Map*                                    m_actualNorthMap;
      Map*                                    m_actualSouthMap;
      Map*                                    m_actualEastMap;
      Map*                                    m_actualWestMap;
      int16_t x,y;

      void        Construct     ();

    public:
      World();
      World(std::string filename);

      void        load              (std::string filename);
      void        lockSprite        (AbstractSprite& sprite);

      void        setActualMap      (uint16_t map);
      Map*        getMap            ();

      void        update            (sf::Time deltaTime);
      void        setCamera         (int16_t x, int16_t y);
      void        render            (Game* game);

      ~World();
};

#endif // __WORLD_HPP__
