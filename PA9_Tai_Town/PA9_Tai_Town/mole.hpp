#pragma once
#include <SFML/Graphics.hpp>


class Mole : public sf::Sprite {
public:
	Mole(const sf::Texture texture, const sf::Vector2f& pos) : sf::Sprite(texture){
		this->setPosition(pos);
		isVisible = false;
	}
private:
	bool isVisible; // if isVisible is false then the click doesn't count towards the score 
	int hiddenDuration; // amount of time mole is hidden
	int visibleDuration; // amount of time mole is visible and able to be hit 
	bool hitState; // if mole was hit or not 
};