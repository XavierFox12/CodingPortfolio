/* Program: Xavier_Fox_Bunker_County_School_Board_Project_Part_2.cpp
   Programmer: Xavier Fox
   Date: 5 May 2015
   Purpose: Updates the proficiency_results data file.
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
int searchArray(string districtNames[], string schoolDistrict);
void updateFile(string districtNames[], int testScores[][NUMOFCOLS], int districtNum);
void rewriteFile(string districtNames[], int testScores[][NUMOFCOLS]);

int main()
{
	string districtNames[NUMOFROWS];
	int testScores[NUMOFROWS][NUMOFCOLS], districtNum;
	string schoolDistrict;
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

	cout << "\t Welcome to the Bunker County School Districts" << endl
		 << "\t      Proficiency Score Update Program        " << endl << endl;
	cout << "Enter the name of the School District or 'Q' to quit: ";
	cin >> schoolDistrict;
	cout << endl;

	system("cls");

	while (schoolDistrict != "Q")
	{
		districtNum = searchArray(districtNames, schoolDistrict);

		if (districtNum == -1)
			cout << "Invalid school district" << endl << endl;
		else
		{
			updateFile(districtNames, testScores, districtNum);

			rewriteFile(districtNames, testScores);
			system("cls");
		}

		cout << "\t Welcome to the Bunker County School Districts" << endl
			 << "\t      Proficiency Score Update Program        " << endl << endl;
		cout << "Enter the name of the School District or 'Q' to quit: ";
		cin >> schoolDistrict;
		cout << endl;

		system("cls");
	}

	cout << "Program by: Xavier Fox" << endl << endl;

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

// searches the array
int searchArray(string districtNames[], string schoolDistrict)
{
	int first = 0;
	int last = NUMOFROWS - 1;
	int mid;
	bool found = false;
	
	while (first <= last && !found)
	{
		mid = (first + last) / 2;
		
		if (districtNames[mid] == schoolDistrict)
			found = true;
		else if (districtNames[mid] > schoolDistrict)
			last = mid - 1;
		else
			first = mid + 1;
	}
	
	if (found)
		return mid;
	else
		return -1;
}

// updates the proficiency_results.dat file
void updateFile(string districtNames[], int testScores[][NUMOFCOLS], int districtNum)
{
	char updateCode = ' ';
	int updatedScore;

	while (updateCode != 'X')
	{
		cout << "\t\t\t    Current Information" << endl << endl
			 << "\t\t\t District          : " << districtNames[districtNum] << endl
			 << "\t\t\t Citizenship Score : " << testScores[districtNum][0] << endl
			 << "\t\t\t Math Score        : " << testScores[districtNum][1] << endl
			 << "\t\t\t Reading Score     : " << testScores[districtNum][2] << endl
			 << "\t\t\t Writing Score     : " << testScores[districtNum][3] << endl
			 << endl;

		cout << "Enter one of the following update codes:" << endl
			 << "\t (C)itizenship, (M)ath, (R)eading, (W)riting, or E(X)it: ";
		cin >> updateCode;
		cout << endl;

		if (updateCode == 'C')
		{
			cout << "Enter the updated score for Citizenship: ";
			cin >> updatedScore;

			testScores[districtNum][0] = updatedScore;
			system("cls");
		}

		else if (updateCode == 'M')
		{
			cout << "Enter the updated score for Math: ";
			cin >> updatedScore;

			testScores[districtNum][1] = updatedScore;
			system("cls");
		}

		else if (updateCode == 'R')
		{
			cout << "Enter the updated score for Reading: ";
			cin >> updatedScore;

			testScores[districtNum][2] = updatedScore;
			system("cls");
		}

		else if (updateCode == 'W')
		{
			cout << "Enter the updated score for Writing: ";
			cin >> updatedScore;

			testScores[districtNum][3] = updatedScore;
			system("cls");
		}
		else if (updateCode == 'X')
			system("cls");

		else
		{
			system("cls");
			cout << "Invalid update code" << endl << endl;
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