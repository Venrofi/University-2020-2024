#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "GamePlay.h"

namespace Game
{
	class PauseState : public State
	{
	public:
		PauseState(GameDataRef data);
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;
		sf::Sprite _background;

		sf::Sprite _resumeButton;
		sf::Sprite _menuButton;
	};


}