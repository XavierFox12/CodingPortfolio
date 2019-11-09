/* Program: Xavier_Fox_Bunker_County_School_Board_Project_Part_1.cpp
   Programmer: Xavier Fox
   Date: 4 May 2015
   Purpose: Opens the proficienty school results file,
   prints the report and outputs the updated results 
   back into the file.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int NUMOFCOLS = 4;
const int NUMOFROWS = 10;

void getData(ifstream& inFile, string districtNames[], int testScores[][NUMOFCOLS]);
void bubbleSort(string districtNames[], int length, int testScores[][NUMOFCOLS]);
void rewriteFile(string districtNames[], int testScores[][NUMOFCOLS]);
void printResults(string districtNames[], int testScores[][NUMOFCOLS]);

int main()
{
	string districtNames[NUMOFROWS];
	int testScores[NUMOFROWS][NUMOFCOLS];
	ifstream inFile;

	inFile.open("E:\\SP2015\\C++\\proficiency_results.dat");
	if (!inFile)
	{
		cout << "Cannot find proficiency_results.dat" << endl
			 << "      The Program terminates       " << endl << endl;
		return 1;
	}

	getData(inFile, districtNames, testScores);

	inFile.close();

	bubbleSort(districtNames, NUMOFROWS, testScores);
	rewriteFile(districtNames, testScores);
	printResults(districtNames, testScores);

	return 0;
}

// loads the data into the array
void getData(ifstream& inFile, string districtNames[], int testScores[][NUMOFCOLS])
{
	while (inFile)
	{
		for (int r = 0; r < NUMOFROWS; r++)
		{
			inFile >> districtNames[r];
			for (int c = 0; c < NUMOFCOLS; c++)
				inFile >> testScores[r][c];
		}
	}
}

// sorts the two arrays
void bubbleSort(string districtNames[], int length, int testScores[][NUMOFCOLS])
{
	string temp;
	int scoreTemp;
	int iteration;
	int index;
	
	for (iteration = 1; iteration < length; iteration++)
	{
		for (index = 0; index < length - iteration; index++)
			if (districtNames[index] > districtNames[index + 1])
			{
				temp = districtNames[index];
				districtNames[index] = districtNames[index + 1];
				districtNames[index + 1] = temp;
				for (int i = 0; i < NUMOFCOLS; i++)
				{
					scoreTemp = testScores[index][i];
					testScores[index][i] = testScores[index + 1][i];
					testScores[index + 1][i] = scoreTemp;
				}
			}
	}
}

// rewrites to the proficiency_results.dat file
void rewriteFile(string districtNames[], int testScores[][NUMOFCOLS])
{
	ofstream outFile;

	outFile.open("E:\\SP2015\\C++\\proficiency_results.dat");
	for (int r = 0; r < NUMOFROWS; r++)
	{
		outFile << districtNames[r] << " ";
		for (int c = 0; c < NUMOFCOLS; c++)
			outFile << testScores[r][c] << " ";

		outFile << endl;
	}

	outFile.close();
}

// Prints the report
void printResults(string districtNames[], int testScores[][NUMOFCOLS])
{
	double sum;

	cout << setw(50) << "B U N K E R  C O U N T Y" << endl
		 << setw(50) << "    PROFICIENCY REPORT  " << endl
		 << setw(50) << " Program by: Xavier Fox " << endl << endl;

	cout << "School District   Citizenship   Math    Reading   Writing     Average"
		 << endl << endl;

	cout << showpoint << fixed << setprecision(2);

	for (int r = 0; r < NUMOFROWS; r++)
	{
		cout << setw(10) << left << districtNames[r] << right << setw(15);

		sum = 0.0;
		for (int c = 0; c < NUMOFCOLS; c++)
		{
			cout << testScores[r][c] << "        ";
			sum += testScores[r][c];
		}
		cout << sum / 4 << endl;
	}
	cout << endl;
}