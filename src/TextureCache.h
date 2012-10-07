#ifndef TEXTURE_CACHE_H
#define TEXTURE_CACHE_H

#include <map>
#include <memory>
#include <string>

#include "SFML/Graphics.hpp"

class TextureCache {
private:
    std::map<std::string, std::shared_ptr<sf::Texture> > textures;
public:
    static TextureCache& getInstance() {
        static TextureCache instance;
        return instance;
    }

    std::shared_ptr<sf::Texture> loadTexture(std::string path);
    void releaseTexture(std::string path);
    void releaseAll();
};

#endif