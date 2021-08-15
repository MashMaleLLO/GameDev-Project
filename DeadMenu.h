#pragma once
#include "SFML/Graphics.hpp"


#define DEAD_MAX_NUMBER_OF_ITEMS 2

class DeadMenu
{
public:
	DeadMenu(float width, float height);

	~DeadMenu();



	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int DeadGetPressedItem() { return deadselectedItemIndex; }

private:
	int deadselectedItemIndex;
	sf::Font font;
	sf::Text deadmenu[DEAD_MAX_NUMBER_OF_ITEMS];

	sf::Texture menuText;

	sf::Sprite bgmenuText;

};



