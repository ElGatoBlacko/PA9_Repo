#pragma once
#include <SFML/Graphics.hpp>

class Mole : public sf::Sprite {
public:
	Mole(const sf::Texture texture, const sf::Vector2f& pos) : sf::Sprite(texture){
		this->setPosition(pos);
		isVisible = false;
	}
private:
	bool isVisible;
	int hiddenDuration;
	int visibleDuration;
	bool hitState;
};