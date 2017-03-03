/* Program: Xavier_Fox_Chp_15_Exercise_10.cpp
   Programmer: Xavier Fox
   Date: 1 Apr. 2015
   Purpose: adds the digits of the number entered
*/

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int sumDigits(int number);

int main()
{
	int number;
	int sum = 0;

	cout << "Enter a number: ";
	cin >> number;
	cout << endl;

	sum = sumDigits(number);

	cout << "The sum of all of the digits of " << number << " = "
		 << sum << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

// returns the sum of all of the digits entered
int sumDigits(int number)
{
	if (number == 0)
		return 0;
	else
	{
		return sumDigits(number / 10) + number % 10;
	}
}