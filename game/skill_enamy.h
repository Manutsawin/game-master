#pragma once
#include <SFML/Graphics.hpp>
#include<stdio.h>
class skilll
{
public:

	skilll(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~skilll();

	void Update(int row, float deltaTime);

public:

	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};

