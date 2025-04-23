#include "mole.hpp"

/*
	* Function: Mole()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: constructor that initializes a Mole object at a specific position with a difficulty level
	* Input parameters: const sf::Texture& texture: the texture to apply to the mole, const sf::Vector2f& pos: the initial position of the mole,
	* int difficulty: the difficulty level (1 = easy, 2 = medium, 3 = hard)
	* Returns: none
	* Preconditions: texture and position given
	* Postconditions: a Mole is created, initialized, and positioned
	*/
Mole::Mole(const sf::Texture& texture, const sf::Vector2f& pos, int difficulty) : sf::Sprite(texture) {
	initialize(difficulty);

	this->setPosition(pos);

}
/*
	* Function: Mole()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: constructor that initializes a Mole object at a random position and difficulty level
	* Input parameters: const sf::Texture& texture: the texture to apply to the mole, int difficulty: the difficulty level (1 = easy, 2 = medium, 3 = hard)
	* Returns: none
	* Preconditions: texture given
	* Postconditions: a Mole is created, initialized, and randomly positioned
	*/
Mole::Mole(const sf::Texture& texture, int difficulty) : sf::Sprite(texture) {
	initialize(difficulty);

	float randX = static_cast<float>(rand() % 700);
	float randY = static_cast<float>(rand() % 500);

	this->setPosition(sf::Vector2f(randX, randY));

}
/*
	* Function: initialize()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: sets up the mole based on the difficulty level and visible duration ranges
	* Input parameters: int difficulty
	* Returns: none
	* Preconditions: difficulty between 1 and 3
	* Postconditions: Mole scale, visibility, hit state, and visible duration are set
	*/
void Mole::initialize(int difficulty)
{
	this->setScale(sf::Vector2f(0.08f, 0.08f));

	this->setColor(sf::Color(255, 255, 255, 0));

	isVisible = false;
	hitState = false;

	switch (difficulty) {
	case 1:
		// easy 
		visibleBase = 0.8f;
		break;
	case 2:
		// medium
		visibleBase = 0.4f;
		break;
	case 3:
		// hard
		visibleBase = 0.0f;
		break;
	default:
		visibleBase = 0.5f;
		break;
	}

	hiddenDuration = 0;
	visibleDuration = (rand() % 70) * 0.01f + visibleBase;
}
/*
	* Function: update()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: updates visibility of mole
	* Input parameters: none
	* Returns: none
	* Preconditions: clock to track time
	* Postconditions: Mole visibility is updated
	*/
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
			visibleDuration = (rand() % 70) * 0.01f + visibleBase;
			timer.restart();
		}
	}
}
/*
	* Function: hide()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: hides mole by making it transparent and setting isVisible to false
	* Input parameters: none
	* Returns: none
	* Preconditions: mole is visible
	* Postconditions: mole is not visible
	*/
void Mole::hide()
{
	isVisible = false;
	this->setColor(sf::Color(255, 255, 255, 0));

}
/*
	* Function: show()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: makes mole visible and randomly places it on the screen
	* Input parameters: none
	* Returns: none
	* Preconditions: mole is not visible
	* Postconditions: mole is visible
	*/
void Mole::show()
{
	isVisible = true;
	this->setColor(sf::Color(255, 255, 255, 255));

	float randX = static_cast<float>(rand() % 700 );
	float randY = static_cast<float>(rand() % 500 );
	this->setPosition(sf::Vector2f(randX, randY));
}
/*
	* Function: isHit()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: determines if mole was hit or not
	* Input parameters: sf::Event event, sf::RenderWindow& window
	* Returns: bool if hit returns true and false if mole was not hit
	* Preconditions: mouse must have been clicked
	* Postconditions: returns true if mole was clicked and is visible
	*/
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

/*
	* Function: setIsVisible()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: sets mole visible
	* Input parameters: const bool newVis
	* Returns: none
	* Preconditions: newVis is bool
	* Postconditions: moles visibility is updated
	*/
void Mole::setIsVisible(const bool newVis)
{
	isVisible = newVis;
}
/*
	* Function: setHitState()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: sets mole hit state (true if hit)
	* Input parameters: const bool newHitState
	* Returns: none
	* Preconditions: newHitState is bool
	* Postconditions: Mole hit state is updated
	*/
void Mole::setHitState(const bool newHitState)
{
	hitState = newHitState;
}
/*
	* Function: getIsVisible()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: gets moles visibility
	* Input parameters: none
	* Returns: bool if visible returns true and if not visible returns false
	* Preconditions: none
	* Postconditions: Mole visibility returned
	*/
bool Mole::getIsVisible()
{
	return isVisible;
}
/*
	* Function: getHitState()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: gets moles hit state
	* Input parameters: none
	* Returns: bool if hit returns true and if not hit returns false
	* Preconditions: none
	* Postconditions: Mole hit state is returned
	*/
bool Mole::getHitState()
{
	return hitState;
}

/*
* Function: getVisibleDuration()
* Date Created: 4/20/25
* Date Last Modified: 4/20/25
* Description: gets moles visible duration
* Input parameters: none
* Returns: float representing visible duration
* Preconditions: none
* Postconditions: none
*/
float Mole::getVisibleDuration()
{
	return visibleDuration;
}
