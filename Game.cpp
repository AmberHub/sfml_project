#include "Game.h"

//Initializers
void Game::InitWindow()
{
	std::fstream fs("conf/window.ini");

	std::string title = "None";
	this->videoModes = sf::VideoMode::getFullscreenModes();
	sf::VideoMode window_frame(800, 600);
	unsigned framerate_limit = 120;
	unsigned antialiasingLevel = 0;
	bool fullscreen = false;
	bool vert_sync_enabled = false;

	if (fs.is_open()) {
		std::getline(fs, title);
		fs >> framerate_limit;
		fs >> antialiasingLevel;
		fs >> fullscreen;
		fs >> window_frame.width >> window_frame.height;
		fs >> vert_sync_enabled;
	}

	fs.close();
	
	this->fullscreen = fullscreen;
	this->windowSettings.antialiasingLevel = antialiasingLevel;

	if(this->fullscreen)
		this->window = new sf::RenderWindow(window_frame, title, sf::Style::Fullscreen, windowSettings);
	else
		this->window = new sf::RenderWindow(window_frame, title, sf::Style::Titlebar | sf::Style::Close, windowSettings);
	
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vert_sync_enabled);
}

void Game::InitKeys()
{
	std::ifstream fs("conf/suppKeys.ini");
	if (fs.is_open()) {
		std::string key = "";
		int value = 0;
		while(fs >> key >> value)
			this->supportedKeys[key] = value;
	}
	fs.close();
}

void Game::InitState() {
	this->states.push(new MainState(this->window, &this->supportedKeys, &this->states));
}


//Constructor/Destructor
Game::Game()
{
	this->InitWindow();
	this->InitKeys();
	this->InitState();
}

Game::~Game()
{
	delete this->window;

	while (!this->states.empty()) {
		delete this->states.top();
		this->states.pop();
	}
}


//Functions
void Game::update()
{
	this->updateSFMLEvents();

	if (!this->states.empty()) {
		this->states.top()->update(this->timeData);
		if (this->states.top()->getQuit()) {
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	//Application end
	else {
		this->endApp();
		this->window->close();
	}
	
	//watch time value for one global cycle iteration
	//std::cout << this->timeData << '\n';
}

void Game::updateTimeData()
{
	this->timeData = this->timeDataClock.restart().asSeconds();
}

void Game::updateSFMLEvents()
{
	while (this->window->pollEvent(this->sfmlEvent)) {
		if (this->sfmlEvent.type == sf::Event::Closed)
			this->window->close();
	}

}

void Game::endApp()
{
	std::cout << "end of application" << '\n';
}

void Game::run()
{
	while (this->window->isOpen()) {
		this->updateTimeData();
		this->update();
		this->render();
	}
}

void Game::render()
{
	this->window->clear();

	//Render elems
	if (!this->states.empty())
		this->states.top()->render();

	this->window->display();
}