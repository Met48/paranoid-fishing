#include <SFML/Graphics.hpp>

#include "Game.h"


#include "Entity.h"
#include "Vector2Attribute.h"
#include "DrawSpriteBehavior.h"
#include <memory>

// Tutorial SFML test script
int main() {
    Game game(200, 200, "Game Prototype");
    // TODO: Revise getWindow form
    game.getWindow()->setKeyRepeatEnabled(false);  // TODO: This disables repeat for KeyPressed, but does it affect TextEntered?
    game.getWindow()->setFramerateLimit(30);

    // Add example entity
    auto ent = std::make_shared<Entity>();
    ent->addAttribute("position", new Vector2Attribute(&*ent,0, 0));
    ent->addBehavior(new DrawSpriteBehavior(&*ent, "test.png"));

    game.addEntity(ent);

    // Start game loop
    game.start();
	return 0;
}
