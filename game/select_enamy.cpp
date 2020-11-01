#include "select_enamy.h"

sf::Texture selectenamy(int level)
{
	sf::Texture Texture;
	if (level == 1)
	{
		Texture.loadFromFile("Textures/12.png");
		return Texture;
	}
	else if(level==2)
	{
		Texture.loadFromFile("Textures/11.png");
		return Texture;
	}
	else if(level==3)
	{
		Texture.loadFromFile("Textures/10.png");
		return Texture;
	}
	else
	{
		Texture.loadFromFile("Textures/10.png");
		return Texture;
	}
}