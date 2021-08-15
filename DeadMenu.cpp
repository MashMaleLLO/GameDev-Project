#include "DeadMenu.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <sstream>


DeadMenu::DeadMenu(float width, float height)
{

	if (!font.loadFromFile("res/font/manaspc.ttf"))
	{
		// error
	}

	if (!menuText.loadFromFile("res/images/DeadMenu.jpg"))
	{
		std::cout << "Load failed" << std::endl;
	}

	bgmenuText.setTexture(menuText);

	deadmenu[0].setFont(font);
	deadmenu[0].setFillColor(sf::Color::Red);
	deadmenu[0].setString("BACK TO MENU");
	deadmenu[0].setPosition(sf::Vector2f(width / 2, height / (DEAD_MAX_NUMBER_OF_ITEMS + 1) * 1));

	deadmenu[1].setFont(font);
	deadmenu[1].setFillColor(sf::Color::White);
	deadmenu[1].setString("QUIT");
	deadmenu[1].setPosition(sf::Vector2f(width / 2, height / (DEAD_MAX_NUMBER_OF_ITEMS + 1) * 2));

	deadselectedItemIndex = 0;


}

DeadMenu::~DeadMenu()
{


}

void DeadMenu::draw(sf::RenderWindow& window)
{
	window.draw(bgmenuText);

	for (int i = 0; i < DEAD_MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(deadmenu[i]);
	}


}

void DeadMenu::MoveUp()
{
	if (deadselectedItemIndex - 1 >= 0)
	{
		deadmenu[deadselectedItemIndex].setFillColor(sf::Color::White);
		deadselectedItemIndex--;
		deadmenu[deadselectedItemIndex].setFillColor(sf::Color::Red);
	}


}

void DeadMenu::MoveDown()
{
	if (deadselectedItemIndex + 1 < DEAD_MAX_NUMBER_OF_ITEMS)
	{
		deadmenu[deadselectedItemIndex].setFillColor(sf::Color::White);
		deadselectedItemIndex++;
		deadmenu[deadselectedItemIndex].setFillColor(sf::Color::Red);
	}


}
