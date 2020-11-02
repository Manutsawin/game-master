#include "select_enamy.h"

sf::Texture selectenamy(int level, sf::Texture *enamytext)
{
	sf::Texture Texture;
	sf::Texture Textureicon;

	if (level == 1)
	{
		
		Texture.loadFromFile("Textures/1.png");
		Textureicon.loadFromFile("iconcharecter/11.png");
		*enamytext = Textureicon;
		return Texture;
	}
	else if(level==2)
	{
		Texture.loadFromFile("Textures/2.png");
		Textureicon.loadFromFile("iconcharecter/22.png");
		*enamytext = Textureicon;
		return Texture;
	}
	else if(level==3)
	{
		Texture.loadFromFile("Textures/3.png");
		Textureicon.loadFromFile("iconcharecter/33.png");
		*enamytext = Textureicon;
		return Texture;
	}
	else
	{
		Texture.loadFromFile("Textures/3.png");
		Textureicon.loadFromFile("iconcharecter/33.png");
		*enamytext = Textureicon;
		return Texture;
	}
}