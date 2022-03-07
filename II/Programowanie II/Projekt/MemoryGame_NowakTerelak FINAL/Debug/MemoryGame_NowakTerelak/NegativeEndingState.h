#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "GamePlay.h"

namespace Game
{
	class NegativeEndingState : public State
	{
	public:
		NegativeEndingState(GameDataRef data, int gameplay, int icons, int difficulty);
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;
		sf::Sprite _background;
		sf::Sprite _tryAgainButton;
		sf::Sprite _menuButton;

		int type_gameplay;
		int type_icons;
		int type_diff;
	};


}

