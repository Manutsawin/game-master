#include "Menu_in_game.h"
Menu_in_game::Menu_in_game(float width, float height)
{
	if (!font.loadFromFile("impact.ttf"))
	{
		//handle error
	}

	menu[0].setFont(font);
	menu[0].setCharacterSize(67);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("RESUME");
	menu[0].setPosition(sf::Vector2f(width / 7, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setCharacterSize(47);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("MENU");
	menu[1].setPosition(sf::Vector2f(width / 7, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("EXIT");
	menu[2].setPosition(sf::Vector2f(width / 7, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}


Menu_in_game::~Menu_in_game()
{
}

void Menu_in_game::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu_in_game::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu_in_game::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}