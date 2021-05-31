#ifndef MAINSTATE_H
#define MAINSTATE_H

#include "GameState.h"
#include "Button.h"

class MainState :
    public State
{
private:

	sf::Texture backgroundTexture;
	sf::RectangleShape background;

	std::map<std::string, Button*> buttons;

	void initVariable();
	void initBackground();
	void initKeysbinds();
	void initButtons();
	void initFonts();

public:
	MainState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~MainState();

	void updateMousePos();
	void updateInput(const float& timeData);
	void updateButtons();
	void update(const float& timeData);
	void renderButtons(sf::RenderTarget* target = NULL);
	void render(sf::RenderTarget* target = NULL);
};

#endif //!MAINSTATE_H