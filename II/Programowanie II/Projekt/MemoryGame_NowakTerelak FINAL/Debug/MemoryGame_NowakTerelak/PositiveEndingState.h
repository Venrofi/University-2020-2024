#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "GamePlay.h"

namespace Game
{
	class PositiveEndingState : public State
	{
	public:
		PositiveEndingState(GameDataRef data, int score);
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
		std::string toString(int integer);

	private:
		GameDataRef _data;
		sf::Sprite _background;
		sf::Sprite _saveButton;
		sf::Sprite _menuButton;
		sf::Text _score;
	};
}