#pragma once
#include "Mole.hpp"
#include<iostream>

class Test
{
public: 
	/*
	* Function: testEasy()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: tests if visible duration for easy is correct 
	* Input parameters: none
	* Returns: none
	* Preconditions: mole with easy difficulty
	* Postconditions: gives if duration is right or not 
	*/
	void testEasy(); 
	/*
	* Function: testMedium()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: tests if visible duration for medium is correct 
	* Input parameters: none
	* Returns: none
	* Preconditions: mole with medium difficulty 
	* Postconditions: gives if duration is right or not 
	*/
	void testMedium(); 
	/*
	* Function: testHard()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: tests if visible duration for hard is correct 
	* Input parameters: none
	* Returns: none
	* Preconditions: mole with hard difficulty
	* Postconditions: gives if duration is right or not 
	*/
	void testHard();
	/*
	* Function: testShow()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: tests if mole is showing when show() is called
	* Input parameters: none
	* Returns: none
	* Preconditions: mole must be constructed 
	* Postconditions: isVisible should be true 
	*/
	void testShow();
	/*
	* Function: testHide()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: tests if mole is showing when hide() is called
	* Input parameters: none
	* Returns: none
	* Preconditions: mole must be constructed 
	* Postconditions: isVisible should be false
	*/
	void testHide(); 
};