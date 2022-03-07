#pragma once
#include <SFML/Graphics.hpp>

namespace Game
{
	class InputManager
	{
	public:
		InputManager() {}
		~InputManager() {}
		bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window);
		sf::Vector2i GetMousePosition(sf::RenderWindow& window);
	};
}