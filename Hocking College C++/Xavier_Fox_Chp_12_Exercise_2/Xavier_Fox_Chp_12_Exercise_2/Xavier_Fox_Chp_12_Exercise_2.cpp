/* Program: Xavier_Fox_Chp_12_Exercise_2.cpp
   Programmer: Xavier Fox
   Date: 9 Feb. 2015
   Purpose: To output the student's grade based
   upon the answers they gave.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

char testGrade(int score, int maxScore);

int main()
{
	string ID;
	char *keyAnswers, *studentAnswers;
	int score, numQuestions, len, maxScore;

	ifstream inFile;

	inFile.open("E:\\SP2015\\C++\\Ch12_Ex2Data.txt");
	if (!inFile)
	{
		cout << "Cannot fine Ch12_Ex2Data.txt" << endl
			 << "   The Program Terminates   " << endl << endl;
		return 1;
	}

	cout << "Enter the number of exam questions: ";
	cin >> numQuestions;

	keyAnswers = new char[numQuestions];
	studentAnswers = new char[numQuestions];

	inFile.get(keyAnswers, numQuestions+1);
	cout << "Answer Key: " << keyAnswers << endl << endl;

	cout << setw(44) << "Student Test Information" << endl << endl
		 << "     ID" << setw(17) << " Answers" << setw(21) << "Score"
		 << setw(10) << "Grade" << endl << endl;

	inFile >> ID;
	inFile.get();
	inFile.get(studentAnswers, numQuestions+1);

	while (inFile)
	{
		score = 0;

		len = strlen(studentAnswers);
		for (int i=len; i < numQuestions; i++)
			studentAnswers[i] = ' ';

		studentAnswers[numQuestions] = '\0';

		for (int i = 0; i < numQuestions; i++)
		{
			if (studentAnswers[i] != ' ')
				if (studentAnswers[i] == keyAnswers[i])
					score += 2;
				else
					score--;
		}
		maxScore = numQuestions * 2;
		cout << "     " << ID << "    " << studentAnswers << "     " << score
			 << "        " << testGrade(score, maxScore) << endl;

		inFile >> ID;
		inFile.get();
		inFile.get(studentAnswers, numQuestions+1);
	}

	inFile.close();

	cout << endl << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

// Returns the grade
char testGrade(int score, int maxScore)
{
	char grade;
	double average;

	average = 100.0 * (static_cast<double>(score) / maxScore);

	if (average >= 90)
		return 'A';
	if (average >= 80)
		return 'B';
	if (average >= 70)
		return 'C';
	if (average >= 60)
		return 'D';
	else 
		return 'F';

	return grade;
}