
#include "AbstractVisibleMap.hpp"

AbstractVisibleMap::AbstractVisibleMap() {
  this->m_wide = 0;
  this->m_hight = 0;
  this->m_offsetX = 0;
  this->m_offsetY = 0;
}

void AbstractVisibleMap::load(std::string filename) {
  this->m_pointer.load(filename);
}

void AbstractVisibleMap::loadTileset (Tileset& tileset) {
  this->m_pointer.loadTexture(tileset.getTexture());
}

void AbstractVisibleMap::setTileDimension(unsigned int wide, unsigned int hight) {
  this->m_wide = wide;
  this->m_hight = hight;
  this->m_pointer.setDimensions(wide, hight);
}

void AbstractVisibleMap::setTilesetDimension (unsigned int wide, unsigned int hight) {
  this->m_pointer.setTextureDimensions(wide, hight);
}

void AbstractVisibleMap::render (Game *game, unsigned int **map, unsigned int width, unsigned int hight) {
  for (unsigned int i = 0; i < hight; i++) {
    for (unsigned int j = 0; j < width; j++) {
      this->m_pointer.setPosition(j*this->m_wide + this->m_offsetX,
                                  i*this->m_hight + this->m_offsetY);
      this->m_pointer.setIndex(map[j][i]);
      this->m_pointer.update();
      this->m_pointer.render(game);
    }
  }
}

void AbstractVisibleMap::setOffset (int x, int y) {
  this->m_offsetX = x;
  this->m_offsetY = y;
}
