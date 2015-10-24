
#include "AbstractVisibleMap.hpp"

void AbstractVisibleMap::load(std::string filename) {
  this->m_pointer.load(filename);
}

void AbstractVisibleMap::setTileDimension(unsigned int wide, unsigned int hight) {
  this->m_wide = wide;
  this->m_hight = hight;
  this->m_pointer.setTileDimensions(wide, hight);
}

void AbstractVisibleMap::setTilesetDimension (unsigned int wide, unsigned int hight) {
  this->m_pointer.setTextureDimensions(wide, hight);
}

void render (Game *game, unsigned int map[][], unsigned int width, unsigned int hight) {
  for (unsigned int i = 0; i < hight; i++) {
    for (unsigned int j = 0; j < width; j++) {
      this->m_pointer.setPosition(j*this->m_wide, i*this->m_hight);
      this->m_pointer.setIndex(map[j][i]);
      game->getWindow().draw(this->m_pointer);
    }
  }
}
