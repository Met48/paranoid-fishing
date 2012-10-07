#pragma once
#ifndef GAME_H
#define GAME_H

#include <list>
#include <memory>

#include "SFML/Graphics.hpp"

#include "Entity.h"

class Game {
protected:
    int width_;
    int height_;

    std::unique_ptr<sf::RenderWindow> window_;

    std::list<std::shared_ptr<Entity> > entities_;
public:
    Game(int width, int height, const char *title);
    
    sf::RenderWindow* getWindow();

    void addEntity(std::shared_ptr<Entity> ent);

    void start();
};

#endif
