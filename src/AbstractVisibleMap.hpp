
#ifndef __ABSTRACTVISIBLEMAP_HPP__
#define __ABSTRACTVISIBLEMAP_HPP__

#include <SFML/Graphics.hpp>

#include "AbstractSprite.hpp"
#include "Tileset.hpp"
#include "defines.hpp"

class AbstractVisibleMap {

  private:
    AbstractSprite      m_pointer;
    uint16_t             m_wide;
    uint16_t            m_hight;
    uint16_t            m_nTilesX;
    uint16_t            m_nTilesY;
    int16_t             m_offsetX;
    int16_t             m_offsetY;
    uint16_t**          m_map;

  public:
    AbstractVisibleMap              ();
    void        loadTileset         (Tileset& tileset);
    void        setTileDimension    (uint16_t wide, uint16_t hight);
    void        setTilesetDimension (uint16_t wide, uint16_t hight); // Neded to reserve enought space
    void        setOffset           (int16_t x, int16_t y);
    void        render              (Game* game, uint16_t width, uint16_t hight );

    unsigned int getTile            (int16_t x, int16_t y);
    void         setTile            (int16_t x, int16_t y, uint16_t tile);

    ~AbstractVisibleMap             ();

    // Deprecated
    void        load                (std::string filename);
};

#endif //  __ABSTRACTVISIBLEMAP_HPP__
