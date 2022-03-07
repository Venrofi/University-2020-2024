#include <iostream>
#include <sstream>

#include "Definitions.h"
#include "MainMenuState.h"
#include "GameState.h"
#include "NegativeEndingState.h"


namespace Game
{
	NegativeEndingState::NegativeEndingState(GameDataRef data, int gameplay, int icons, int difficulty) :_data(data)
	{
		type_gameplay = gameplay;
		type_icons = icons;
		type_diff = difficulty;
	}

	void NegativeEndingState::Init()
	{
		this->_data->assets.LoadTexture("Negative Ending", NEGATIVE_FINAL);
		this->_data->assets.LoadTexture("Menu Button", MENU_SIDE_BUTTON);
		this->_data->assets.LoadTexture("Try Again Button", TRY_AGAIN_BUTTON);


		this->_background.setTexture(this->_data->assets.GetTexture("Negative Ending"));
		this->_menuButton.setTexture(this->_data->assets.GetTexture("Menu Button"));
		this->_tryAgainButton.setTexture(this->_data->assets.GetTexture("Try Again Button"));

		this->_menuButton.setPosition(0, 0);
		this->_tryAgainButton.setPosition((SCREEN_WIDTH / 2) - (this->_tryAgainButton.getGlobalBounds().width / 2),
			675);
	}

	void NegativeEndingState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			if (this->_data->input.isSpriteClicked(this->_menuButton, sf::Mouse::Left, this->_data->window))
			{
				std::cout << "Go to the Main Screen!" << std::endl;
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true); 
			}
			if (this->_data->input.isSpriteClicked(this->_tryAgainButton, sf::Mouse::Left, this->_data->window))
			{
				std::cout << "Play Again" << std::endl;
				//
				this->_data->machine.AddState(StateRef(new GameState(_data, type_gameplay, type_icons, type_diff)), true);
			}
		}
	}

	void NegativeEndingState::Draw(float dt)
	{
		this->_data->window.clear();

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_menuButton);
		this->_data->window.draw(this->_tryAgainButton);
		this->_data->window.display();
	}
	void NegativeEndingState::Update(float dt) { }
}