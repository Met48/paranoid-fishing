#ifndef TICK_EVENT_H
#define TICK_EVENT_H

#include "SFML/System.hpp"

#include "Event.h"

class TickEvent : public Event {
protected:
	sf::Time elapsed_;
public:
    TickEvent(sf::Time elapsed) : elapsed_(elapsed) { };

    sf::Time getElapsed() { return elapsed_; };
};

#endif