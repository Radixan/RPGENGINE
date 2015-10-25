
#include "FileUtils.hpp"

bool FileUtils::openBinary (std::ifstream& file, std::string filename) {
  file.open(filename, std::ios::in | std::ios::binary);
  if (file.is_open()) {
    file.seekg (0, file.beg);
    return true;
  }
  return false;
}

char FileUtils::readByte (std::ifstream& file) {
  if (file.eof()) return 0x00;
  return file.get();
}
