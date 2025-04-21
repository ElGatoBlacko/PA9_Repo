#include "Menu.hpp"

Menu::Menu(sf::Font& font) : title(font, "Whack-A-Mole", 100), easy(font, "Easy Mode", 50), medium(font, "Intermediate Mode", 50), hard(font, "Hard Mode", 50)
{
	title.setFillColor(sf::Color::White);
	easy.setFillColor(sf::Color::White);
	medium.setFillColor(sf::Color::White);
	hard.setFillColor(sf::Color::White);

	title.setPosition(sf::Vector2f(300, 50));
	easy.setPosition(sf::Vector2f(350, 250));
	medium.setPosition(sf::Vector2f(350, 350));
	hard.setPosition(sf::Vector2f(350, 450));
}

void Menu::draw(sf::RenderWindow& window)
{
	window.draw(title);
	window.draw(easy);
	window.draw(medium);
	window.draw(hard);
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
