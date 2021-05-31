#include "MovementComponent.h"

MovementComponent::MovementComponent(float& maxVelocity)
{
	this->maxVelocity = maxVelocity;
}

MovementComponent::~MovementComponent()
{
}

sf::Vector2f& MovementComponent::getVelocity()
{
	return this->velocity;
}

void MovementComponent::update(const float& timeData)
{

}

void MovementComponent::move(const float dir_x, const float dir_y)
{
	this->velocity.x = dir_x * this->maxVelocity;
	this->velocity.y = dir_y * this->maxVelocity;
}
