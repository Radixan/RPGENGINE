
#include "Map.hpp"
#include "FileUtils.hpp"
#include <fstream>
#include <iostream>

Map::Map() {
  this->m_visibleMap = nullptr;
  this->m_map = nullptr;
/*  for (int i = 0; i < 4; i++)
    this->m_conections[0] = nullptr;*/

  this->m_width = 0;
  this->m_height = 0;
  this->m_scrollx = 0;
  this->m_scrolly = 0;
  this->m_layers = 0;
  this->m_renderWidth = 0;
  this->m_renderHeight = 0;
}

void Map::setTileset (Tileset* tileset) {
  if (this->m_visibleMap != nullptr) {
    for (uint8_t i = 0; i < this->m_layers; i++) {
      this->m_visibleMap[i].loadTileset(*tileset);
    }
  }
}

void Map::load (std::string filename) {

  if (this->m_map != nullptr) {
    for (uint8_t i = 0; i < this->m_layers; i++) {
      for (uint16_t x = 0; x < this->m_width; x++) {
        delete[] this->m_map[i][x];
      }
      delete[] this->m_map[i];
    }
    delete[] this->m_map;
  }
  if (this->m_visibleMap != nullptr)
    delete[] this->m_visibleMap;

  std::ifstream file;
  if (!FileUtils::openBinary(file, filename)) std::cout << "Error Opening file" << std::endl;
  this->m_width = FileUtils::readBytesAsUINT16 (file);
  this->m_height = FileUtils::readBytesAsUINT16 (file);
  this->m_layers = FileUtils::readByteAsUINT8 (file);

  // Reserve enough memory
  // FIXME: reverse map
  this->m_map = new uint16_t**[this->m_layers];
  this->m_visibleMap = new AbstractVisibleMap[this->m_layers];
  for (uint8_t i = 0; i < this->m_layers; i++) {
    this->m_map[i] = new uint16_t*[this->m_width];
    for (uint16_t y = 0; y < this->m_height; y++) {
      this->m_map[i][y] = new uint16_t [this->m_height];
      for (uint16_t x = 0; x < this->m_width; x++) {
        this->m_map[i][y][x] = FileUtils::readBytesAsUINT16 (file);
      }
    }
  }

}

void Map::setScroll (int16_t x, int16_t y) {
  this->m_scrollx = x;
  this->m_scrolly = y;
}
/*
void Map::setConnections (Map* north, Map* south, Map* east, Map* west) {
  this->m_conections[0] = north;
  this->m_conections[1] = south;
  this->m_conections[2] = east;
  this->m_conections[3] = west;
}*/
/*
void Map::setDimensions (uint16_t width, uint16_t height) {
  this->m_width = width;
  this->m_height = height;
}
*/
void Map::update (sf::Time deltaTime, uint16_t startTileX, uint16_t startTileY, uint16_t width, uint16_t hight) {
  if (this->m_visibleMap != nullptr) {
    this->m_renderWidth = width;
    this->m_renderHeight = hight;
    for (uint8_t i = 0; i < this->m_layers; i++) {
      this->m_visibleMap[i].setOffset(this->m_scrollx, this->m_scrolly);

      // FIXME: Reverse map
      for (uint16_t x = startTileX; x < width + startTileX; x++) {
        for (uint16_t y = startTileY; y < hight + startTileY; y++) {
          this->m_visibleMap[i].setTile(x - startTileX, y - startTileY, this->m_map[i][y][x]);
        }
      }
    }
  }
}

void Map::render (Game* game) {
  if (this->m_visibleMap != nullptr) {
    for (uint8_t i = 0; i < this->m_layers; i++) {
        this->m_visibleMap[i].render(game, this->m_renderWidth, this->m_renderHeight);
    }
  }
}

Map::~Map () {
  if (this->m_map != nullptr) {
    for (uint8_t i = 0; i < this->m_layers; i++) {
      for (uint16_t x = 0; x < this->m_width; x++) {
        delete[] this->m_map[i][x];
      }
      delete[] this->m_map[i];
    }
    delete[] this->m_map;
  }
  if (this->m_visibleMap != nullptr)
    delete[] this->m_visibleMap;
}
