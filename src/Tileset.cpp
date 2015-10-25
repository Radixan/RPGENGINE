
#include "Tileset.hpp"
#include <fstream>
#include "FileUtils.hpp"
#include <iostream>

int16_t Tileset::getWide () {
  return this->m_wide;
}

int16_t Tileset::getHight () {
  return this->m_hight;
}

int16_t Tileset::getTileWide () {
  return this->m_tileWide;
}

int16_t Tileset::getTileHight () {
  return this->m_tileHight;
}

int16_t Tileset::getID () {
  return this->m_ID;
}

sf::Texture& Tileset::getTexture () {
  return this->m_texture;
}

void Tileset::load (std::string filename) {
  std::ifstream file;
  if (!FileUtils::openBinary(file, filename));
  this->m_ID = (FileUtils::readByte(file) << 8 | FileUtils::readByte(file));

  std::string textureFilename = "";
  char x = FileUtils::readByte(file);
  while (x != 0xFF && !file.eof()) {
    textureFilename += x;
    x = FileUtils::readByte(file);
  }

  this->m_texture.loadFromFile(textureFilename);

  this->m_tileWide = (FileUtils::readByte(file) << 8 | FileUtils::readByte(file));
  this->m_tileHight = (FileUtils::readByte(file) << 8 | FileUtils::readByte(file));

  this->m_wide = (FileUtils::readByte(file) << 8 | FileUtils::readByte(file));
  this->m_hight = (FileUtils::readByte(file) << 8 | FileUtils::readByte(file));
}
