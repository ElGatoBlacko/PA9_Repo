/*
	Programmers: Arie Tai and Emery Town
	Class: CptS 122, Spring 2025; Lab Section 7 and Lab Section 10
	Programming Assignment: PA 9
	Date: April 22, 2025
	Description: This is the Test class header file
*/
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
	* Returns: bool true if it passed false if failed
	* Preconditions: mole with easy difficulty
	* Postconditions: gives if duration is right or not 
	*/
	bool testEasy(); 
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
	bool testMedium();
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
	bool testHard();
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
	bool testShow();
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
	bool testHide();
};