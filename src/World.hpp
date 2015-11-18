
#ifndef __WORLD_HPP__
#define __WORLD_HPP__

#include "defines.hpp"
#include "Map.hpp"

class World {
    private:
      Map**                   m_maps;
      uint16_t                m_nmaps;

    public:
      World();

      void        load              (std::string filename);

      // Sprites Related
      int         getRelativeX      (int x);
      int         getRelativeY      (int y);

      ~World();
};

#endif // __WORLD_HPP__
