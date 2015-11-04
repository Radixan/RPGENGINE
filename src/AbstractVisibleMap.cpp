
#include "AbstractVisibleMap.hpp"

AbstractVisibleMap::AbstractVisibleMap() {
  this->m_wide = 0;
  this->m_hight = 0;
  this->m_offsetX = 0;
  this->m_offsetY = 0;
  for (int i = 0; i < WIDTH_TILES; i++) {
    for (int j = 0; j < HEIGHT_TILES; j++)
      this->m_map[i][j] = 0;
  }
}

void AbstractVisibleMap::load(std::string filename) {
  this->m_pointer.load(filename);
}

void AbstractVisibleMap::loadTileset (Tileset& tileset) {
  this->m_pointer.loadTexture(tileset.getTexture());
  this->setTileDimension(tileset.getTileWide(), tileset.getTileHight());
  this->setTilesetDimension(tileset.getWide(), tileset.getHight());
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
      this->m_pointer.setIndex(this->m_map[j][i]);
      this->m_pointer.update();
      this->m_pointer.render(game);
    }
  }
}

void setTile (int x, int y, unsigned int tile) {
  if (x < 0 || x >= WIDTH_TILES) return;
  if (y < 0 || y >= HEIGHT_TILES) return;
  this->m_map[x][y] = tile;
}

unsigned int getTile (int x, int y) {
  if (x < 0 || x >= WIDTH_TILES) return 0;
  if (y < 0 || y >= HEIGHT_TILES) return 0;
  return this->m_map[x][y];
}

void AbstractVisibleMap::setOffset (int x, int y) {
  this->m_offsetX = x;
  this->m_offsetY = y;
}
