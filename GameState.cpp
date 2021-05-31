#include "GameState.h"

void GameState::initPlayers()
{
	this->player = new Player(0, 0, &this->textures["PLAYER_IDLE"]);
}

//Initializations
void GameState::initKeysbinds()
{
	std::ifstream fs("conf/gameKeybinds.ini");
	if (fs.is_open()) {
		std::string key = "";
		std::string value = "";
		while (fs >> key >> value)
			this->keybinds[key] = this->supportedKeys->at(value);
	}
	fs.close();
}

void GameState::initTexures()
{
	if (!this->textures["PLAYER_IDLE"].loadFromFile("assets/img/Player/up_idle.png"))
		throw "ERROR::GAMESTATE::PLAYER_IDLE_TEXTURE_NOT_FOUND";
}

//Constructor/Destructor
GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initKeysbinds();
	this->initTexures();
	this->initPlayers();
}

GameState::~GameState()
{
	delete this->player;
}

//Functions
void GameState::updateInput(const float& timeData)
{
	//player moving
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player->move(timeData, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player->move(timeData, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
		this->player->move(timeData, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->player->move(timeData, 0.f, 1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
		this->endState();
}

void GameState::update(const float& timeData)
{
	this->updateInput(timeData);
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	this->player->render(target);
}
