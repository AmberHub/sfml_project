#ifndef GAME_H
#define GAME_H

#include "MainState.h";


class Game {

private :
	//Variables

	sf::RenderWindow* window;
	sf::Event sfmlEvent;

	sf::Clock timeDataClock;
	float timeData;

	std::stack<State*> states;
	std::map<std::string, int> supportedKeys;
	std::vector<sf::VideoMode> videoModes;
	sf::ContextSettings windowSettings;
	bool fullscreen;

	//Initializers
	void InitWindow();
	void InitKeys();
	void InitState();

public :

	//Constructors/Destructors
	Game();
	virtual ~Game();

	//Functions
	void endApp();

	//Updates
	void update();
	void updateTimeData();
	void updateSFMLEvents();

	//Visualisation
	void render();

	//Run core
	void run();
};

#endif // !GAME_H