#include <iostream>
#include <sstream>

#include "Definitions.h"
#include "MainMenuState.h"
#include "RankingState.h"


namespace Game
{
	RankingState::RankingState(GameDataRef data) :_data(data)
	{

	}

	void RankingState::Init()
	{
		this->_data->assets.LoadTexture("Ladder Background", LADDER_BACKGROUND);
		this->_data->assets.LoadTexture("Menu Button", MENU_SIDE_BUTTON);



		this->_background.setTexture(this->_data->assets.GetTexture("Ladder Background"));
		this->_menuSideButton.setTexture(this->_data->assets.GetTexture("Menu Button"));
		
		this->_menuSideButton.setPosition(0, 0);
		
	}

	void RankingState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			if (this->_data->input.isSpriteClicked(this->_menuSideButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}
		}
	}

	void RankingState::Draw(float dt)
	{
		this->_data->window.clear();

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_menuSideButton);

		this->_data->window.display();
	}
	void RankingState::Update(float dt){ }
}