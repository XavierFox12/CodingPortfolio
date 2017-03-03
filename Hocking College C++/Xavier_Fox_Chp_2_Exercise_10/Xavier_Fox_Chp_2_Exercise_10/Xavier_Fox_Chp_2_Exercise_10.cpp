/* Program: Xavier_Fox_Chp_2_Exercise_10.cpp
   Programmer: Xavier Fox
   Date: 15 Sep. 2014
   Purpose: To take 5 decimal numbers and convert the sum
   into an integer.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	double decNum1, decNum2, decNum3, decNum4,
		   decNum5, sumOfDecNum;
	int convertedInteger;

	cout << "Enter five decimal numbers: ";
	cin >> decNum1 >> decNum2 >> decNum3
		>> decNum4 >> decNum5;

	sumOfDecNum = decNum1 + decNum2 + decNum3 +
		          decNum4 + decNum5;

	convertedInteger = static_cast<int>(sumOfDecNum + .5);

	cout << endl << "The sum of the numbers to the nearest integer = "
		 << convertedInteger << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

