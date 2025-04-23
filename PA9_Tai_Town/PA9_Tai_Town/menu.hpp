#pragma once
#include<SFML/Graphics.hpp>

class Menu {
public:
	/*
	* Function: Menu()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: constructor that initializes inputted font
	* Input parameters: sf::Font& font
	* Returns: none
	* Preconditions: font must be loaded and initialized 
	* Postconditions: menu text is initialized 
	*/
	Menu(sf::Font& font);
	
	/*
	* Function: Menu()
	* Date Created: 4/22/25
	* Date Last Modified: 4/22/25
	* Description: copy constructor for menu class
	* Input parameters: const reference to original menu
	* Returns: none
	* Preconditions: none
	* Postconditions: menu is copied
	*/
	Menu(const Menu& copy);

	/*
	* Function: ~Menu()
	* Date Created: 4/22/25
	* Date Last Modified: 4/22/25
	* Description: destructor for menu class
	* Input parameters: none
	* Returns: none
	* Preconditions: none
	* Postconditions: menu is destructed
	*/
	~Menu();

	/*
	* Function: draw()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: all menu options into window 
	* Input parameters: sf::RenderWindow& window
	* Returns: none
	* Preconditions: window must be open 
	* Postconditions: all menu options displayed on the window 
	*/
	void draw(sf::RenderWindow& window);

	/*
	* Function: getTitleBounds()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: gets bounds of title  
	* Input parameters: none
	* Returns: title bounds
	* Preconditions: title must be initialized 
	* Postconditions: used for layout and mouse clicks   
	*/
	sf::FloatRect getTitleBounds();

	/*
	* Function: getEasyBounds()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: gets the easy bounds 
	* Input parameters: none 
	* Returns: easy bounds 
	* Preconditions: easy text initialized 
	* Postconditions: used for layout and for mouse clicks 
	*/
	sf::FloatRect getEasyBounds();

	/*
	* Function: getMediumBounds()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: gets the medium bounds 
	* Input parameters: none
	* Returns: medium bounds 
	* Preconditions: medium text initialized 
	* Postconditions: used for layout and for mouse clicks 
	*/
	sf::FloatRect getMediumBounds();

	/*
	* Function: getHardBounds()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: gets the hard bounds
	* Input parameters: none
	* Returns: hard bounds
	* Preconditions: hard text initialized
	* Postconditions: used for layout and for mouse clicks
	*/
	sf::FloatRect getHardBounds();

	/*
	* Function: getRecordsBounds()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: gets the record bounds 
	* Input parameters: none
	* Returns: record bounds
	* Preconditions: record text must be initialized 
	* Postconditions: used for layout and for mouse clicks
	*/
	sf::FloatRect getRecordsBounds();

	/*
	* Function: getDescriptionBounds()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: gets the description bounds
	* Input parameters: none
	* Returns: description bounds
	* Preconditions: description text must be initialized
	* Postconditions: used for layout and for mouse clicks
	*/
	sf::FloatRect getDescriptionBounds();

private:
	sf::Text title, easy, medium, hard, records, description;
};