#pragma once
#include<fstream>
class ScoreRecord {
public:
	ScoreRecord();
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
	void setMedium(float newMedium);
	void setHard(float newHard);

	float getEasy();
	float getMedium();
	float getHard();

private:

	float easyHigh, mediumHigh, hardHigh;
};