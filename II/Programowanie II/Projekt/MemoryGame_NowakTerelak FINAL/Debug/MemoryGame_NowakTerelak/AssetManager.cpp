#include "AssetManager.h"
#include <iostream>
namespace Game
{
	void AssetManager::LoadTexture(std::string name, std::string fileName)
	{
		sf::Texture tex;
		if (tex.loadFromFile(fileName))
		{
			this->_textures[name] = tex;
		}
	}
	sf::Texture& AssetManager::GetTexture(std::string name) 
	{
		return this->_textures[name];
	}
	void AssetManager::loadFont(std::string name, std::string fileName)
	{
		sf::Font font;
		if (font.loadFromFile(fileName))
		{
			this->_fonts[name] = font;
		}
	}
	sf::Font& AssetManager::GetFont(std::string name)
	{
		return this->_fonts[name];
	}
}