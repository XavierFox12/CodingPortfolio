/* Program: Xavier_Fox_Chp_2_exercise_7.cpp
   Programmer: Xavier Fox
   Date: 11 Sep. 2014
   Purpose: To round a decimal number to the nearest
   integer.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	double decimalNumber;
	int roundedNumber;

	cout << "Enter a decimal number: ";
	cin >> decimalNumber;

	roundedNumber = static_cast<int>(decimalNumber + .5);

	cout << endl
		 << "The integer neartest to " << decimalNumber << " = "
		 << roundedNumber << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;
	return 0;
}

