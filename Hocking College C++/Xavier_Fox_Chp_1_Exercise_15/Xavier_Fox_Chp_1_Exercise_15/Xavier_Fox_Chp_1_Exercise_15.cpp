/* Program: Xavier_Fox_Chp_1_Exercise_15.cpp
   Programmer: Xavier Fox
   Date: 28 Aug 2014
   Purpose: Determine the weighted average of four test scores.
*/

#include "stdafx.h"

#include <iostream>

using namespace std;

int main()
{
	int testScore1, testScore2, testScore3, testScore4;
	double weightedTestScore1, weightedTestScore2,
		   weightedTestScore3, weightedTestScore4,
		   weightedAverage;

	cout << "Enter Test Score 1: ";
	cin >> testScore1;
	cout << "Enter Weight for Test Score 1: ";
	cin >> weightedTestScore1;

	cout << "Enter Test Score 2: ";
	cin >> testScore2;
	cout << "Enter Weight for Test Score 2: ";
	cin >> weightedTestScore2;

	cout << "Enter Test Score 3: ";
	cin >> testScore3;
	cout << "Enter Weight for Test Score 3: ";
	cin >> weightedTestScore3;

	cout << "Enter Test Score 4: ";
	cin >> testScore4;
	cout << "Enter Weight for Test Score 4: ";
	cin >> weightedTestScore4;

	weightedAverage = testScore1 * weightedTestScore1 +
					  testScore2 * weightedTestScore2 +
					  testScore3 * weightedTestScore3 +
					  testScore4 * weightedTestScore4;
	cout << endl
		 << "Weighted Average: " << weightedAverage
		 << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

