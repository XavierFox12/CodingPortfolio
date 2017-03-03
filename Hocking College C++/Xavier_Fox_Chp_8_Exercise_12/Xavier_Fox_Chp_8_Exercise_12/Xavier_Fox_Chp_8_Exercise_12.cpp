/* Program: Xavier_Fox_Chp_8_Exercise_12.cpp
   Programmer: Xavier Fox
   Date: 25 Nov. 2014
   Purpose: Determines the total miles ran by the person
   and calculates the average miles they ran.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int NUMOFROWS = 5;
const int NUMOFCOLS = 9;

void getData(ifstream& inFile, string runnerNames[], double miles[][NUMOFCOLS]);
void totalMiles(const string runnerNames[], const double miles[][NUMOFCOLS],
				  double total[], double average[]);
void results(const string runnerNames[], const double miles[][NUMOFCOLS],
			 const double total[], const double average[]);

int main()
{
	string runnerNames[NUMOFROWS];
	double miles[NUMOFROWS][NUMOFCOLS], total[NUMOFROWS] = {0.0},
		   average[NUMOFROWS] = {0.0};

	ifstream inFile;

	inFile.open("E:\\C++\\Ch8_Ex12Data.txt");
	if (!inFile)
	{
		cout << "Cannot find Ch8_Ex12Data.txt" << endl
			 << "   The Program terminates   " << endl << endl;
		return 1;
	}

	cout << showpoint << fixed << setprecision(2);

	getData(inFile, runnerNames, miles);

	inFile.close();

	totalMiles(runnerNames, miles, total, average);
	results(runnerNames, miles, total, average);

	return 0;
}

//Reads the data from the file
void getData(ifstream& inFile, string runnerNames[], double miles[][NUMOFCOLS])
{
	while (inFile)
	{
		for (int r = 0; r < 5; ++r)
		{
			inFile >> runnerNames[r];
			for (int c = 0; c < 7; ++c)
			{
				inFile >> miles[r][c];
			}
		}
	}
}

//Calculates the total miles and average miles
void totalMiles(const string runnerNames[], const double miles[][NUMOFCOLS],
				  double total[], double average[])
{
	for (int r = 0; r < 5; ++r)
	{
		for (int c = 0; c < 7; ++c)
			total[r] += miles[r][c];

		average[r] = total[r] / 7;
	}
}

//Outputs the results
void results(const string runnerNames[], const double miles[][NUMOFCOLS],
			 const double total[], const double average[])
{
	cout << setw(50) <<  "   Marathon Results   " << endl << setw(50)
		 << "Program by: Xavier Fox" << endl << endl;

	cout << "Name       Day 1   Day 2   Day 3   Day 4   Day 5   Day 6"
		 << "   Day 7   Total Average" << endl;

	for (int r = 0; r < 5; ++r)
	{
		cout << setw(8) << left << runnerNames[r] << right;
		for (int c = 0; c < 9; ++c)
		{
			if (c == 7)
				cout << setw(8) << total[r];
			else if (c == 8)
				cout << setw(8) << average[r];
			else
				cout << setw(8) << miles[r][c];
		}
	}
}