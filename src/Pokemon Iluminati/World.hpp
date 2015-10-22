
#ifndef __WORLD_HPP__
#define __WORLD_HPP__

#define     MAX_MAPS        16

#include "Map.hpp"
#include "AbstractScreenMap.hpp"

class World {
    private:
        Map                     m_maps[MAX_MAPS];
        AbstractScreenMap       m_screenMap;

    public:


};

#endif // __WORLD_HPP__
