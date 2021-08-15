#pragma once
#include "SFML/Graphics.hpp"


#define END_MAX_NUMBER_OF_ITEMS 1

class EndGameMenu
{
public:
	EndGameMenu(float width, float height);

	~EndGameMenu();



	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int EndGetPressedItem() { return endselectedItemIndex; }

private:
	int endselectedItemIndex;
	sf::Font font;
	sf::Text endmenu[END_MAX_NUMBER_OF_ITEMS];

	sf::Texture menuText;

	sf::Sprite bgmenuText;

};

