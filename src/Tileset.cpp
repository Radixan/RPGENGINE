
#include "Tileset.hpp"
#include <fstream>
#include "FileUtils.hpp"
#include <iostream>

void Tileset::Construct() {
  this->m_ID = 0;
  this->m_tileWide = 0;
  this->m_tileHight = 0;
  this->m_wide = 0;
  this->m_hight = 0;
}

Tileset::Tileset() {
  this->Construct();
}

Tileset::Tileset(std::string filename) {
  this->Construct();
  this->load(filename);
}

uint16_t Tileset::getWide () {
  return this->m_wide;
}

uint16_t Tileset::getHight () {
  return this->m_hight;
}

uint16_t Tileset::getTileWide () {
  return this->m_tileWide;
}

uint16_t Tileset::getTileHight () {
  return this->m_tileHight;
}

uint16_t Tileset::getID () {
  return this->m_ID;
}

sf::Texture& Tileset::getTexture () {
  return this->m_texture;
}

void Tileset::load (std::string filename) {
  std::ifstream file;
  if (!FileUtils::openBinary(file, filename));
  this->m_ID = FileUtils::readBytesAsUINT16 (file);

  std::string textureFilename = "";
  char x = FileUtils::readByte(file);
  while ((uint8_t)x != 255 && !file.eof()) {
    textureFilename += x;
    x = FileUtils::readByte(file);
  }

  this->m_texture.loadFromFile(textureFilename);

  this->m_tileWide = FileUtils::readBytesAsUINT16 (file);
  this->m_tileHight = FileUtils::readBytesAsUINT16 (file);

  this->m_wide = FileUtils::readBytesAsUINT16 (file);
  this->m_hight = FileUtils::readBytesAsUINT16 (file);
}
