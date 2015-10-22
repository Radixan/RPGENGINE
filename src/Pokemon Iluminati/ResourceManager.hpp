
#ifndef __RESOURCEMANAGER_HPP__
#define __RESOURCEMANAGER_HPP__

class ResourceManager {

    public:
        AbstractSprite*     spriteLoader    (const std::string filename);
                            spriteUnloader  (AbstractSprite* sprite);

};

#endif // __RESOURCEMANAGER_HPP__
