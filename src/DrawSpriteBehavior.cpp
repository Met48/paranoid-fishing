#include "DrawSpriteBehavior.h"

#include <memory>
#include <typeinfo>

#include "DrawEvent.h"
#include "Entity.h"
#include "TextureCache.h"
#include "Vector2Attribute.h"

void DrawSpriteBehavior::setImage(std::string texPath) {
    // TODO: Handle exception here (e.x. use dummy image)
    sprite_.setTexture(*TextureCache::getInstance().loadTexture(texPath));
}
void DrawSpriteBehavior::setImage(sf::Texture tex) {
    sprite_.setTexture(tex, true);
}
void DrawSpriteBehavior::setImage(sf::Sprite sprite) {
    sprite_ = sprite;
}

void DrawSpriteBehavior::processEvent(const std::type_info &type, Event *ev) {
    if (type == typeid(DrawEvent)) {
        DrawEvent *ev2 = static_cast<DrawEvent*>(ev);
        sprite_.setPosition(positionComponent_->getX(), positionComponent_->getY());
        ev2->getWindow()->draw(sprite_);
    }
};
