#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"

class GameState : public State
{
private :

	Player* player;

	void initPlayers();
	void initKeysbinds();
	void initTexures();

public :
	GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~GameState();

	void updateInput(const float& timeData);
	void update(const float& timeData);
	void render(sf::RenderTarget* target = NULL);
};

#endif