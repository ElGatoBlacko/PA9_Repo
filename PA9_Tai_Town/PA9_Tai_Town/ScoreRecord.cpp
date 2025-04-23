/*
	Programmers: Arie Tai and Emery Town
	Class: CptS 122, Spring 2025; Lab Section 7 and Lab Section 10
	Programming Assignment: PA 9
	Date: April 22, 2025
	Description: This is the ScoreRecord class cpp file
*/
#include "ScoreRecord.hpp"

/*
* Function: ScoreRecord()
* Date Created: 4/21/25
* Date Last Modified: 4/21/25
* Description: constructor for scoreRecord object sets all fields to 0.0
* Input parameters: none
* Returns: none
* Preconditions: none
* Postconditions: object is constructed
*/
ScoreRecord::ScoreRecord()
{
	easyHigh = 0.0;
	mediumHigh = 0.0;
	hardHigh = 0.0;
}
/*
* Function: ScoreRecord()
* Date Created: 4/21/25
* Date Last Modified: 4/21/25
* Description: copy constructor for scoreRecord object
* Input parameters: const reference to other scoreRecord object
* Returns: none
* Preconditions: none
* Postconditions: object is copied
*/
ScoreRecord::ScoreRecord(const ScoreRecord& copy)
{
	easyHigh = copy.easyHigh;
	mediumHigh = copy.mediumHigh;
	hardHigh = copy.hardHigh;
}
/*
* Function: ~ScoreRecord()
* Date Created: 4/22/25
* Date Last Modified: 4/22/25
* Description: destructor for ScoreRecord class
* Input parameters: none
* Returns: none
* Preconditions: none
* Postconditions: ScoreRecord is destructed
*/
ScoreRecord::~ScoreRecord()
{
	//destructor unnecessary, no manual reasource management needed
}
/*
	* Function: import()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: loads saved scores
	* Input parameters: std::ifstream& in
	* Returns: none
	* Preconditions: input file must be open
	* Postconditions: values read from file are stored in variables
	*/
void ScoreRecord::import(std::ifstream & in)
{
	in >> easyHigh >> mediumHigh >> hardHigh;
}

/*
	* Function: setEasy()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: setter for easyHigh field (float that stores easy mode high score)
	* Input parameters: new float representing new high score
	* Returns: none
	* Preconditions: none
	* Postconditions: none
	*/
void ScoreRecord::setEasy(float newEasy)
{
	easyHigh = newEasy;
}
/*
	* Function: setMedium()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: setter for mediumHigh field (float that stores easy mode high score)
	* Input parameters: new float representing new high score
	* Returns: none
	* Preconditions: none
	* Postconditions: none
	*/
void ScoreRecord::setMedium(float newMedium)
{
	mediumHigh = newMedium;
}
/*
	* Function: setHard()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: setter for hardHigh field (float that stores easy mode high score)
	* Input parameters: new float representing new high score
	* Returns: none
	* Preconditions: none
	* Postconditions: none
	*/
void ScoreRecord::setHard(float newHard)
{
	hardHigh = newHard;
}
/*
	* Function: getEasy()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: gets the current high score for the easy difficulty level
	* Input parameters: none
	* Returns: the current value of easyHigh (float)
	* Preconditions: none
	* Postconditions: returns the stored easyHigh score
	*/
float ScoreRecord::getEasy()
{
	return easyHigh;
}
/*
	* Function: getMedium()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: gets the current high score for the medium difficulty level
	* Input parameters: none
	* Returns: the current value of mediumHigh (float)
	* Preconditions: none
	* Postconditions: returns the stored mediumHigh score
	*/
float ScoreRecord::getMedium()
{
	return mediumHigh;
}
/*
	* Function: getHard()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: gets the current high score for the hard difficulty level
	* Input parameters: none
	* Returns: the current value of hardHigh (float)
	* Preconditions: none
	* Postconditions: returns the stored hardHigh score
	*/
float ScoreRecord::getHard()
{
	return hardHigh;
}

/*
	* Function: exportScores()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: writes the high scores for each difficulty level in an output file
	* Input parameters: std::ofstream& out
	* Returns: none
	* Preconditions: output file must be open and able to be written in
	* Postconditions: values are written into the file
	*/
void ScoreRecord::exportScores(std::ofstream& out)
{
	out << easyHigh << '\n'<< mediumHigh << '\n' << hardHigh;
}
