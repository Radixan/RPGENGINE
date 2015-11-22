
#include "World.hpp"
#include <fstream>
#include "FileUtils.hpp"
#include "MapMetadataParser.hpp"

void World::Construct() {

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

  uint16_t ntilesets = FileUtils::readBytesAsUINT16(file);

  // Load tilesets in memory
  for (uint16_t i = 0; i < ntilesets; i++) {
    std::string tilesetFilename = "";
    char x = FileUtils::readByte(file);
    while ((uint8_t)x != 255 && !file.eof()) {
      tilesetFilename += x;
      x = FileUtils::readByte(file);
    }

    Tileset* tileset = new Tileset(tilesetFilename);
    this->m_tilesets[tileset->getID()] = tileset;
  }

  uint16_t nmaps = FileUtils::readBytesAsUINT16(file);

  // Load maps in memory
  for (uint16_t i = 0; i < nmaps; i++) {
    std::string mapFilename = "";
    char x = FileUtils::readByte(file);
    while ((uint8_t)x != 255 && !file.eof()) {
      mapFilename += x;
      x = FileUtils::readByte(file);
    }

    Map* map = MapMetadataParser::parse(mapFilename);
    this->m_maps[map->getID()] = map;
    this->m_maps[map->getID()]->setTileset(this->m_tilesets[map->getTilesetID()]);
  }

  file.close();
}

void World::lockSprite (AbstractSprite& sprite) {
  int16_t tilex = (WIN_X/2)/this->m_tilesets[this->m_actualMap->getTilesetID()]->getTileWide();
  int16_t tiley = (WIN_Y/2)/this->m_tilesets[this->m_actualMap->getTilesetID()]->getTileHight();
  sprite.setPosition(tilex*64, tiley*64);
}

void World::setCamera(int16_t x, int16_t y) {
  this->x = x;
  this->y = y;
}

void World::setActualMap (uint16_t map) {
  this->m_actualMap = this->m_maps[map];
  /*this->m_actualNorthMap = this->m_maps[this->m_actualMap->getNorthMap()];
  this->m_actualSouthMap = this->m_maps[this->m_actualMap->getSouthMap()];
  this->m_actualEastMap = this->m_maps[this->m_actualMap->getEastMap()];
  this->m_actualWestMap = this->m_maps[this->m_actualMap->getWestMap()];*/
}

Map* World::getMap() {
  return this->m_actualMap;
}

// FIXME: Imposible Loop map
void World::update (sf::Time deltaTime) {
  uint16_t tileW = this->m_tilesets[this->m_actualMap->getTilesetID()]->getTileWide();
  uint16_t tileH = this->m_tilesets[this->m_actualMap->getTilesetID()]->getTileHight();
  int16_t startTileX = (this->x / tileW) - ((WIN_X / 2) / tileW);
  int16_t startTileY = (this->y / tileH) - ((WIN_Y / 2) / tileH);
  this->m_actualMap->setScroll(-this->x % tileW, -this->y % tileH);
  this->m_actualMap->update(deltaTime, startTileX, startTileY, (WIN_X / tileW)+1, (WIN_Y / tileH)+1);
}

void World::render (Game* game) {
  this->m_actualMap->render(game);
  /*this->m_actualNorthMap->render(game);
  this->m_actualSouthMap->render(game);
  this->m_actualEastMap->render(game);
  this->m_actualWestMap->render(game);*/
}

World::~World() {
  for (auto tileset = this->m_tilesets.begin(); tileset != this->m_tilesets.end(); tileset++)
    delete tileset->second;
  this->m_tilesets.clear();

  for (auto map = this->m_maps.begin(); map != this->m_maps.end(); map++)
    delete map->second;
  this->m_maps.clear();
}
