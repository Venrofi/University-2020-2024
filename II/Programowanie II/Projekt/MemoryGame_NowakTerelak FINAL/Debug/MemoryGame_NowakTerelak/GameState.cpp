#include <iostream>
#include <sstream>
#include <random>
#include <algorithm>
#include <chrono>
#include <cmath>

#include "Definitions.h"
#include "GameState.h"
#include "PauseState.h"
#include "MainMenuState.h"
#include "PositiveEndingState.h"
#include "NegativeEndingState.h"


namespace Game
{
	GameState::GameState(GameDataRef data, int gameplay, int icons, int difficulty) :_data(data)
	{
		type_gameplay = gameplay;
		type_icons = icons;
		type_diff = difficulty;
	}

	//GLOBAL VARIABLES
	int foundPairs = 0;
	int moves = 0;
	int score = 0;

	int time_left{};
	sf::Clock game_clock; //starts the clock
	sf::Time elapsed_game_time = game_clock.getElapsedTime();

	int tmp1 = -1, tmp2 = -1;
	int tmpColumn1, tmpColumn2, tmpRow1, tmpRow2;
	std::string str1, str2;
	int tmp_move1{}, tmp_move2{}, score_base = 100;
	float factor = 1.0f;

	struct Timer {
		sf::Clock mC;
		float runTime;
		bool bPaused;

		Timer() {
			bPaused = false;
			runTime = 0;
			mC.restart();
		}

		void Reset() {
			mC.restart();
			runTime = 0;
			bPaused = false;
		}

		void Start() {
			if (bPaused) {
				mC.restart();
			}
			bPaused = false;
		}

		void Pause() {
			if (!bPaused) {
				runTime += mC.getElapsedTime().asSeconds();
			}
			bPaused = true;
		}

		float GetElapsedSeconds() {
			if (!bPaused) {
				return runTime + mC.getElapsedTime().asSeconds();
			}
			return runTime;
		}
	};
	Timer test_clock;

	void GameState::Init()
	{
		moves = 0;
		time_left = 0;
		foundPairs = 0;
		elapsed_game_time = game_clock.restart();

		this->_data->assets.LoadTexture("Grid Sprite", GRID_BACKGROUND);
		this->_data->assets.LoadTexture("Grid Icon", GRID_SPRITE_FILEPATH);
		this->_data->assets.LoadTexture("Pause Button", PAUSE_BUTTON);
		
		this->_data->assets.loadFont("Roboto Bold", FONT_ROBOTO_BOLD);
		this->_movesText.setFont(this->_data->assets.GetFont("Roboto Bold"));

		this->_timeText.setFont(this->_data->assets.GetFont("Roboto Bold"));
		this->_timeText.setString("");
		this->_timeText.setCharacterSize(32);
		this->_timeText.setFillColor(sf::Color::Black);

		if(type_gameplay == 0)
		{
			this->_timeText.setPosition(280, 70);
		}
		else
		{
			this->_timeText.setPosition(430, 70);
		}

		this->_movesText.setString("");
		this->_movesText.setCharacterSize(32);
		this->_movesText.setFillColor(sf::Color::Black);
		this->_movesText.setPosition(1080, 70);
		
		if (type_gameplay == 1)
		{
			this->_data->assets.LoadTexture("Main Menu Background", GAME_BACKGROUND_FILEPATH_1);
		}
		else
		{
			this->_data->assets.LoadTexture("Main Menu Background", GAME_BACKGROUND_FILEPATH_2);
		}

		this->_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
		this->_pauseButton.setTexture(this->_data->assets.GetTexture("Pause Button"));
		this->_gridSprite.setTexture(this->_data->assets.GetTexture("Grid Sprite"));

		this->_pauseButton.setPosition(0, 0);
		this->_gridSprite.setPosition((SCREEN_WIDTH / 2) - (this->_gridSprite.getGlobalBounds().width / 2),SCREEN_HEIGHT - this->_gridSprite.getGlobalBounds().height - 50);

		InitGridPieces();
		if (type_icons == 0)
		{
			this->_data->assets.LoadTexture("Argentina", ARGENTINA);
			this->_data->assets.LoadTexture("Belgium", BELGIUM);
			this->_data->assets.LoadTexture("Brazil", BRAZIL);
			this->_data->assets.LoadTexture("Canada", CANADA);
			this->_data->assets.LoadTexture("Czech", CZECH);
			this->_data->assets.LoadTexture("France", FRANCE);
			this->_data->assets.LoadTexture("Germany", GERMANY);
			this->_data->assets.LoadTexture("Greece", GREECE);
			this->_data->assets.LoadTexture("Italy", ITALY);
			this->_data->assets.LoadTexture("Japan", JAPAN);
			this->_data->assets.LoadTexture("Poland", POLAND);
			this->_data->assets.LoadTexture("Portugal", PORTUGAL);
			this->_data->assets.LoadTexture("Russia", RUSSIA);
			this->_data->assets.LoadTexture("Spain", SPAIN);
			this->_data->assets.LoadTexture("UK", UK);
			this->_data->assets.LoadTexture("USA", USA);
			randomGameCountries = InitRandomFlags();
		}
		else
		{
			this->_data->assets.LoadTexture("Bat", BAT);
			this->_data->assets.LoadTexture("Whale", WHALE);
			this->_data->assets.LoadTexture("Ostrich", OSTRICH);
			this->_data->assets.LoadTexture("Elk", ELK);
			this->_data->assets.LoadTexture("Kangaroo", KANGAROO);
			this->_data->assets.LoadTexture("Elephant", ELEPHANT);
			this->_data->assets.LoadTexture("Turtle", TURTLE);
			this->_data->assets.LoadTexture("Mouse", MOUSE);
			this->_data->assets.LoadTexture("Swan", SWAN);
			this->_data->assets.LoadTexture("Camel", CAMEL);
			this->_data->assets.LoadTexture("Cat", CAT);
			this->_data->assets.LoadTexture("Parrot", PARROT);
			this->_data->assets.LoadTexture("Giraffe", GIRAFFE);
			this->_data->assets.LoadTexture("Chicken", CHICKEN);
			this->_data->assets.LoadTexture("Sheep", SHEEP);
			this->_data->assets.LoadTexture("Dog", DOG);
			randomGameCountries = InitRandomAnimals();
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				gridArray[i][j] = -1;
			}
		}

	}
	

	void GameState::HandleInput()
	{
		sf::Event event;
		

		while (this->_data->window.pollEvent(event))
		{
			sf::Vector2i cursorPos = _data->input.GetMousePosition(this->_data->window);

			if(type_gameplay == 1)
			{
				this->_timeText.setString(toString(time_left - elapsed_game_time.asSeconds()));
				this->_movesText.setString(toString(moves));
			}
			else
			{
				this->_timeText.setString(toString(elapsed_game_time.asSeconds()));

				if (type_diff == 0) //EASY
				{
					this->_movesText.setString(toString(MOVES_EASY - moves));
				}
				if (type_diff == 1) //MEDIUM
				{
					this->_movesText.setString(toString(MOVES_MEDIUM - moves));
				}
				if (type_diff == 2) //HARD
				{
					this->_movesText.setString(toString(MOVES_HARD - moves));
				}
			}

			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (cursorPos.x >= 0 && cursorPos.x <= SCREEN_WIDTH && cursorPos.y >= 0 && cursorPos.y <= SCREEN_HEIGHT)
			{
				elapsed_game_time = game_clock.getElapsedTime();
			}

			if (this->_data->input.isSpriteClicked(this->_pauseButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(StateRef(new PauseState(_data)), false);
			}

			if (this->_data->input.isSpriteClicked(this->_gridSprite, sf::Mouse::Left, this->_data->window))
			{
				this->CheckAndPlacePiece();
			}

			if (foundPairs == 8)
			{
				this->_data->machine.AddState(StateRef(new PositiveEndingState(_data, score)), true);
				foundPairs = 0;
				score = 0;
				moves = 0;
				time_left = 0;
				elapsed_game_time = game_clock.restart();
			}
			if (type_diff == 0) //EASY
			{
				if (moves == MOVES_EASY && type_gameplay == 0)
				{
					moves = 0;
					this->_data->machine.AddState(StateRef(new NegativeEndingState(_data, type_gameplay, type_icons, type_diff)), true);
				}
				if (type_gameplay == 1)
				{
					time_left = 120;
					if (elapsed_game_time.asSeconds() >= time_left)
					{
						this->_data->machine.AddState(StateRef(new NegativeEndingState(_data, type_gameplay, type_icons, type_diff)), true);
					}
				}
			}
			else if (type_diff == 1) //MEDIUM
			{
				if (moves == MOVES_MEDIUM && type_gameplay == 0)
				{
					moves = 0;
					this->_data->machine.AddState(StateRef(new NegativeEndingState(_data, type_gameplay, type_icons, type_diff)), true);
				}
				if(type_gameplay == 1)
				{
					time_left = 60;
					if (elapsed_game_time.asSeconds() >= time_left)
					{
						this->_data->machine.AddState(StateRef(new NegativeEndingState(_data, type_gameplay, type_icons, type_diff)), true);
					}
				}
			}
			else //HARD
			{
				if (moves == MOVES_HARD && type_gameplay == 0)
				{
					moves = 0;
					this->_data->machine.AddState(StateRef(new NegativeEndingState(_data, type_gameplay, type_icons, type_diff)), true);
				}
				if (type_gameplay == 1)
				{
					time_left = 30;
					if (elapsed_game_time.asSeconds() >= time_left)
					{
						this->_data->machine.AddState(StateRef(new NegativeEndingState(_data, type_gameplay, type_icons, type_diff)), true);
					}
				}
			}	
		}
	}
	void GameState::Draw(float dt)
	{
		this->_data->window.clear();

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_pauseButton);
		this->_data->window.draw(this->_gridSprite);
		this->_data->window.draw(this->_movesText);
		this->_data->window.draw(this->_timeText);

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				this->_data->window.draw(this->_gridPieces[i][j]);
			}
		}

		this->_data->window.display();
	}


	void GameState::InitGridPieces()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				_gridPieces[i][j].setTexture(this->_data->assets.GetTexture("Grid Icon"));
				_gridPieces[i][j].setPosition((SCREEN_WIDTH / 2) - (this->_gridSprite.getGlobalBounds().width / 2) + 166.749 * j, SCREEN_HEIGHT - this->_gridSprite.getGlobalBounds().height - 50 + 150.2 * i );
			}
		}
	}

	std::vector<std::string> GameState::InitRandomFlags()
	{
		std::random_device device;
		std::mt19937 generator(device());
		std::uniform_int_distribution <int>distribution(0, 15);	//distribution(generator)

		std::vector<std::string> allFlags
		{
			"Argentina",
			"Belgium",
			"Brazil",
			"Canada",
			"Czech",
			"France",
			"Germany",
			"Greece",
			"Italy",
			"Japan",
			"Poland",
			"Portugal",
			"Russia",
			"Spain",
			"UK",
			"USA"
		};

		std::vector<std::string> gameFlags(8);

		for (int i = 0; i < gameFlags.size(); i++)
		{
			int rand = distribution(generator);
			if (allFlags[rand] == "0")
			{
				do
				{
					rand = distribution(generator);
				} while (allFlags[rand] == "0");
			}
			gameFlags[i] = allFlags[rand];
			allFlags[rand] = "0";
		}
		std::vector<std::string> gameFlagsEdit(16);
		int j = 0;
		for (int i = 0; i < 16; i++)
		{	
			if (i % 2 == 0 && i != 0)
			{
				j++;
			}
			gameFlagsEdit[i] = gameFlags[j];
		}

		// Shuffling array
		unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::shuffle(gameFlagsEdit.begin(), gameFlagsEdit.end(),
			std::default_random_engine(seed));

		return  gameFlagsEdit;
	}
	std::vector<std::string> GameState::InitRandomAnimals()
	{
		std::random_device device;
		std::mt19937 generator(device());
		std::uniform_int_distribution <int>distribution(0, 15);	//distribution(generator)

		std::vector<std::string> allAnimals
		{
			"Bat",
			"Whale",
			"Ostrich",
			"Elk",
			"Kangaroo",
			"Elephant",
			"Turtle",
			"Mouse",
			"Swan",
			"Camel",
			"Cat",
			"Parrot",
			"Giraffe",
			"Chicken",
			"Sheep",
			"Dog"
		};
		std::vector<std::string> gameAnimals(8);

		for (int i = 0; i < gameAnimals.size(); i++)
		{
			int rand = distribution(generator);
			if (allAnimals[rand] == "0")
			{
				do
				{
					rand = distribution(generator);
				} while (allAnimals[rand] == "0");
			}
			gameAnimals[i] = allAnimals[rand];
			allAnimals[rand] = "0";
		}
		std::vector<std::string> gameAnimalsEdit(16);
		int j = 0;
		for (int i = 0; i < 16; i++)
		{
			if (i % 2 == 0 && i != 0)
			{
				j++;
			}
			gameAnimalsEdit[i] = gameAnimals[j];
		}

		// Shuffling array
		unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::shuffle(gameAnimalsEdit.begin(), gameAnimalsEdit.end(),
			std::default_random_engine(seed));

		return  gameAnimalsEdit;
	}
	
	void GameState::CheckAndPlacePiece()
	{
		sf::Vector2i touchPoint = _data->input.GetMousePosition(this->_data->window);
		
		int column = -1, row = -1;
		int x;
		
		// 1. ROW
		if (touchPoint.x >= 321 && touchPoint.x <= 443 && (touchPoint.y >= 160 && touchPoint.y <= 282))
		{
			column = 1;
			row = 1;
			x = 0;
		}
		if (touchPoint.x >= 486 && touchPoint.x <= 608 && (touchPoint.y >= 160 && touchPoint.y <= 282))
		{
			column = 1;
			row = 2;
			x = 1;
		}
		if (touchPoint.x >= 651 && touchPoint.x <= 773 && (touchPoint.y >= 160 && touchPoint.y <= 282))
		{
			column = 1;
			row = 3;
			x = 2;
		}
		if (touchPoint.x >= 816 && touchPoint.x <= 938 && (touchPoint.y >= 160 && touchPoint.y <= 282))
		{
			column = 1;
			row = 4;
			x = 3;
		}

		// 2. ROW
		if (touchPoint.x >= 321 && touchPoint.x <= 443 && (touchPoint.y >= 325 && touchPoint.y <= 447))
		{
			column = 2;
			row = 1;
			x = 4;
		}
		if (touchPoint.x >= 486 && touchPoint.x <= 608 && (touchPoint.y >= 325 && touchPoint.y <= 447))
		{
			column = 2;
			row = 2;
			x = 5;
		}
		if (touchPoint.x >= 651 && touchPoint.x <= 773 && (touchPoint.y >= 325 && touchPoint.y <= 447))
		{
			column = 2;
			row = 3;
			x = 6;
		}
		if (touchPoint.x >= 816 && touchPoint.x <= 938 && (touchPoint.y >= 325 && touchPoint.y <= 447))
		{
			column = 2;
			row = 4;
			x = 7;
		}

		// 3. ROW
		if (touchPoint.x >= 321 && touchPoint.x <= 443 && (touchPoint.y >= 490 && touchPoint.y <= 612))
		{
			column = 3;
			row = 1;
			x = 8;
		}
		if (touchPoint.x >= 486 && touchPoint.x <= 608 && (touchPoint.y >= 490 && touchPoint.y <= 612))
		{
			column = 3;
			row = 2;
			x = 9;
		}
		if (touchPoint.x >= 651 && touchPoint.x <= 773 && (touchPoint.y >= 490 && touchPoint.y <= 612))
		{
			column = 3;
			row = 3;
			x = 10;
		}
		if (touchPoint.x >= 816 && touchPoint.x <= 938 && (touchPoint.y >= 490 && touchPoint.y <= 612))
		{
			column = 3;
			row = 4;
			x = 11;
		}

		// 4. ROW
		if (touchPoint.x >= 321 && touchPoint.x <= 443 && (touchPoint.y >= 655 && touchPoint.y <= 777))
		{
			column = 4;
			row = 1;
			x = 12;
		}
		if (touchPoint.x >= 486 && touchPoint.x <= 608 && (touchPoint.y >= 655 && touchPoint.y <= 777))
		{
			column = 4;
			row = 2;
			x = 13;
		}
		if (touchPoint.x >= 651 && touchPoint.x <= 773 && (touchPoint.y >= 655 && touchPoint.y <= 777))
		{
			column = 4;
			row = 3;
			x = 14;
		}
		if (touchPoint.x >= 816 && touchPoint.x <= 938 && (touchPoint.y >= 655 && touchPoint.y <= 777))
		{
			column = 4;
			row = 4;
			x = 15;
		}

		if (column > 0 && row > 0)
		{
			if (gridArray[column - 1][row - 1] == -1)
			{
				moves++;
				gridArray[column - 1][row - 1] = 0;
				LoadCurrentFlag(column, row, x);
				
				if (tmp1 == -1)
				{
					tmp1 = 0;
					str1 = randomGameCountries[x];
					tmpColumn1 = column;
					tmpRow1 = row;
				}
				else
				{
					tmp2 = 0;
					str2 = randomGameCountries[x];
					tmpColumn2 = column;
					tmpRow2 = row;
				}

				if (tmp1 != -1 && tmp2 != -1)
				{
					if (str1 == str2)
					{
						tmp1 = -1;
						tmp2 = -1;
						str1 = "";
						str2 = "";
						score += (score_base * factor);
						foundPairs++;
						if (tmp_move1 == 0)
						{
							tmp_move1 = moves;
							factor *= 1.5;
						}
						else if (tmp_move2 == 0 && tmp_move1 != 0)
						{
							tmp_move2 = moves;
						}
						if (abs(tmp_move1 - tmp_move2) == 2 && tmp_move1 != 0 && tmp_move2 != 0)
						{
							factor *= 1.5f;
							tmp_move1 = tmp_move2;
							tmp_move2 = 0;
						}
					}
					else
					{
						tmp_move1 = 0;
						tmp_move2 = 0;
						factor = 1.0f;
						gridArray[tmpColumn1 - 1][tmpRow1 - 1] = -1;
						gridArray[tmpColumn2 - 1][tmpRow2 - 1] = -1;
						_gridPieces[tmpColumn1 - 1][tmpRow1 - 1].setTexture(this->_data->assets.GetTexture("Grid Icon"));
						_gridPieces[tmpColumn2 - 1][tmpRow2 - 1].setTexture(this->_data->assets.GetTexture("Grid Icon"));
						tmp1 = -1;
						tmp2 = -1;
						str1 = "";
						str2 = "";
					}
				}
			}
		}
	}

	void GameState::LoadCurrentFlag(int column, int row, int x)
	{
		_gridPieces[column - 1][row - 1].setTexture(this->_data->assets.GetTexture(randomGameCountries[x]));
	}

	std::string GameState::toString(int integer)
	{
		std::ostringstream os;
		os << integer;
		return os.str();
	}
	void GameState::Update(float dt) { }
}