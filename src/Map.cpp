
#include "Map.hpp"
#include "FileUtils.hpp"
#include <fstream>

Map::Map() {
  this->m_map = nullptr;
  for (int i = 0; i < 4; i++)
    this->m_conections[0] = nullptr;

  this->m_width = 0;
  this->m_height = 0;
  this->m_scrollx = 0;
  this->m_scrolly = 0;
}

void Map::load (std::string filename) {

  if (this->m_map != nullptr) {
    for (uint8_t i = 0; i < layers; i++) {
      for (uint16_t x = 0; x < this->m_width; x++) {
        delete[] this->m_map[i][x];
      }
      delete[] this->m_map[i];
    }
    delete[] this->m_map;
  }

  std::ifstream file;
  if (!FileUtils::openBinary(file, filename));
  this->m_width = FileUtils::readBytesAsUINT16 (file);
  this->m_height = FileUtils::readBytesAsUINT16 (file);

  uint8_t layers = FileUtils::readByteAsUINT8 (file);

  // Reserve enough memory
  this->m_map = new uint16_t**[layers];
  for (uint8_t i = 0; i < layers; i++) {
    this->m_map[i] = new uint16_t*[this->m_width];
    for (uint16_t x = 0; x < this->m_width; x++) {
      this->m_map[i][x] = new uint16_t [this->m_height];
      for (uint16_t y = 0; y < this->m_height; y++) {
        this->m_map[i][x][y] = FileUtils::readBytesAsUINT16 (file);
      }
    }
  }

}

void setScroll (int16_t x, int16_t y) {
  this->m_scrollx = x;
  this->m_scrolly = y;
}
