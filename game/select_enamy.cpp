#include "select_enamy.h"

sf::Texture selectenamy(int level, sf::Texture* enamytext, sf::Texture* enamyskill, sf::Texture* iskillenamy)
{
	sf::Texture Texture;
	sf::Texture Textureicon;
	sf::Texture skill;
	sf::Texture skillicon;
	if (level == 1)
	{
		
		Texture.loadFromFile("Textures/1.png");
		
		Textureicon.loadFromFile("iconcharecter/11.png");
		*enamytext = Textureicon;
		
		skill.loadFromFile("skill/1.png");
		*enamyskill = skill;

		skillicon.loadFromFile("skill icon/1.png");
		*iskillenamy = skillicon;
		
		return Texture;
	}
	else if(level==2)
	{
		Texture.loadFromFile("Textures/2.png");
		
		Textureicon.loadFromFile("iconcharecter/22.png");
		*enamytext = Textureicon;
		
		skill.loadFromFile("skill/2.png");
		*enamyskill = skill;

		skillicon.loadFromFile("skill icon/1.png");
		*iskillenamy = skillicon;
		
		return Texture;
	}
	else if(level==3)
	{
		Texture.loadFromFile("Textures/3.png");
		Textureicon.loadFromFile("iconcharecter/33.png");
		*enamytext = Textureicon;

		skillicon.loadFromFile("skill icon/1.png");
		*iskillenamy = skillicon;

		return Texture;

	}
	else
	{
		Texture.loadFromFile("Textures/3.png");
		
		Textureicon.loadFromFile("iconcharecter/33.png");
		*enamytext = Textureicon;

		skill.loadFromFile("skill/2.png");
		*enamyskill = skill;

		skillicon.loadFromFile("skill icon/1.png");
		*iskillenamy = skillicon;
		
		return Texture;
	}
}