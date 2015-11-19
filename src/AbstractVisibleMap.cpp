
#include "AbstractVisibleMap.hpp"
#include <cmath>

AbstractVisibleMap::AbstractVisibleMap() {
  this->m_wide = 0;
  this->m_hight = 0;
  this->m_offsetX = 0;
  this->m_offsetY = 0;
  this->m_map = nullptr;
}

void AbstractVisibleMap::load(std::string filename) {
  this->m_pointer.load(filename);
}

void AbstractVisibleMap::loadTileset (Tileset& tileset) {
  this->m_pointer.loadTexture(tileset.getTexture());
  this->setTileDimension(tileset.getTileWide(), tileset.getTileHight());
  this->setTilesetDimension(tileset.getWide(), tileset.getHight());
}

void AbstractVisibleMap::setTileDimension(uint16_t wide, uint16_t hight) {
  // Delete old map, if it exists
  if (this->m_map != nullptr) {
    for (uint16_t i = 0; i < this->m_nTilesX; i++) {
      delete[] this->m_map[i];
    }
    delete[] this->m_map;
  }

  this->m_wide = wide;
  this->m_hight = hight;
  this->m_pointer.setDimensions(wide, hight);

  // Reserve new memory
  // +1 Round up
  // +2 Out of bounds tiles
  this->m_nTilesX = (uint16_t)(std::ceil(WIN_X / this->m_wide)) + 1 + 2;
  this->m_nTilesY = (uint16_t)(std::ceil(WIN_Y / this->m_hight)) + 1 + 2;
  this->m_map = new uint16_t* [this->m_nTilesX];
  for (uint16_t i = 0; i < this->m_nTilesX; i++) {
    this->m_map[i] = new uint16_t [this->m_nTilesY];
    // Empty the new map
    for (uint16_t j = 0; j < this->m_nTilesY; j++)
      this->m_map[i][j] = 0;
  }
}

void AbstractVisibleMap::setTilesetDimension (uint16_t wide, uint16_t hight) {
  this->m_pointer.setTextureDimensions(wide, hight);
}

void AbstractVisibleMap::render (Game *game, uint16_t width, uint16_t hight) {
  for (uint16_t i = 0; i < hight && i < this->m_nTilesY; i++) {
    for (uint16_t j = 0; j < width && j < this->m_nTilesX; j++) {
      this->m_pointer.setPosition(j*this->m_wide + this->m_offsetX,
                                  i*this->m_hight + this->m_offsetY);
      this->m_pointer.setIndex(this->m_map[j][i]);
      this->m_pointer.update(game->getFrameTime());
      this->m_pointer.render(game);
    }
  }
}

void AbstractVisibleMap::setTile (int16_t x, int16_t y, uint16_t tile) {
  if (x < 0 || x >= this->m_nTilesX) return;
  if (y < 0 || y >= this->m_nTilesY) return;
  this->m_map[x][y] = tile;
}

unsigned int AbstractVisibleMap::getTile (int16_t x, int16_t y) {
  if (x < 0 || x >= this->m_nTilesX) return 0;
  if (y < 0 || y >= this->m_nTilesY) return 0;
  return this->m_map[x][y];
}

void AbstractVisibleMap::setOffset (int16_t x, int16_t y) {
  this->m_offsetX = x;
  this->m_offsetY = y;
}

AbstractVisibleMap::~AbstractVisibleMap() {
  // Delete old map, if it exists
  if (this->m_map != nullptr) {
    for (uint16_t i = 0; i < this->m_nTilesX; i++) {
      delete[] this->m_map[i];
    }
    delete[] this->m_map;
  }
}
