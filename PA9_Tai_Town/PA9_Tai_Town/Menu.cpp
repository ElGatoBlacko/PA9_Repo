/*
	Programmers: Arie Tai and Emery Town
	Class: CptS 122, Spring 2025; Lab Section 7 and Lab Section 10
	Programming Assignment: PA 9
	Date: April 22, 2025
	Description: This is the Menu class cpp file
*/
#include "Menu.hpp"
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
Menu::Menu(sf::Font& font) : title(font, "Whack-A-Mole", 100), easy(font, "Easy Mode", 50), medium(font, "Intermediate Mode", 50), hard(font, "Hard Mode", 50), records(font, "High Scores", 50), description(font, "Description", 50)
{
	title.setFillColor(sf::Color::White);
	easy.setFillColor(sf::Color::White);
	medium.setFillColor(sf::Color::White);
	hard.setFillColor(sf::Color::White);
	records.setFillColor(sf::Color::White);
	description.setFillColor(sf::Color::White);

	title.setPosition(sf::Vector2f(100, 20));
	easy.setPosition(sf::Vector2f(300, 235));
	medium.setPosition(sf::Vector2f(200, 320));
	hard.setPosition(sf::Vector2f(300, 405));
	records.setPosition(sf::Vector2f(290, 490));
	description.setPosition(sf::Vector2f(290, 150));
}
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
Menu::Menu(const Menu& copy) : title(copy.title), easy(copy.easy), medium(copy.medium), hard(copy.hard), records(copy.records), description(copy.description)
{
}

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
Menu::~Menu()
{
	//destructor unnecessary, no manual reasource management needed
}
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
void Menu::draw(sf::RenderWindow& window)
{
	window.draw(title);
	window.draw(easy);
	window.draw(medium);
	window.draw(hard);
	window.draw(records);
	window.draw(description);
}
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
sf::FloatRect Menu::getTitleBounds()
{
	return title.getGlobalBounds();
}
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
sf::FloatRect Menu::getEasyBounds()
{
	return easy.getGlobalBounds();
}
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
sf::FloatRect Menu::getMediumBounds()
{
	return medium.getGlobalBounds();
}
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
sf::FloatRect Menu::getHardBounds()
{
	return hard.getGlobalBounds();
}
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
sf::FloatRect Menu::getRecordsBounds()
{
	return records.getGlobalBounds();
}
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
sf::FloatRect Menu::getDescriptionBounds()
{
	return description.getGlobalBounds();
}


