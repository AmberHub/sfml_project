#ifndef MOVEMENT_COMPONENT_H
#define MOVEMENT_COMPONENT_H

#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<stack>
#include<map>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

class MovementComponent
{
private :
	//Variables
	float maxVelocity;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::Vector2f deceleration;

public:

	//Constructor / Destructor
	MovementComponent(float& maxVelocity);
	virtual ~MovementComponent();

	//Accessors
	sf::Vector2f& getVelocity();

	//Functions
	void update(const float& timeData);
	void move(const float dir_x, const float dir_y);
};

#endif MOVEMENT_COMPONENT_H