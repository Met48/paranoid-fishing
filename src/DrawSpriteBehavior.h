#ifndef DRAW_SPRITE_BEHAVIOR_H
#define DRAW_SPRITE_BEHAVIOR_H

#include <memory>
#include <string>

#include "SFML/Graphics.hpp"

#include "GameComponent.h"
#include "Vector2Attribute.h"

#include "Entity.h"

class DrawSpriteBehavior : public GameComponent {
protected:
    Vector2Attribute *positionComponent_;
    sf::Sprite sprite_;
public:
    DrawSpriteBehavior(Entity *parent, std::string texPath) : GameComponent(parent) {
        GameComponent *pos = parent->getAttribute("position");
        if (!pos) {
            pos = &*(parent->addAttribute("position", std::make_shared<Vector2Attribute>(parent)));
        }
        positionComponent_ = static_cast<Vector2Attribute*>(pos);  // Assume right type

        // Initialize texture
        setImage(texPath);
    };

    void setImage(std::string texPath);
    void setImage(sf::Texture tex);
    void setImage(sf::Sprite tex);

    virtual void processEvent(Event *ev);
};

#endif