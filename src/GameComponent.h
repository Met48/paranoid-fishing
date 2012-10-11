#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H

#include <memory>
#include <typeinfo>

#include <SFML/Graphics.hpp>

#include "Event.h"

class Entity;  // To avoid circular reference

// TODO: Distinguish Attributes from Behaviors

class GameComponent {
protected:
    Entity *parent_;
public:
    GameComponent(Entity *parent) : parent_(parent) { };

    /* virtual void initialize(Entity *parent) {
        parent_ = parent;
    }; */

    virtual void processEvent(const std::type_info &type, Event *ev) { };
};

#endif
