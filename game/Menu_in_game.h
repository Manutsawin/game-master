#include <sfml/Graphics.hpp>
#include <stdio.h>
#define MAX_NUMBER_OF_ITEMS 3

class Menu_in_game
{
public:
	Menu_in_game(float width, float height);
	~Menu_in_game();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
};

