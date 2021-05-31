#ifndef ENTITY_H
#define ENTITY_H

#include "MovementComponent.h"

class Entity {
private:

	//Initializers
	void initVariables();

protected :

	sf::Sprite* sprite;
	sf::Texture* texture;
	
	MovementComponent* movementComponent;

public:

	//Constructor/Destructor
	Entity();
	virtual ~Entity();

	//Class functions
	void createSprite(sf::Texture* texture);
	void createMovementComponent(float maxVelocity);

	//Functions
	virtual void move(const float& timeData, const float dir_x, const float dir_y);
	virtual void setPosition(const float x, const float y);

	virtual void update(const float& timeData);
	virtual void render(sf::RenderTarget* target = NULL);
};

#endif //!ENTITY_H