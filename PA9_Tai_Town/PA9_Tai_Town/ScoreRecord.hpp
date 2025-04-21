#pragma once
#include<fstream>
class ScoreRecord {
public:
	ScoreRecord();

	void import(std::ifstream& in);
	void exportScores(std::ofstream& out);
	
	void setEasy(float newEasy);
	void setMedium(float newMedium);
	void setHard(float newHard);

	float getEasy();
	float getMedium();
	float getHard();

private:

	float easyHigh, mediumHigh, hardHigh;
};