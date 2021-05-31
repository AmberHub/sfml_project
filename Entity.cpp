#include "Entity.h"
void Entity::initVariables()
{
	this->texture = NULL;
	this->sprite = NULL;
	this->movementComponent = NULL;
}

Entity::Entity()
{
	this->initVariables();
}

Entity::~Entity()
{
	delete this->sprite;
	delete this->movementComponent;
}

void Entity::createSprite(sf::Texture* texture)
{
	this->texture = texture;
	this->sprite = new sf::Sprite(*this->texture);
}

void Entity::createMovementComponent(float maxVelocity)
{
	this->movementComponent = new MovementComponent(maxVelocity);
}

void Entity::setPosition(const float x, const float y)
{
	if(this->sprite)
		this->sprite->setPosition(sf::Vector2f(x, y));
}

void Entity::move(const float& timeData, const float dir_x, const float dir_y)
{
	if (this->sprite && this->movementComponent) {
		this->movementComponent->move(dir_x, dir_y); //Sets velocity
		this->sprite->move(this->movementComponent->getVelocity() * timeData); //Use velocity
	}
		
}

void Entity::update(const float& timeData)
{
	
}

void Entity::render(sf::RenderTarget* target)
{
	if(this->sprite)
		target->draw(*this->sprite);
}
