#include "State.h"

//Constructor/Destructor
State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
{
	this->window = window;
	this->supportedKeys = supportedKeys;
	this->states = states;
	this->quit = false;
}

State::~State()
{

}

//Functions
const bool& State::getQuit() const
{
	return this->quit;
}

void State::updateMousePos()
{

}

void State::endState()
{
	this->quit = true;
}