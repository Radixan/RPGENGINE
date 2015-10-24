
#ifndef __ABSTRACTVISIBLEMAP_HPP__
#define __ABSTRACTVISIBLEMAP_HPP__

#include <SFML/Graphics.hpp>

#include "AbstractSprite.hpp"

class AbstractVisibleMap {

  private:
    AbstractSprite      m_pointer;
    unsigned int        m_wide;
    unsigned int        m_hight;
    int                 m_offsetX;
    int                 m_offsetY;

  public:
    AbstractVisibleMap              ();
    void        load                (std::string filename);
    void        setTileDimension    (unsigned int wide, unsigned int hight);
    void        setTilesetDimension (unsigned int wide, unsigned int hight);
    void        setOffset           (int x, int y);

    // Render 1 tile out of the map (TOP-LEFT)
    void        render              (Game* game, unsigned int **map, unsigned int width, unsigned int hight );
};

#endif //  __ABSTRACTVISIBLEMAP_HPP__
