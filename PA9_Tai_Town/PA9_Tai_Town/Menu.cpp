#include "Menu.hpp"

Menu::Menu(sf::Font& font) : title(font, "Whack-A-Mole", 100), easy(font, "Easy Mode", 50), medium(font, "Intermediate Mode", 50), hard(font, "Hard Mode", 50), records(font, "High Scores", 50), description(font, "Description", 50)
{
	title.setFillColor(sf::Color::White);
	easy.setFillColor(sf::Color::White);
	medium.setFillColor(sf::Color::White);
	hard.setFillColor(sf::Color::White);
	records.setFillColor(sf::Color::White);
	description.setFillColor(sf::Color::White);

	title.setPosition(sf::Vector2f(100, 20));
	easy.setPosition(sf::Vector2f(300, 235));
	medium.setPosition(sf::Vector2f(200, 320));
	hard.setPosition(sf::Vector2f(300, 405));
	records.setPosition(sf::Vector2f(290, 490));
	description.setPosition(sf::Vector2f(290, 150));
}

void Menu::draw(sf::RenderWindow& window)
{
	window.draw(title);
	window.draw(easy);
	window.draw(medium);
	window.draw(hard);
	window.draw(records);
	window.draw(description);
}

sf::FloatRect Menu::getTitleBounds()
{
	return title.getGlobalBounds();
}

sf::FloatRect Menu::getEasyBounds()
{
	return easy.getGlobalBounds();
}

sf::FloatRect Menu::getMediumBounds()
{
	return medium.getGlobalBounds();
}

sf::FloatRect Menu::getHardBounds()
{
	return hard.getGlobalBounds();
}

sf::FloatRect Menu::getRecordsBounds()
{
	return records.getGlobalBounds();
}

sf::FloatRect Menu::getDescriptionBounds()
{
	return description.getGlobalBounds();
}


