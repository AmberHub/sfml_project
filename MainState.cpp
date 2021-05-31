#include "MainState.h"

void MainState::initVariable()
{
	this->background.setSize(sf::Vector2f((float)this->window->getSize().x, (float)this->window->getSize().y));
}

void MainState::initBackground()
{
	if (!this->backgroundTexture.loadFromFile("assets/img/Background/bg1.png")) {
		throw "MAINMENUSTATE::BACKGROUND FOR MAIN MENU NOT FOUND";
	}
	this->background.setTexture(&this->backgroundTexture);
}

//Initializations
void MainState::initKeysbinds()
{
	std::ifstream fs("conf/mainMenuKeybinds.ini");
	if (fs.is_open()) {
		std::string key = "";
		std::string value = "";
		while (fs >> key >> value)
			this->keybinds[key] = this->supportedKeys->at(value);
	}
	fs.close();
}

void MainState::initButtons()
{
	this->buttons["NEW_GAME_BTN"] = new Button(this->window->getSize().x / 2.f - 75, 150, 150, 35, &this->font, "New game",
		sf::Color(105, 105, 105), sf::Color(50, 150, 200), sf::Color(50, 50, 200));

	this->buttons["QUIT_BTN"] = new Button(this->window->getSize().x / 2.f - 75, 300, 150, 35, &this->font, "Quit",
		sf::Color(150, 150, 200), sf::Color(50, 150, 200), sf::Color(50, 50, 200));

}

void MainState::initFonts()
{
	if (!this->font.loadFromFile("fonts/mainMenuFont.ttf"))
		throw("MAINSTATE::FONT_NOT_FOUND");
}

//Constructor/Destructor
MainState::MainState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initVariable();
	this->initBackground();
	this->initKeysbinds();
	this->initFonts();
	this->initButtons();
}

MainState::~MainState()
{
	for (auto& iter : this->buttons) {
		delete iter.second;
	}
}

//Functions
void MainState::updateMousePos()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));

	//debug positions
	/*system("cls");
	std::cout << this->mousePosScreen.x << " " << this->mousePosScreen.y << "\n";
	std::cout << this->mousePosWindow.x << " " << this->mousePosWindow.y << "\n";
	std::cout << this->mousePosView.x << " " << this->mousePosView.y << "\n";*/

}

void MainState::updateInput(const float& timeData)
{
	
}

void MainState::updateButtons()
{
	//update button state and descripting functionality of each button
	for (auto& iter : this->buttons) {
		iter.second->update(this->mousePosView);
	}

	//New game
	if (this->buttons["NEW_GAME_BTN"]->isPressed()) {
		this->states->push(new GameState(this->window, this->supportedKeys, this->states));
	}

	//Quit game
	if (this->buttons["QUIT_BTN"]->isPressed()) {
		this->quit = true;
	}
}

void MainState::update(const float& timeData)
{
	this->updateInput(timeData);
	this->updateMousePos();

	this->updateButtons();
}

void MainState::renderButtons(sf::RenderTarget* target)
{
	for (auto& iter : this->buttons) {
		iter.second->render(target);
	}
}

void MainState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);

	this->renderButtons(target);
}