#include "Entity.h"

#include <memory>

bool Entity::hasAttribute(std::string name) {
    auto i = attributes_.find(name);
    return i != attributes_.end();
}

GameComponent* Entity::getAttribute(std::string name) {
    auto i = attributes_.find(name);
    if (i == attributes_.end()) {
        throw std::runtime_error("Unable to find attribute " + name + ".");
    }
    return &*(i->second);  // TODO: Bit of a hack
}

std::shared_ptr<GameComponent> Entity::addAttribute(std::string name, GameComponent *component) {
    auto ptr = std::shared_ptr<GameComponent>(component);
    return addAttribute(name, ptr);
}

std::shared_ptr<GameComponent> Entity::addAttribute(std::string name, std::shared_ptr<GameComponent> component) {
    attributes_[name] = component;
    return component;
}

std::shared_ptr<GameComponent> Entity::addBehavior(GameComponent *component) {
    auto ptr = std::shared_ptr<GameComponent>(component);
    return addBehavior(ptr);
}

std::shared_ptr<GameComponent> Entity::addBehavior(std::shared_ptr<GameComponent> component) {
    behaviors_.push_back(component);
    return component;
}

void Entity::processEvent(Event *ev) {
    // Only behaviors need to see this events
    for (auto i = behaviors_.begin(); i != behaviors_.end(); i++) {
        (*i)->processEvent(ev);
    }
}
