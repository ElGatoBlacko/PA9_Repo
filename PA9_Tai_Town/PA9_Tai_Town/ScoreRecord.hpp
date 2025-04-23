#pragma once
#include<fstream>
class ScoreRecord {
public:
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
	ScoreRecord();

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
	ScoreRecord(const ScoreRecord& copy);

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
	~ScoreRecord();

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
	void import(std::ifstream& in);

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
	void exportScores(std::ofstream& out);
	
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
	void setEasy(float newEasy);

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
	void setMedium(float newMedium);

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
	void setHard(float newHard);

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
	float getEasy();

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
	float getMedium();

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
	float getHard();

private:

	float easyHigh, mediumHigh, hardHigh;
};