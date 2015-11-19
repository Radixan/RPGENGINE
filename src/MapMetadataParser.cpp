
#include "MapMetadataParser.hpp"
#include "FileUtils.hpp"
#include <fstream>
#include <iostream>

Map* MapMetadataParser::parse (std::string filename) {
  std::ifstream file;
  if (!FileUtils::openBinary(file, filename));

  uint16_t id = FileUtils::readBytesAsUINT16(file);
  uint16_t north = FileUtils::readBytesAsUINT16(file);
  uint16_t south = FileUtils::readBytesAsUINT16(file);
  uint16_t east = FileUtils::readBytesAsUINT16(file);
  uint16_t west = FileUtils::readBytesAsUINT16(file);
  uint16_t tilesetID = FileUtils::readBytesAsUINT16(file);

  std::string mapFilename = "";
  char x = FileUtils::readByte(file);
  while ((uint8_t)x != 255 && !file.eof()) {
    mapFilename += x;
    x = FileUtils::readByte(file);
  }

  Map* map = new Map(mapFilename);

  map->setConnections(north, south, east, west);
  map->setID(id);
  map->setTilesetID(tilesetID);

  file.close();
  return map;
}
