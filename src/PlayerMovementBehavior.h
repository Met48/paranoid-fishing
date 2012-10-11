#ifndef PLAYER_MOVEMENT_BEHAVIOR_H
#define PLAYER_MOVEMENT_BEHAVIOR_H

#include <memory>
#include <string>

#include "GameComponent.h"
#include "Vector2Attribute.h"

#include "Entity.h"

class PlayerMovementBehavior : public GameComponent {
protected:
    Vector2Attribute *positionComponent_;
	Vector2Attribute *velocityComponent_;

	float xSpeed_;
	float ySpeed_;

	void initComponents(Entity *parent) {
        GameComponent *pos = parent->getAttribute("position");
		GameComponent *vel = parent->getAttribute("velocity");
        if (!pos) {
            pos = &*(parent->addAttribute("position", std::make_shared<Vector2Attribute>(parent)));
        }
		if (!vel) {
			vel = &*(parent->addAttribute("velocity", std::make_shared<Vector2Attribute>(parent)));
		}
        positionComponent_ = static_cast<Vector2Attribute*>(pos);  // Assume right type
        velocityComponent_ = static_cast<Vector2Attribute*>(vel);  // Assume right type
	};
public:
	PlayerMovementBehavior(Entity *parent, float xSpeed, float ySpeed) : GameComponent(parent),
		xSpeed_(xSpeed), ySpeed_(ySpeed) {
			initComponents(parent);
	};
	PlayerMovementBehavior(Entity *parent, float speed) : GameComponent(parent),
		xSpeed_(speed), ySpeed_(speed) {
		initComponents(parent);
	};

	// TODO: Changing these values while a key is held could cause player to never stop
	void setSpeed(float speed) {
		xSpeed_ = ySpeed_ = speed;
	};
	void setSpeed(float xSpeed, float ySpeed) {
		xSpeed_ = xSpeed;
		ySpeed_ = ySpeed;
	};

    virtual void processEvent(const std::type_info &type, Event *ev);
};

#endif