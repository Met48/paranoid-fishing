#include "Game.h"

#include "Event.h"
#include "DrawEvent.h"

Game::Game(int width, int height, const char *title) {
    width_ = width;
    height_ = height;

    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(width, height), title);
    window_ = std::unique_ptr<sf::RenderWindow>(window);
}

sf::RenderWindow* Game::getWindow() {
    return &*window_;
}

void Game::start() {
    DrawEvent drawEvent(&*window_);  // TODO: Bit of a hack
    while (window_->isOpen())
    {
        sf::Event ev;
        while (window_->pollEvent(ev))
        {
            // Might be best to move this outside Game class,
            //   or allow it to be disabled
            if (ev.type == sf::Event::Closed)
                window_->close();

            // Pass the event to all entities
            Event sfEvent(&ev);
            for (auto i = entities_.begin(); i != entities_.end(); i++) {
                (*i)->processEvent(typeid(sfEvent), &sfEvent);
            }
        }

        // Draw
        window_->clear();
        for (auto i = entities_.begin(); i != entities_.end(); i++) {
            (*i)->processEvent(typeid(drawEvent), &drawEvent);
        }
        window_->display();
    }
}

void Game::addEntity(std::shared_ptr<Entity> ent) {
    entities_.push_back(ent);
}
