#pragma once
#include <SFML/Graphics.hpp>
#include<cstdlib>

class Mole : public sf::Sprite {
public:
	//if we have time add function to check for mole overlap

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
	Mole(const sf::Texture& texture, const sf::Vector2f& pos, int difficulty);

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
	Mole(const sf::Texture& texture, int difficulty);

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
	void initialize(int difficulty);

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
	void update();

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
	void hide();

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
	void show();

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
	bool isHit(sf::Event event, sf::RenderWindow& window);

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
	void setIsVisible(const bool newVis);

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
	void setHitState(const bool newHitState);
	
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
	bool getIsVisible();

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
	bool getHitState();

private:
	bool isVisible; // if isVisible is false then the click doesn't count towards the score 
	float hiddenDuration,visibleDuration,visibleBase; // amount of time mole is hidden, amount of time mole is visible and able to be hit 
	bool hitState; // if mole was hit or not 
	sf::Clock timer;
};