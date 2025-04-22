// test cases for basic automation and conditional checks 
// does not need to be complex test cases or complex aspects of the game 

// initialize- pass in different difficulty (different functions for easy medium and hard) and test if the visible durations are appropriate for difficulty level 
// if visible range is correct 

//maybe 
// is show is hid by testing colors 
// get colors and test if it is equal to what it is supposed to be 
// in is show could test position ranges if y is between 0 and max then good and if not is bad 
// if is visible then passes if not then fail in show class


// video 
// show the game 
// then show quick run through of the code 
// explain choices we made 
// possible additions if we had more time 

#pragma once
#include "Mole.hpp"
#include<iostream>

class test
{
public: 
	void testEasy(); 
	void testMedium(); 
	void testHard();

	void testShow();
	void testHide(); 
};