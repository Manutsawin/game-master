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
		
		skill.loadFromFile("skill/3.png");
		*palyerskill = skill;

		skillicon.loadFromFile("skill icon/1.png");
		*iskillplayer = skillicon;
		
		return Texture;
	}
	else if (position == 600)
	{
		Texture.loadFromFile("Textures/4.png");

		Textureicon.loadFromFile("iconcharecter/3.png");
		*playertext = Textureicon;

		skill.loadFromFile("skill/4.png");
		*palyerskill = skill;

		skillicon.loadFromFile("skill icon/1.png");
		*iskillplayer = skillicon;

		return Texture;
	}
	else if (position == 750)
	{
		Texture.loadFromFile("Textures/5.png");

		Textureicon.loadFromFile("iconcharecter/3.png");
		*playertext = Textureicon;

		skill.loadFromFile("skill/5.png");
		*palyerskill = skill;

		skillicon.loadFromFile("skill icon/1.png");
		*iskillplayer = skillicon;

		return Texture;
	}
	return Texture;
}