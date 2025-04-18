#include "mole.hpp"

void Mole::update()
{
	float elapsedTime = timer.getElapsedTime().asSeconds();
	if (isVisible && elapsedTime > visibleDuration) {
		hide();
		hiddenDuration = (rand() * 100) * 0.01f + 2.0f;
		timer.restart();
	}
	else if (!isVisible && elapsedTime > hiddenDuration) {
		show();
		visibleDuration = (rand() * 100) * 0.01f + visibleBase;
		timer.restart();
	}
}

void Mole::hide()
{
	isVisible = false;
	this->setColor(sf::Color(255, 255, 255, 0));

}

void Mole::show()
{
	isVisible = true;
	this->setColor(sf::Color(255, 255, 255, 255));

	float randX = static_cast<float>(rand() % 700 + 50);
	float randY = static_cast<float>(rand() % 500 + 50);
	this->setPosition(sf::Vector2f(randX, randY));
}
