#include "EndGameMenu.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <sstream>


EndGameMenu::EndGameMenu(float width, float height)
{
	if (!font.loadFromFile("res/font/manaspc.ttf"))
	{
		// error
	}

	if (!menuText.loadFromFile("res/images/endgamebg.png"))
	{
		std::cout << "Load failed" << std::endl;
	}

	bgmenuText.setTexture(menuText);

	endmenu[0].setFont(font);
	endmenu[0].setFillColor(sf::Color::Red);
	endmenu[0].setString("Play again!!");
	endmenu[0].setPosition(sf::Vector2f(width / 2, height / (END_MAX_NUMBER_OF_ITEMS + 1) * 1));


	endselectedItemIndex = 0;

}

EndGameMenu::~EndGameMenu()
{

}

void EndGameMenu::draw(sf::RenderWindow& window)
{
	window.draw(bgmenuText);

	for (int i = 0; i < END_MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(endmenu[i]);
	}

}

void EndGameMenu::MoveUp()
{
	if (endselectedItemIndex - 1 >= 0)
	{
		endmenu[endselectedItemIndex].setFillColor(sf::Color::White);
		endselectedItemIndex--;
		endmenu[endselectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void EndGameMenu::MoveDown()
{
	if (endselectedItemIndex + 1 < END_MAX_NUMBER_OF_ITEMS)
	{
		endmenu[endselectedItemIndex].setFillColor(sf::Color::White);
		endselectedItemIndex++;
		endmenu[endselectedItemIndex].setFillColor(sf::Color::Red);
	}
}
