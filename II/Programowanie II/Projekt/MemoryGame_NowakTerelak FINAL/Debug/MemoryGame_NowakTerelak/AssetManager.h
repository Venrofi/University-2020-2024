#pragma once

#include <map>
#include <string>
#include <SFML/Graphics.hpp>

namespace Game
{
	class AssetManager
	{
	public:
		AssetManager() {}
		~AssetManager() {}

		void LoadTexture(std::string name, std::string fileName);
		sf::Texture& GetTexture(std::string name);

		void loadFont(std::string name, std::string fileName);
		sf::Font& GetFont(std::string name);
	private:
		std::map<std::string, sf::Texture> _textures;
		std::map<std::string, sf::Font> _fonts;
	};
}