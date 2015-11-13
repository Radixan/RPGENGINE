
#include "AbstractVisibleMap.hpp"
#include <cmath>

AbstractVisibleMap::AbstractVisibleMap() {
  this->m_wide = 0;
  this->m_hight = 0;
  this->m_offsetX = 0;
  this->m_offsetY = 0;
  this->m_map = nullptr;
  /*for (int i = 0; i < WIDTH_TILES; i++) {
    for (int j = 0; j < HEIGHT_TILES; j++)
      this->m_map[i][j] = 0;
  }*/
}

void AbstractVisibleMap::load(std::string filename) {
  this->m_pointer.load(filename);
}

void AbstractVisibleMap::loadTileset (Tileset& tileset) {
  this->m_pointer.loadTexture(tileset.getTexture());
  this->setTileDimension(tileset.getTileWide(), tileset.getTileHight());
  this->setTilesetDimension(tileset.getWide(), tileset.getHight());
}

#include <iostream>
void AbstractVisibleMap::setTileDimension(unsigned int wide, unsigned int hight) {
  // Delete old map, if it exists
  if (this->m_map != nullptr) {
    for (unsigned int i = 0; i < this->m_nTilesX; i++) {
      delete[] this->m_map[i];
    }
    delete[] this->m_map;
  }  

  this->m_wide = wide;
  this->m_hight = hight;
  this->m_pointer.setDimensions(wide, hight);

  // Reserve new memory
  this->m_nTilesX = (unsigned int)(std::ceil(WIN_X / this->m_wide));
  this->m_nTilesY = (unsigned int)(std::ceil(WIN_Y / this->m_hight));
  this->m_map = new unsigned int* [this->m_nTilesX];
  for (unsigned int i = 0; i < this->m_nTilesX; i++) {
    this->m_map[i] = new unsigned int [this->m_nTilesY];
    // Empty the new map
    for (int j = 0; j < this->m_nTilesY; i++)
      this->m_map[i][j] = 0;
  }
}

void AbstractVisibleMap::setTilesetDimension (unsigned int wide, unsigned int hight) {
  this->m_pointer.setTextureDimensions(wide, hight);
}

void AbstractVisibleMap::render (Game *game, unsigned int width, unsigned int hight) {
  for (unsigned int i = 0; i < hight && i < this->m_nTilesY; i++) {
    for (unsigned int j = 0; j < width && j < this->m_nTilesX; j++) {
      this->m_pointer.setPosition(j*this->m_wide + this->m_offsetX,
                                  i*this->m_hight + this->m_offsetY);
      this->m_pointer.setIndex(this->m_map[j][i]);
      this->m_pointer.update(game->getFrameTime());
      this->m_pointer.render(game);
    }
  }
}

void AbstractVisibleMap::setTile (int x, int y, unsigned int tile) {
  if (x < 0 || x >= this->m_nTilesX) return;
  if (y < 0 || y >= this->m_nTilesY) return;
  this->m_map[x][y] = tile;
}

unsigned int AbstractVisibleMap::getTile (int x, int y) {
  if (x < 0 || x >= this->m_nTilesX) return 0;
  if (y < 0 || y >= this->m_nTilesY) return 0;
  return this->m_map[x][y];
}

void AbstractVisibleMap::setOffset (int x, int y) {
  this->m_offsetX = x;
  this->m_offsetY = y;
}
