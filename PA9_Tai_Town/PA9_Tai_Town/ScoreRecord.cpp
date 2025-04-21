#include "ScoreRecord.hpp"

ScoreRecord::ScoreRecord()
{
	easyHigh = 0.0;
	mediumHigh = 0.0;
	hardHigh = 0.0;
}

void ScoreRecord::import(std::ifstream & in)
{
	in >> easyHigh >> mediumHigh >> hardHigh;
}

void ScoreRecord::setEasy(float newEasy)
{
	easyHigh = newEasy;
}

void ScoreRecord::setMedium(float newMedium)
{
	mediumHigh = newMedium;
}

void ScoreRecord::setHard(float newHard)
{
	hardHigh = newHard;
}

float ScoreRecord::getEasy()
{
	return easyHigh;
}

float ScoreRecord::getMedium()
{
	return mediumHigh;
}

float ScoreRecord::getHard()
{
	return hardHigh;
}


void ScoreRecord::exportScores(std::ofstream& out)
{
	out << easyHigh << '\n'<< mediumHigh << '\n' << hardHigh;
}
