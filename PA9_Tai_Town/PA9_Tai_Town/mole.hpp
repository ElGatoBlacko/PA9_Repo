#pragma once
#include <SFML/Graphics.hpp>
#include<cstdlib>

class Mole : public sf::Sprite {
public:
	//if we have time add function to check for mole overlap

	Mole(const sf::Texture& texture, const sf::Vector2f& pos, int difficulty);

	Mole(const sf::Texture& texture, int difficulty);

	void initialize(int difficulty);

	void update();

	void hide();

	void show();

	bool isHit(sf::Event event, sf::RenderWindow& window);

	void setIsVisible(const bool newVis);
	void setHitState(const bool newHitState);
	
	bool getIsVisible();
	bool getHitState();

private:
	bool isVisible; // if isVisible is false then the click doesn't count towards the score 
	float hiddenDuration,visibleDuration,visibleBase; // amount of time mole is hidden, amount of time mole is visible and able to be hit 
	bool hitState; // if mole was hit or not 
	sf::Clock timer;
};