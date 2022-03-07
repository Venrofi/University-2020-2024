#include <iostream>
#include <sstream>

#include "Definitions.h"
#include "GameState.h"
#include "PauseState.h"
#include "MainMenuState.h"


namespace Game
{
	PauseState::PauseState(GameDataRef data) :_data(data)
	{

	}

	void PauseState::Init()
	{
		this->_data->assets.LoadTexture("Pause Background", PAUSE_GAME_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Resume Button", RESUME_BUTTON);
		this->_data->assets.LoadTexture("Menu Button", MENU_BUTTON);

		this->_background.setTexture(this->_data->assets.GetTexture("Pause Background"));
		this->_resumeButton.setTexture(this->_data->assets.GetTexture("Resume Button"));
		this->_menuButton.setTexture(this->_data->assets.GetTexture("Menu Button"));

		this->_resumeButton.setPosition((SCREEN_WIDTH / 2) - (this->_resumeButton.getGlobalBounds().width / 2),
			450);
		this->_menuButton.setPosition((SCREEN_WIDTH / 2) - (this->_menuButton.getGlobalBounds().width / 2),
			550);
	}

	void PauseState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			if (this->_data->input.isSpriteClicked(this->_resumeButton, sf::Mouse::Left, this->_data->window))
			{
				std::cout << "Resume Button!" << std::endl;
				this->_data->machine.RemoveState();
			}
			if (this->_data->input.isSpriteClicked(this->_menuButton, sf::Mouse::Left, this->_data->window))
			{
				std::cout << "Menu Button!" << std::endl;
				this->_data->machine.RemoveState();
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}
		}
	}

	void PauseState::Draw(float dt)
	{
		this->_data->window.clear();

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_resumeButton);
		this->_data->window.draw(this->_menuButton);

		this->_data->window.display();
	}
	void PauseState::Update(float dt) { }
}