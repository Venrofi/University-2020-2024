#include <iostream>
#include <sstream>

#include "Definitions.h"
#include "MainMenuState.h"
#include "PositiveEndingState.h"
#include "TextBox.h"


namespace Game
{
	PositiveEndingState::PositiveEndingState(GameDataRef data, int score) :_data(data)
	{
		this->_score.setString(toString(score));
	}

	Textbox nickname(16, sf::Color::Black, true);

	void PositiveEndingState::Init()
	{
		nickname.setPosition(sf::Vector2f((SCREEN_WIDTH / 2) - (this->_saveButton.getGlobalBounds().width / 2), 575));
		this->_data->assets.LoadTexture("Positive Ending", POSITIVE_FINAL);
		this->_data->assets.LoadTexture("Menu Button", MENU_SIDE_BUTTON);
		this->_data->assets.LoadTexture("Save Button", SAVE_BUTTON);

		this->_data->assets.loadFont("Roboto Bold", FONT_ROBOTO_BOLD);
		this->_score.setFont(this->_data->assets.GetFont("Roboto Bold"));
		this->_score.setCharacterSize(36);
		this->_score.setFillColor(sf::Color::Black);
		this->_score.setPosition(810, 410);

		this->_background.setTexture(this->_data->assets.GetTexture("Positive Ending"));
		this->_menuButton.setTexture(this->_data->assets.GetTexture("Menu Button"));
		this->_saveButton.setTexture(this->_data->assets.GetTexture("Save Button"));

		this->_menuButton.setPosition(0, 0);
		this->_saveButton.setPosition((SCREEN_WIDTH / 2) - (this->_saveButton.getGlobalBounds().width / 2),
			675);
	}

	void PositiveEndingState::HandleInput()
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
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}
			if (this->_data->input.isSpriteClicked(this->_saveButton, sf::Mouse::Left, this->_data->window))
			{
				std::cout << "Save to ladder!" << std::endl;
				
			}
		}
	}

	void PositiveEndingState::Draw(float dt)
	{
		this->_data->window.clear();

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_menuButton);
		this->_data->window.draw(this->_saveButton);
		this->_data->window.draw(this->_score);
		nickname.drawTo(this->_data->window);
		
		this->_data->window.display();
	}

	std::string PositiveEndingState::toString(int integer)
	{
		std::ostringstream os;
		os << integer;
		return os.str();
	}

	void PositiveEndingState::Update(float dt) { }
}