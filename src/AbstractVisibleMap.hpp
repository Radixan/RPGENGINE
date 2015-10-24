
#ifndef __ABSTRACTVISIBLEMAP_HPP__
#define __ABSTRACTVISIBLEMAP_HPP__

#include <SFML/Graphics.hpp>

class AbstractVisibleMap {

  private:
    AbstractSprite      m_pointer;
    unsigned int        m_wide;
    unsigned int        m_hight;

  public:
    void        load                (std::string filename);
    void        setTileDimension    (unsigned int wide, unsigned int hight);
    void        setTilesetDimension (unsigned int wide, unsigned int hight);

    // Render 1 tile out of the map (TOP-LEFT)
    void        render              (unsigned int map[][], unsigned int width, unsigned int hight );
}

#ifndef /* __ABSTRACTVISIBLEMAP_HPP__ */
