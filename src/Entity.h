#ifndef ENTITY_H
#define ENTITY_H

#include <list>
#include <string>

#include "Event.h"
#include "GameComponent.h"

class Entity {
protected:
    // Attributes hold data but have minimal behavior
    std::map<std::string, std::shared_ptr<GameComponent> > attributes_;
    std::list<std::shared_ptr<GameComponent> > behaviors_;
public:
    bool hasAttribute(std::string name);
    GameComponent* getAttribute(std::string name);  // TODO: Use shared_ptr?
    std::shared_ptr<GameComponent> addAttribute(std::string name, GameComponent *component);
    std::shared_ptr<GameComponent> addAttribute(std::string name, std::shared_ptr<GameComponent> component);
    std::shared_ptr<GameComponent> addBehavior(GameComponent *component);
    std::shared_ptr<GameComponent> addBehavior(std::shared_ptr<GameComponent> component);

    void processEvent(Event *ev);
};

#endif