#include "Button.h"

Button::Button(float x, float y, float width, float height,
	sf::Font* font, std::string text, sf::Color mainColor,
	sf::Color hoverColor, sf::Color pressedColor)
{
	this->btnState = BTN_MAIN;
	this->rect.setPosition(sf::Vector2f(x, y));
	this->rect.setSize(sf::Vector2f(width, height));
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(14);
	this->text.setPosition(sf::Vector2f(
		this->rect.getPosition().x + (this->rect.getSize().x / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->rect.getPosition().y + (this->rect.getSize().y / 2.f) - this->text.getGlobalBounds().height / 2.f
	));

	this->mainColor = mainColor;
	this->hoverColor = hoverColor;
	this->pressedColor = pressedColor;

	this->rect.setFillColor(this->mainColor);
}

Button::~Button()
{

}

const bool Button::isPressed() const
{
	if (this->btnState == BTN_PRESSED)
		return true;

	return false;
}

const bool Button::isHovered() const
{
	if (this->btnState == BTN_HOVER)
		return true;

	return false;
}

void Button::update(sf::Vector2f mouseCoords)
{
	//Check mouse position and change boolean variable for hover button or press

	//Normal
	this->btnState = BTN_MAIN;

	//Hover
	if (this->rect.getGlobalBounds().contains(mouseCoords)) {
		this->btnState = BTN_HOVER;
		//Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			this->btnState = BTN_PRESSED;
		}
	}

	switch (this->btnState)
	{
	case BTN_MAIN :
		this->rect.setFillColor(this->mainColor);
		break;

	case BTN_HOVER:
		this->rect.setFillColor(this->hoverColor);
		break;

	case BTN_PRESSED:
		this->rect.setFillColor(this->pressedColor);
		break;

	default:
		this->rect.setFillColor(sf::Color::Red);
		break;
	}
}

void Button::render(sf::RenderTarget* target)
{
	target->draw(this->rect);
	target->draw(this->text);
}
