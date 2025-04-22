#pragma once
#include<SFML/Graphics.hpp>

class Menu {
public:
	Menu(sf::Font& font);
	
	void draw(sf::RenderWindow& window);

	sf::FloatRect getTitleBounds();
	sf::FloatRect getEasyBounds();
	sf::FloatRect getMediumBounds();
	sf::FloatRect getHardBounds();
	sf::FloatRect getRecordsBounds();
	sf::FloatRect getDescriptionBounds();

private:
	sf::Text title, easy, medium, hard, records, description;
};