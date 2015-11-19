
#ifndef __WORLD_HPP__
#define __WORLD_HPP__

#include "defines.hpp"
#include "Map.hpp"
#include "Tileset.hpp"

class World {
    private:
      Map**                   m_maps;
      uint16_t                m_nmaps;
      Tileset**               m_tilesets;
      uint16_t                m_ntilesets;

      void        Construct     ();

    public:
      World();
      World(std::string filename);

      void        load              (std::string filename);
      void        lockSprite        (AbstractSprite& sprite);

      Map*        getMap();

      ~World();
};

#endif // __WORLD_HPP__
