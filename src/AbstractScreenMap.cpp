
#include "AbstractScreenMap.hpp"

AbstractScreenMap::AbstractScreenMap() {
    for (int i = 0; i < WIDTH_TILES+2; i++) {
        for (int j = 0; j < HEIGHT_TILES+2; j++) {
            this->m_map[i][j] = 0;
        }
    }
}

void AbstractScreenMap::setTile(unsigned int x, unsigned int y, unsigned int tile) {
    this->m_map[x][y] = tile;
}

unsigned int AbstractScreenMap::getTile(unsigned int x, unsigned int y) {
    return this->m_map[x][y];
}
