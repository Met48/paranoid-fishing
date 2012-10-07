#ifndef DRAW_EVENT_H
#define DRAW_EVENT_H

#include "SFML/Graphics.hpp"

#include "Event.h"

class DrawEvent : public Event {
protected:
    sf::RenderWindow *window_;
public:
    DrawEvent(sf::RenderWindow *window) : window_(window) { };

    sf::RenderWindow* getWindow() { return window_; };
};

#endif