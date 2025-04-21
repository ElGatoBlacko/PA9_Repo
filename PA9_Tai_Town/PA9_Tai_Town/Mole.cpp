#include "mole.hpp"


Mole::Mole(const sf::Texture& texture, const sf::Vector2f& pos, int difficulty) : sf::Sprite(texture) {
	initialize(difficulty);

	this->setPosition(pos);

}

Mole::Mole(const sf::Texture& texture, int difficulty) : sf::Sprite(texture) {
	initialize(difficulty);

	float randX = static_cast<float>(rand() % 700);
	float randY = static_cast<float>(rand() % 500);

	this->setPosition(sf::Vector2f(randX, randY));

}

void Mole::initialize(int difficulty)
{
	this->setScale(sf::Vector2f(0.08f, 0.08f));

	this->setColor(sf::Color(255, 255, 255, 0));

	isVisible = false;
	hitState = false;

	switch (difficulty) {
	case 1:
		visibleBase = 1.0f;
		break;
	case 2:
		visibleBase = 0.5f;
		break;
	case 3:
		visibleBase = 0.0f;
		break;
	default:
		visibleBase = 0.5f;
		break;
	}

	hiddenDuration = 0;
	visibleDuration = (rand() % 100) * 0.01f + visibleBase;
}

void Mole::update()
{
	if (!hitState) {
		float elapsedTime = timer.getElapsedTime().asSeconds();
		if (isVisible && elapsedTime > visibleDuration) {
			hide();
			hiddenDuration = (rand() % 100) * 0.01f + 2.0f;
			timer.restart();
		}
		else if (!isVisible && elapsedTime > hiddenDuration) {
			show();
			visibleDuration = (rand() % 100) * 0.01f + visibleBase;
			timer.restart();
		}
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

	float randX = static_cast<float>(rand() % 700 );
	float randY = static_cast<float>(rand() % 500 );
	this->setPosition(sf::Vector2f(randX, randY));
}

bool Mole::isHit(sf::Event event, sf::RenderWindow& window)
{
	if (!isVisible) {
		return false;
	}
	if (event.is<sf::Event::MouseButtonPressed>()) {
		sf::Vector2f pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		return this->getGlobalBounds().contains(pos);
	}
	return false;
}


void Mole::setIsVisible(const bool newVis)
{
	isVisible = newVis;
}

void Mole::setHitState(const bool newHitState)
{
	hitState = newHitState;
}

bool Mole::getIsVisible()
{
	return isVisible;
}

bool Mole::getHitState()
{
	return hitState;
}
