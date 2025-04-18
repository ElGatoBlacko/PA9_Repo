#pragma once
#include <SFML/Graphics.hpp>
#include<cstdlib>

class Mole : public sf::Sprite {
public:
	Mole(const sf::Texture texture, const sf::Vector2f& pos, int difficulty) : sf::Sprite(texture){
		this->setPosition(pos);
		isVisible = false;
		hitState = false;
		switch (difficulty) {
		case 1:
			visibleBase = 3.0f;
			break;
		case 2:
			visibleBase = 2.0f;
			break;
		case 3:
			visibleBase = 1.0f;
			break;
		default:
			visibleBase = 2.0f;
			break;
		}

		hiddenDuration = (rand()*100) * 0.01f + 2.0f;
		visibleDuration = (rand()*100)*0.01f + visibleBase;
	}

	void update();

	void hide();

	void show();

private:
	bool isVisible; // if isVisible is false then the click doesn't count towards the score 
	float hiddenDuration,visibleDuration,visibleBase; // amount of time mole is hidden, amount of time mole is visible and able to be hit 
	bool hitState; // if mole was hit or not 
	sf::Clock timer;
};