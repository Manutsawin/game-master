#include "Menu.h"
Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("impact.ttf"))
	{
		//handle error
	}

	menu[0].setFont(font);
	menu[0].setCharacterSize(67);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("PLAY");
	menu[0].setPosition(sf::Vector2f(width / 7, height / (MAX_NUMBER_OF_ITEMS ) * 1));

	menu[1].setFont(font);
	menu[1].setCharacterSize(47);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("HIGH SCORE");
	menu[1].setPosition(sf::Vector2f(width / 7, 370));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("HOW TO PLAY");
	menu[2].setPosition(sf::Vector2f(width / 7, 470));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("EXIT");
	menu[3].setPosition(sf::Vector2f(width / 7,570));

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}