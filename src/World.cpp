
#include "World.hpp"
#include <fstream>
#include "FileUtils.hpp"
#include "MapMetadataParser.hpp"

void World::Construct() {
  this->m_maps = nullptr;
  this->m_nmaps = 0;
  this->m_tilesets = nullptr;
  this->m_ntilesets = 0;
}

World::World() {
  this->Construct();
}
#include <iostream>
World::World(std::string filename) {
  this->Construct();
  this->load(filename);
}

void World::load (std::string filename) {
  std::ifstream file;
  if (!FileUtils::openBinary(file, filename));

  this->m_ntilesets = FileUtils::readBytesAsUINT16(file);
  this->m_tilesets = new Tileset* [this->m_ntilesets];

  // Load tilesets in memory
  for (uint16_t i = 0; i < this->m_ntilesets; i++) {
    std::string tilesetFilename = "";
    char x = FileUtils::readByte(file);
    while ((uint8_t)x != 255 && !file.eof()) {
      tilesetFilename += x;
      x = FileUtils::readByte(file);
    }
    this->m_tilesets[i] = new Tileset(tilesetFilename);
  }

  this->m_nmaps = FileUtils::readBytesAsUINT16(file);
  this->m_maps = new Map* [this->m_nmaps];

  // Load maps in memory
  for (uint16_t i = 0; i < this->m_nmaps; i++) {
    std::string mapFilename = "";
    char x = FileUtils::readByte(file);
    while ((uint8_t)x != 255 && !file.eof()) {
      mapFilename += x;
      x = FileUtils::readByte(file);
    }

    this->m_maps[i] = MapMetadataParser::parse(mapFilename);
    for (int j = 0; j < this->m_ntilesets; j++) {
      if (this->m_tilesets[j]->getID() == this->m_maps[i]->getTilesetID()) {
        this->m_maps[i]->setTileset(this->m_tilesets[j]);
      }
    }
  }

  file.close();
}

void World::lockSprite (AbstractSprite& sprite) {

}

Map* World::getMap() {
  return this->m_maps[0];
}

World::~World() {
  for (uint16_t i = 0; i < this->m_nmaps; i++)
    delete this->m_maps[i];
  delete[] this->m_maps;
}
