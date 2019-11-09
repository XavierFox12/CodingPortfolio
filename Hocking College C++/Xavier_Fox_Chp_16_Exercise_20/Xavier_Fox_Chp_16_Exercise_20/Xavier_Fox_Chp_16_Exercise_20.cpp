/* Program: Xavier_Fox_Chp_16_Exercise_20.cpp
   Programmer: Xavier Fox
   Date: 13 Apr. 2015
   Purpose: To determine the students grades and averages
   in the world history class.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

const int NUMOFCOLS = 6;
const int NUMOFROWS = 10;

void getData(ifstream& inFile, string studentNames[],
			 double testScores[][NUMOFCOLS]);
void bubbleSort(string list[], int length, double testScores[][NUMOFCOLS],
				char grades[]);
void calculateScore(double testScores[][NUMOFCOLS], char grades[]);
void printResults(string studentNames[], double testScores[][NUMOFCOLS],
				  char grades[]);


int main()
{
	string studentNames[NUMOFROWS];
	double testScores[NUMOFROWS][NUMOFCOLS];
	char grades[NUMOFROWS];

	ifstream inFile;

	inFile.open("E:\\SP2015\\C++\\Ch16_Ex20Data.txt");
	if (!inFile)
	{
		cout << "Cannot find Ch16_Ex20Data.txt" << endl
			 << "    The Program terminates   " << endl << endl;
		return 1;
	}

	getData(inFile, studentNames, testScores);

	inFile.close();

	calculateScore(testScores, grades);
	bubbleSort(studentNames, NUMOFROWS, testScores, grades);
	printResults(studentNames, testScores, grades);

	return 0;
}

//Reads and stores the student data
void getData(ifstream& inFile, string studentNames[], double testScores[][NUMOFCOLS])
{
	while (inFile)
	{
		double sum;

		for (int r = 0; r < NUMOFROWS; r++)
		{
			inFile >> studentNames[r];
			sum = 0.0;
			for (int c = 0; c < 5; c++)
			{
				inFile >> testScores[r][c];
				sum += testScores[r][c];
			}
			testScores[r][5] = sum / 5;
		}
	}
}

// sorts the array
void bubbleSort(string list[], int length, double testScores[][NUMOFCOLS],
				char grades[])
{
	string temp;
	double scoreTemp;
	char gradeTemp;
	int iteration;
	int index;
	
	for (iteration = 1; iteration < length; iteration++)
	{
		for (index = 0; index < length - iteration; index++)
			if (list[index] > list[index + 1])
			{
				temp = list[index];
				list[index] = list[index + 1];
				list[index + 1] = temp;
				gradeTemp = grades[index];
				grades[index] = grades[index + 1];
				grades[index + 1] = gradeTemp;
				for (int i = 0; i < 6; i++)
				{
					scoreTemp = testScores[index][i];
					testScores[index][i] = testScores[index + 1][i];
					testScores[index + 1][i] = scoreTemp;
				}
			}
	}
} 

//Calculates the letter grade
void calculateScore(double testScores[][NUMOFCOLS], char grades[])
{
	for (int r = 0; r < NUMOFROWS; r++)
	{
		if (testScores[r][5] >= 90 && testScores[r][5] <= 100)
			grades[r] = 'A';
		else if (testScores[r][5] >= 80)
			grades[r] = 'B';
		else if (testScores[r][5] >= 70)
			grades[r] = 'C';
		else if (testScores[r][5] >= 60)
			grades[r] = 'D';
		else
			grades[r] = 'F';
	}
}

//Outputs the results
void printResults(string studentNames[], double testScores[][NUMOFCOLS], char grades[])
{
	double classAverage = 0.0;

	cout << setw(50) << "World History Class Results" << endl
		 << setw(50) << "  Program by: Xavier Fox   " << endl << endl;

	cout << "Name        Test 1  Test 2  Test 3  Test 4  Test 5   Average   Grade"
		 << endl << endl;

	cout << showpoint << fixed << setprecision(2);

	for (int r = 0; r < NUMOFROWS; r++)
	{
		cout << setw(10) << left << studentNames[r] << right;
		for (int c = 0; c < NUMOFCOLS - 1; c++)
		{
			cout << setw(8) << testScores[r][c];
		}
		cout << setw(10) << testScores[r][5];
		cout << setw(6) << grades[r] << endl;;
		classAverage += testScores[r][5];
	}
	classAverage = classAverage / NUMOFROWS;
	cout << endl << "Class Average: " << classAverage << endl << endl;
}