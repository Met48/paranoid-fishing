#include "PlayerMovementBehavior.h"

#include "SFML/System.hpp"

#include "Event.h"
#include "TickEvent.h"

void PlayerMovementBehavior::processEvent(const std::type_info &type, Event *ev) {
	if (type == typeid(Event)) {
		sf::Event *ev2 = ev->sfEvent;
		// TODO: Refactor
		if (ev2->type == sf::Event::KeyPressed) {
			if (ev2->key.code == sf::Keyboard::W) {
				velocityComponent_->setY(velocityComponent_->getY() - ySpeed_);
			} else if (ev2->key.code == sf::Keyboard::S) {
				velocityComponent_->setY(velocityComponent_->getY() + ySpeed_);
			} else if (ev2->key.code == sf::Keyboard::A) {
				velocityComponent_->setX(velocityComponent_->getX() - xSpeed_);
			} else if (ev2->key.code == sf::Keyboard::D) {
				velocityComponent_->setX(velocityComponent_->getX() + xSpeed_);
			}
		} else if (ev2->type == sf::Event::KeyReleased) {
			if (ev2->key.code == sf::Keyboard::W) {
				velocityComponent_->setY(velocityComponent_->getY() + ySpeed_);
			} else if (ev2->key.code == sf::Keyboard::S) {
				velocityComponent_->setY(velocityComponent_->getY() - ySpeed_);
			} else if (ev2->key.code == sf::Keyboard::A) {
				velocityComponent_->setX(velocityComponent_->getX() + xSpeed_);
			} else if (ev2->key.code == sf::Keyboard::D) {
				velocityComponent_->setX(velocityComponent_->getX() - xSpeed_);
			}
		}
	} else if(type == typeid(TickEvent)) {
		// TODO: Move to dedicated physics component
		TickEvent *ev2 = static_cast<TickEvent*>(ev);
		positionComponent_->setX(positionComponent_->getX() + velocityComponent_->getX() * ev2->getElapsed().asSeconds());
		positionComponent_->setY(positionComponent_->getY() + velocityComponent_->getY() * ev2->getElapsed().asSeconds());
	}
}