#ifndef STATE_H
#define STATE_H

#include "Player.h"

class State {

protected :
	//Variables
	sf::RenderWindow* window;
	std::stack<State*>* states;
	std::map< std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	bool quit;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	sf::Font font;

	//Resourses
	std::map<std::string, sf::Texture> textures;

	//Functions 
	virtual void initKeysbinds() = 0;

public :
	//Constructor/Destructor
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~State();

	//Regular functions
	const bool& getQuit() const;
	

	//Pure virtual functions of states
	virtual void updateMousePos();
	virtual void updateInput(const float& timeData) = 0;
	virtual void update(const float& timeData) = 0;
	virtual void render(sf::RenderTarget* target = NULL) = 0;
	virtual void endState();
};

#endif //!STATE_H