
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
  if (file.eof() || !file.good()) return 0x00;
  return file.get();
}

uint8_t FileUtils::readByteAsUINT8 (std::ifstream& file) {
  if (file.eof() || !file.good()) return 0x00;
  return file.get();
}

uint16_t FileUtils::readBytesAsUINT16 (std::ifstream& file) {
  return (FileUtils::readByteAsUINT8(file) << 8 | FileUtils::readByteAsUINT8(file));
}

int8_t FileUtils::readByteAsINT8 (std::ifstream& file) {
  if (file.eof() || !file.good()) return 0x00;
  return file.get();
}

int16_t FileUtils::readBytesAsINT16 (std::ifstream& file) {
  return (FileUtils::readByteAsINT8(file) << 8 | FileUtils::readByteAsINT8(file));
}
