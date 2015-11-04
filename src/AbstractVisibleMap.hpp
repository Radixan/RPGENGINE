
#ifndef __ABSTRACTVISIBLEMAP_HPP__
#define __ABSTRACTVISIBLEMAP_HPP__

#include <SFML/Graphics.hpp>

#include "AbstractSprite.hpp"
#include "Tileset.hpp"
#include "defines.hpp"

class AbstractVisibleMap {

  private:
    AbstractSprite      m_pointer;
    unsigned int        m_wide;
    unsigned int        m_hight;
    int                 m_offsetX;
    int                 m_offsetY;
    unsigned int        m_map[WIDTH_TILES][HEIGHT_TILES];

  public:
    AbstractVisibleMap              ();
    void        loadTileset         (Tileset& tileset);
    void        setTileDimension    (unsigned int wide, unsigned int hight);
    void        setTilesetDimension (unsigned int wide, unsigned int hight);
    void        setOffset           (int x, int y);
    void        render              (Game* game, unsigned int **map, unsigned int width, unsigned int hight );

    unsigned int getTile            (int x, int y);
    void         setTile            (int x, int y, unsigned int tile);

    // Deprecated
    void        load                (std::string filename);
};

#endif //  __ABSTRACTVISIBLEMAP_HPP__
