
#ifndef __ABSTRACTSCREENMAP_HPP__
#define __ABSTRACTSCREENMAP_HPP__

#include "defines.hpp"

class AbstractScreenMap {
    private:
        unsigned int        m_map[WIDTH_TILES + 2][HEIGHT_TILES + 2];

    public:

                        AbstractScreenMap   ();

        void            setTile             (unsigned int x, unsigned int y, unsigned int tile);
        unsigned int    getTile             (unsigned int x, unsigned int y);

};

#endif // __ABSTRACTSCREENMAP_HPP__
