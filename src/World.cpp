
#include "World.hpp"
#include <fstream>
#include "FileUtils.hpp"

World::World() {
  this->m_maps = nullptr;
  this->m_nmaps = 0;
}

void World::load (std::string filename) {
  std::ifstream file;
  if (!FileUtils::openBinary(file, filename));

  this->m_nmaps = FileUtils::readBytesAsUINT16(file);
  this->m_maps = new Map* [this->m_nmaps];
}

int World::getRelativeX (int x) {
  return 0;
}

int World::getRelativeY (int y) {
  return 0;
}

World::~World() {
  delete[] this->m_maps;
}
