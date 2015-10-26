
#ifndef __ABSTRACTVISIBLEMAP_HPP__
#define __ABSTRACTVISIBLEMAP_HPP__

#include <SFML/Graphics.hpp>

#include "AbstractSprite.hpp"
#include "Tileset.hpp"

class AbstractVisibleMap {

  private:
    AbstractSprite      m_pointer;
    unsigned int        m_wide;
    unsigned int        m_hight;
    int                 m_offsetX;
    int                 m_offsetY;

  public:
    AbstractVisibleMap              ();
    void        loadTileset         (Tileset& tileset);
    void        setTileDimension    (unsigned int wide, unsigned int hight);
    void        setTilesetDimension (unsigned int wide, unsigned int hight);
    void        setOffset           (int x, int y);
    void        render              (Game* game, unsigned int **map, unsigned int width, unsigned int hight );

    // Deprecated
    void        load                (std::string filename);
};

#endif //  __ABSTRACTVISIBLEMAP_HPP__
