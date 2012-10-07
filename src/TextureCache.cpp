#include "TextureCache.h"

std::shared_ptr<sf::Texture> TextureCache::loadTexture(std::string path) {
    auto it = textures.find(path);
    if (it != textures.end()) {
        return it->second;
    } else {
        auto tex = std::make_shared<sf::Texture>();
        if (!tex->loadFromFile(path)) {
            std::string error("Texture load failed for ");
            error += path;
            throw std::runtime_error(error.c_str());
        }
        textures[path] = tex;
        return tex;
    }
}

void TextureCache::releaseTexture(std::string path) {
    auto it = textures.find(path);
    if (it != textures.end()) {
        textures.erase(it);
    }
}

void TextureCache::releaseAll() {
    textures.clear();
}
