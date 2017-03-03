/* Program: Xavier_Fox_Chp_3_Exercise_3.cpp
   Programmer: Xavier Fox
   Date: 22 Sep. 2014
   Purpose: To determine the how much you weigh in
   kilograms and convert it to pounds.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double weightInKilograms, weightInPounds;

	cout << "Enter the weight in kilograms: ";
	cin >> weightInKilograms;

	weightInPounds = weightInKilograms * 2.2;

	cout << fixed << showpoint << setprecision(2);

	cout << endl << "The equivalent in pounds: " << weightInPounds << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

