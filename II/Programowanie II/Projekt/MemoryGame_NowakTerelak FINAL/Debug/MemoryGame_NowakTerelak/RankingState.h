#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "GamePlay.h"

namespace Game
{
	class RankingState : public State
	{
	public:
		RankingState(GameDataRef data);
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;
		sf::Sprite _background;

		sf::Sprite _menuSideButton;
	};


}

