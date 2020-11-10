#include "select_player.h"

sf::Texture selectplayer(int position, sf::Texture* playertext, sf::Texture* palyerskill, sf::Texture* iskillplayer)
{
	sf::Texture Texture;
	sf::Texture Textureicon;
	sf::Texture skill;
	sf::Texture skillicon;
	if (position == 150)
	{
		Texture.loadFromFile("Textures/1.png");
		
		Textureicon.loadFromFile("iconcharecter/11.png");
		*playertext = Textureicon;
		
		skill.loadFromFile("skill/1.png");
		*palyerskill = skill;

		skillicon.loadFromFile("skill icon/1.png");
		*iskillplayer = skillicon;

		return Texture;
	}
	else if (position == 300)
	{
		Texture.loadFromFile("Textures/2.png");
		
		Textureicon.loadFromFile("iconcharecter/22.png");
		*playertext = Textureicon;
		
		skill.loadFromFile("skill/2.png");
		*palyerskill = skill;

		skillicon.loadFromFile("skill icon/1.png");
		*iskillplayer = skillicon;

		return Texture;
	}
	else if (position == 450)
	{
		Texture.loadFromFile("Textures/3.png");
		
		Textureicon.loadFromFile("iconcharecter/3.png");
		*playertext = Textureicon;
		
		skill.loadFromFile("skill/2.png");
		*palyerskill = skill;

		skillicon.loadFromFile("skill icon/1.png");
		*iskillplayer = skillicon;
		
		return Texture;
	}
	return Texture;
}