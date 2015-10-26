
 #ifndef __FILEUTILS_HPP__
 #define __FILEUTILS_HPP__

#include <fstream>

class FileUtils {
  public:
    static bool       openBinary      (std::ifstream& file, std::string filename);
    static char       readByte        (std::ifstream& file);
    static uint8_t    readByteAsUINT8 (std::ifstream& file);
};

 #endif // __FILEUTILS_HPP__
