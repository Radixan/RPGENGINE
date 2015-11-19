#ifndef __MAPMETADATAPARSER_HPP__
#define __MAPMETADATAPARSER_HPP__

#include "Map.hpp"

class MapMetadataParser {
  public:
    static Map* parse (std::string filename);
};

#endif // __MAPMETADATAPARSER_HPP__
