
#ifndef __RESOURCEMANAGER_HPP__
#define __RESOURCEMANAGER_HPP__

#include "AbstractSprite.hpp"

class ResourceManager {

    public:
        AbstractSprite*     spriteLoader    (const std::string filename);
        void                spriteUnloader  (AbstractSprite* sprite);

};

#endif // __RESOURCEMANAGER_HPP__
