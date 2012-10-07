#ifndef EVENT_H
#define EVENT_H

#include "SFML/Graphics.hpp"

// Base class for custom event types
class Event {
public:
    sf::Event *sfEvent;

    Event() { };
    Event(sf::Event *event) { sfEvent = event; };
};

#endif
