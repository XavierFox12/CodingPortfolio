/* Program: Xavier_Fox_Chp_2_exercise_9.cpp
   Programmer: Xavier Fox
   Date: 15 Sep. 2014
   Purpose: To determine the average of five test scores.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	double testScore1, testScore2, testScore3, testScore4, 
		   testScore5, average;

	cout << "Enter five test scores: ";
	cin >> testScore1 >> testScore2 >> testScore3 >> testScore4
		>> testScore5;

	average = (testScore1 + testScore2 + testScore3 + testScore4 +
			  testScore5) / 5;

	cout << endl << "Average test score: " << average << endl
		 << endl;


	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

