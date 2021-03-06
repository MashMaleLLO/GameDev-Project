#pragma once
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>


#define MAX_NUMBER_OF_ITEMS 2

class Menu
{
public:
	Menu(float width, float height);

	~Menu();



	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

	sf::Texture menuText;

	sf::Sprite bgmenuText;
	

};

