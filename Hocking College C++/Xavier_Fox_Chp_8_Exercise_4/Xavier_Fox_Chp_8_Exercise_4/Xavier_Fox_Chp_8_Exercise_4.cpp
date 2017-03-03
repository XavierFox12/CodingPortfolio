/* Program: Xavier_Fox_Chp_8_Exercise_4.cpp
   Programmer: Xavier Fox
   Date: 18 Nov. 2014
   Purpose: To determine what range the students grade
   falls under.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void readData(ifstream& inFile, int scores[], int size);
void printGrades(const int scores[], int size);

const int NUM_OF_LEVELS = 8;

int main()
{
	int scores[NUM_OF_LEVELS] = {0};

	ifstream inFile;

	inFile.open("E:\\C++\\Ch8_Ex4Data.txt");
	if (!inFile)
	{
		cout << "Cannot fine Ch8_Ex4Data.txt" << endl
			 << "  The Program terminates   " << endl << endl;
		return 1;
	}

	readData(inFile, scores, NUM_OF_LEVELS);

	inFile.close();

	printGrades(scores, NUM_OF_LEVELS);

	return 0;
}

//Reads the test scores and loads them into the correct array level.
void readData(ifstream& inFile, int scores[], int size)
{
	int rangeLimits[] = {24, 49, 74, 99, 124, 149, 174, 200};
	int score;

	inFile >> score;

	while (inFile)
	{
		for (int i = 0; i < size; i++)
			if (score <= rangeLimits[i])
			{
				scores[i]++;
				break;
			}
		inFile >> score;
	}
}

//Prints the results of the range of test scores
void printGrades(const int scores[], int size)
{
	string range[] = {"  0 -  24",
				      " 25 -  49",
					  " 50 -  74",
				      " 75 -  99",
				      "100 - 124",
				      "125 - 149",
				      "150 - 174",
				      "175 - 200"};

	cout << setw(19) << "" << "Range     # of students"
		 << endl << endl;

	for (int i = 0; i < size; i++)
		cout << setw(25) << range[i] << setw(14) << scores[i] << endl;
	cout << endl;

	cout << "Program by: Xavier Fox" << endl << endl;
}
