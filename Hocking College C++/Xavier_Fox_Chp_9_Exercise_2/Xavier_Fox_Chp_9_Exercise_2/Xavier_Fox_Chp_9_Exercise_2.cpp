/* Program: Xavier_Fox_Chp_9_Exercise_2.cpp
   Programmer: Xavier Fox
   Date: 1 Dec. 2014
   Purpose: To determine who got the highest grade in the
   class and to determine what letter grade each student
   got.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

const int ARRAY_SIZE = 20;

struct studentType
{
	string studentFName;
	string studentLName;
	int testScore;
	char grade;
};

void getData(ifstream& inFile, studentType studentInfo[]);
void relevantGrade(studentType studentInfo[]);
int highestScore(const studentType studentInfo[], int& highestTestScore);
void printData(const studentType studentInfo[], int highestTestScore);

int main()
{
	studentType studentInfo[ARRAY_SIZE];
	int highestTestScore;

	ifstream inFile;

	inFile.open("E:\\C++\\Ch9_Ex2Data.txt");
	if (!inFile)
	{
		cout << "Cannot find Ch9_Ex2Data.txt" << endl
			 << "  The Program terminates   " << endl << endl;
		return 1;
	}

	getData(inFile, studentInfo);

	inFile.close();

	relevantGrade(studentInfo);
	highestTestScore = highestScore(studentInfo, highestTestScore);
	printData(studentInfo, highestTestScore);

	return 0;
}

//Reads the students data into an array
void getData(ifstream& inFile, studentType studentInfo[])
{
	while (inFile)
	{
		for (int i = 0; i < ARRAY_SIZE; ++i)
		{
			inFile >> studentInfo[i].studentFName >> studentInfo[i].studentLName
				>> studentInfo[i].testScore;
		}
	}
}

//assigns the relevant grade to each student
void relevantGrade(studentType studentInfo[])
{
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		if (studentInfo[i].testScore < 100 && studentInfo[i].testScore >= 90)
			studentInfo[i].grade = 'A';
		
		else if (studentInfo[i].testScore >= 80)
			studentInfo[i].grade = 'B';

		else if (studentInfo[i].testScore >= 70)
			studentInfo[i].grade = 'C';

		else if (studentInfo[i].testScore >= 60)
			studentInfo[i].grade = 'D';

		else
			studentInfo[i].grade = 'F';
	}
}

//Determines who got the highest test score
int highestScore(const studentType studentInfo[], int& highestTestScore)
{
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		if (studentInfo[i].testScore > highestTestScore)
			highestTestScore = studentInfo[i].testScore;
	}

	return highestTestScore;
}

//prints the names of the students and their grades
void printData(const studentType studentInfo[], int highestTestScore)
{
	cout << setw(50) << "Student Grade Analysis" << endl
		 << setw(50) << "Program by: Xavier Fox" << endl << endl;

	cout << setw(15) << "Student Name" << setw(27) << "Test Score" << setw(18)
		 << "Grade" << endl << endl;

	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		cout << setw(3) << left << "" << setw(20)
			 << studentInfo[i].studentFName + ", "
			 + studentInfo[i].studentLName
		     << right << setw(15) << studentInfo[i].testScore
			 << setw(20) << studentInfo[i].grade << endl;
	}

	cout << endl << "   Highest Test Score: " << highestTestScore
		 << endl << endl;

	cout << setw(15) << "   Students having the highest test score:" << endl;
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		if (studentInfo[i].testScore == highestTestScore)
		{
			cout << setw(12) << left << "" << studentInfo[i].studentLName << ", " 
				 << studentInfo[i].studentFName << endl;
		}
	}
	cout << endl;
}