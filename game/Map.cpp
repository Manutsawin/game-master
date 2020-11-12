#include "Map.h"

sf::Texture randMap()
{
    sf::Texture Map;
    srand(time(NULL));
    int number = ((rand() * rand() + rand() - rand()) % 6);
    if (number == 0)
    {
        Map.loadFromFile("Map/1.png");
    }
    else if (number==1)
    {
        Map.loadFromFile("Map/2.png");
    }
    else if (number == 2)
    {
        Map.loadFromFile("Map/3.png");
    }
    else if (number == 3)
    {
        Map.loadFromFile("Map/4.png");
    }
    else if (number == 4)
    {
        Map.loadFromFile("Map/5.png");
    }
    else if (number == 5)
    {
        Map.loadFromFile("Map/6.png");
    }
    return Map;
}