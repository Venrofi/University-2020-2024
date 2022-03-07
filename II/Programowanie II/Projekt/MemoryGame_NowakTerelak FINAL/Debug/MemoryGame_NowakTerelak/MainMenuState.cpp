#include <iostream>
#include <sstream>

#include "Definitions.h"
#include "MainMenuState.h"
#include "GameState.h"
#include "RankingState.h"


namespace Game
{
	MainMenuState::MainMenuState(GameDataRef data):_data(data)
	{

	}

	int type_gameplay = 1;
	int type_icons = 1;
	int type_diff = 1;

	void MainMenuState::Init()
	{
		this->_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Play Button", MAIN_MENU_PLAY_BUTTON);
		this->_data->assets.LoadTexture("Exit Button", EXIT_BUTTON);
		this->_data->assets.LoadTexture("Ranking Button", RANKING_BUTTON);

		this->_data->assets.LoadTexture("Gameplay Type 1", MAIN_MENU_GAMEPLAY_1);
		this->_data->assets.LoadTexture("Gameplay Type 2", MAIN_MENU_GAMEPLAY_2);

		this->_data->assets.LoadTexture("Type of Icons 1", MAIN_MENU_ICONS_1);
		this->_data->assets.LoadTexture("Type of Icons 2", MAIN_MENU_ICONS_2);

		this->_data->assets.LoadTexture("Difficulty 1", MAIN_MENU_DIFFICULTY_1);
		this->_data->assets.LoadTexture("Difficulty 2", MAIN_MENU_DIFFICULTY_2);
		this->_data->assets.LoadTexture("Difficulty 3", MAIN_MENU_DIFFICULTY_3);

		this->_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
		this->_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
		this->_exitButton.setTexture(this->_data->assets.GetTexture("Exit Button"));
		this->_rankingButton.setTexture(this->_data->assets.GetTexture("Ranking Button"));

		this->_gameplayType.setTexture(this->_data->assets.GetTexture("Gameplay Type 1"));

		this->_typeOfIcons.setTexture(this->_data->assets.GetTexture("Type of Icons 1"));
		this->_difficulty.setTexture(this->_data->assets.GetTexture("Difficulty 2"));

		this->_playButton.setPosition((SCREEN_WIDTH / 2) - (this->_playButton.getGlobalBounds().width / 2),
			SCREEN_HEIGHT - this->_playButton.getGlobalBounds().height);
		this->_rankingButton.setPosition(0,0);
		this->_exitButton.setPosition(SCREEN_WIDTH - this->_exitButton.getGlobalBounds().width, 0);

		this->_gameplayType.setPosition(30, 420);
		this->_typeOfIcons.setPosition(SCREEN_WIDTH - (this->_typeOfIcons.getGlobalBounds().width + 30), 420);
		this->_difficulty.setPosition((SCREEN_WIDTH / 2) - (this->_difficulty.getGlobalBounds().width / 2), 590);

		type_gameplay = 1;
		type_icons = 1;
		type_diff = 1;
	}

	void MainMenuState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type || this->_data->input.isSpriteClicked(this->_exitButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->window.close();
			}
			if (this->_data->input.isSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
			{
				std::cout << "Go to the Game Screen!" << std::endl;
				this->_data->machine.AddState(StateRef(new GameState(_data, type_gameplay, type_icons, type_diff)), true); 
			}
			if (this->_data->input.isSpriteClicked(this->_rankingButton, sf::Mouse::Left, this->_data->window))
			{
				std::cout << "Go to the Ranking Screen!" << std::endl;
				this->_data->machine.AddState(StateRef(new RankingState(_data)), true); 
			}
			if (this->_data->input.isSpriteClicked(this->_gameplayType, sf::Mouse::Left, this->_data->window))
			{
				if (type_gameplay == 1)
				{
					this->_gameplayType.setTexture(this->_data->assets.GetTexture("Gameplay Type 2"));
					type_gameplay = 0;
				}
				else
				{
					this->_gameplayType.setTexture(this->_data->assets.GetTexture("Gameplay Type 1"));
					type_gameplay = 1;
				}
			}
			if (this->_data->input.isSpriteClicked(this->_typeOfIcons, sf::Mouse::Left, this->_data->window))
			{
				if (type_icons == 1)
				{
					this->_typeOfIcons.setTexture(this->_data->assets.GetTexture("Type of Icons 2"));
					type_icons = 0;
				}
				else
				{
					this->_typeOfIcons.setTexture(this->_data->assets.GetTexture("Type of Icons 1"));
					type_icons = 1;
				}
			}
			if (this->_data->input.isSpriteClicked(this->_difficulty, sf::Mouse::Left, this->_data->window))
			{
				
				if (type_diff == 1)
				{
					this->_difficulty.setTexture(this->_data->assets.GetTexture("Difficulty 3"));
					type_diff = 2;
				}
				else if (type_diff == 2)
				{
					this->_difficulty.setTexture(this->_data->assets.GetTexture("Difficulty 1"));
					type_diff = 0;
				}
				else
				{
					this->_difficulty.setTexture(this->_data->assets.GetTexture("Difficulty 2"));
					type_diff = 1;
				}
			}
		}
	}

	void MainMenuState::Draw(float dt)
	{
		this->_data->window.clear();

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_playButton);
		this->_data->window.draw(this->_exitButton);
		this->_data->window.draw(this->_rankingButton);

		this->_data->window.draw(this->_gameplayType);
		this->_data->window.draw(this->_typeOfIcons);
		this->_data->window.draw(this->_difficulty);

		this->_data->window.display();
	}
	void MainMenuState::Update(float dt) { }
}