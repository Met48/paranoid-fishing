#ifndef VECTOR2_ATTRIBUTE_H
#define VECTOR2_ATTRIBUTE_H

#include "GameComponent.h"

class Entity;

class Vector2Attribute : public GameComponent {
protected:
    float x_;
    float y_;
public:
    Vector2Attribute(Entity *parent) : GameComponent(parent) { };
    Vector2Attribute(Entity *parent, float x, float y) : GameComponent(parent), x_(x), y_(y) { };

    
    void setValue(float x, float y) {
        x_ = x;
        y_ = y;
    };

	void setX(float x) {
		x_ = x;
	};
	void setY(float y) {
		y_ = y;
	};

    float getX() {
        return x_;
    };
    float getY() {
        return y_;
    };
};

#endif