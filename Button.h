#ifndef BUTTON_H
#define BUTTON_H

#include<iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

enum buttonState {
	BTN_MAIN = 0,
	BTN_HOVER,
	BTN_PRESSED
};

class Button
{
private :

	short unsigned btnState;

	sf::RectangleShape rect;
	sf::Font* font;
	sf::Text text;

	sf::Color mainColor;
	sf::Color hoverColor;
	sf::Color pressedColor;


public :

	Button(float x, float y, float width, float height, sf::Font* font, std::string text, sf::Color mainColor, sf::Color hoverColor, sf::Color pressedColor);
	~Button();

	//Accessors
	const bool isPressed() const;
	const bool isHovered() const;

	//Functions
	void update(sf::Vector2f mouseCoords);
	void render(sf::RenderTarget* target);
};

#endif BUTTON_H