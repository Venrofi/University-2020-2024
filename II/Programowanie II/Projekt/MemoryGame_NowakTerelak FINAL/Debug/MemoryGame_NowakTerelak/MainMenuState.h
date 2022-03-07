#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "GamePlay.h"

namespace Game
{
	class MainMenuState : public State
	{
	public:
		MainMenuState(GameDataRef data);
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;
		sf::Sprite _background;

		sf::Sprite _playButton;
		sf::Sprite _exitButton;
		sf::Sprite _rankingButton;

		sf::Sprite _gameplayType;
		sf::Sprite _typeOfIcons;
		sf::Sprite _difficulty;
	};


}

