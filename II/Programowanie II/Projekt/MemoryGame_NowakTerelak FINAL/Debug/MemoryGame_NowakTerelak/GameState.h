#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "State.h"
#include "GamePlay.h"
#include <string>

namespace Game
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data, int gameplay, int icons, int difficulty);
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
		std::vector<std::string> randomGameCountries;
		std::vector<std::string> gameSeed;
		std::string toString(int integer);

	private:
		void InitGridPieces();
		void CheckAndPlacePiece();
		void LoadCurrentFlag(int column, int row, int x);

		std::vector<std::string> InitRandomFlags();
		std::vector<std::string> InitRandomAnimals();

		GameDataRef _data;

		sf::Text _timeText;
		sf::Text _movesText;
		
		sf::Sprite _background;

		sf::Sprite _pauseButton;
		
		sf::Sprite _gridSprite;

		sf::Sprite _gridPieces[4][4];

		int gridArray[4][4];
		int gameState;

		int type_gameplay;
		int type_icons;
		int type_diff;
	};


}

