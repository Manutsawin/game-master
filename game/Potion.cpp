#include "Potion.h"
int randompositionpotion()
{
    
    srand(time(NULL));
    int position = ((rand()* rand() + rand() - rand()) % 1100) + 50;
    return position;
}

int randomtypepotion()
{

    srand(time(NULL));
    int type = rand()%2;
    return type;
}

sf::Texture selectpotion(int type, int* typepotion)
{
	sf::Texture Texture;

	if (type == 0)
	{

		Texture.loadFromFile("potion/hpall.png");
		*typepotion = 0;
		return Texture;
		
	}
	else if (type == 1)
	{

		Texture.loadFromFile("potion/manaall.png");
		*typepotion = 1;
		return Texture;
	}
	else
	{

		Texture.loadFromFile("potion/hpall.png");
		return Texture;
	}
	
}
