/*
    Programmers: Arie Tai and Emery Town
    Class: CptS 122, Spring 2025; Lab Section 7 and Lab Section 10
    Programming Assignment: PA 9
    Date: April 22, 2025
    Description: This is the Test class cpp file
*/
#include "Test.hpp"
/*
    * Function: testEasy()
    * Date Created: 4/20/25
    * Date Last Modified: 4/20/25
    * Description: tests if visible duration for easy is correct
    * Input parameters: none
    * Returns: bool true if it passed false if failed
    * Preconditions: mole with easy difficulty
    * Postconditions: gives if duration is right or not
    */
bool Test::testEasy()
{
    sf::Texture texture; 
    Mole mole(texture, sf::Vector2f(100, 100), 1);
    mole.show();
    if (mole.getVisibleDuration() >= 0.8f && mole.getVisibleDuration() <= 1.5f)
    {
        std::cout << "Easy works visible duration is correct" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Easy does not work visible duration is incorrect" << std::endl;
        return false;
    }
}
/*
    * Function: testMedium()
    * Date Created: 4/20/25
    * Date Last Modified: 4/20/25
    * Description: tests if visible duration for medium is correct
    * Input parameters: none
    * Returns: bool true if it passed false if failed
    * Preconditions: mole with medium difficulty
    * Postconditions: gives if duration is right or not
    */
bool Test::testMedium()
{
    sf::Texture texture;
    Mole mole(texture, sf::Vector2f(100, 100), 2);
    mole.show();
    if (mole.getVisibleDuration() >= 0.4f && mole.getVisibleDuration() <= 1.1f)
    {
        std::cout << "Medium works visible duration is correct" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Medium does not work visible duration is incorrect" << std::endl;
        return false;
    }
}
/*
    * Function: testHard()
    * Date Created: 4/20/25
    * Date Last Modified: 4/20/25
    * Description: tests if visible duration for hard is correct
    * Input parameters: none
    * Returns: bool true if it passed false if failed
    * Preconditions: mole with hard difficulty
    * Postconditions: gives if duration is right or not
    */
bool Test::testHard()
{
    sf::Texture texture;
    Mole mole(texture, sf::Vector2f(100, 100), 3);
    mole.show();
    if (mole.getVisibleDuration() >= 0.0f && mole.getVisibleDuration() <= 0.7f)
    {
        std::cout << "Hard works visible duration is correct" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Hard does not work visible duration is incorrect" << std::endl;
        return false;
    }
}
/*
    * Function: testShow()
    * Date Created: 4/20/25
    * Date Last Modified: 4/20/25
    * Description: tests if mole is showing when show() is called
    * Input parameters: none
    * Returns: bool true if it passed false if failed
    * Preconditions: mole must be constructed
    * Postconditions: isVisible should be true
    */
bool Test::testShow()
{
    sf::Texture texture;
    Mole mole(texture, sf::Vector2f(100, 100), 1);
    mole.show();
    if (mole.getIsVisible())
    {
        std::cout << "Show works mole is visible" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Show does not work mole is not visible" << std::endl;
        return false;
    }
}
/*
    * Function: testHide()
    * Date Created: 4/20/25
    * Date Last Modified: 4/20/25
    * Description: tests if mole is showing when hide() is called
    * Input parameters: none
    * Returns: bool true if it passed false if failed
    * Preconditions: mole must be constructed
    * Postconditions: isVisible should be false
    */
bool Test::testHide()
{
    sf::Texture texture;
    Mole mole(texture, sf::Vector2f(100, 100), 1);
    mole.show();
    mole.hide(); 
    if (!mole.getIsVisible())
    {
        std::cout << "Hide works mole is not visible" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Hide does not work mole is visible" << std::endl;
        return false;
    }
}