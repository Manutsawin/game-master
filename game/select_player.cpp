#include "select_player.h"

sf::Texture selectplayer(int position, sf::Texture* playertext)
{
	sf::Texture Texture;
	sf::Texture Textureicon;

	if (position == 150)
	{
		Texture.loadFromFile("Textures/1.png");
		Textureicon.loadFromFile("iconcharecter/11.png");
		*playertext = Textureicon;
		return Texture;
	}
	if (position == 300)
	{
		Texture.loadFromFile("Textures/2.png");
		Textureicon.loadFromFile("iconcharecter/22.png");
		*playertext = Textureicon;
		return Texture;
	}
	return Texture;
}