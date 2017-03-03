/* Program: Xavier_Fox_Chp_15_Exercise_9.cpp
   Programmer: Xavier Fox
   Date: 1 Apr. 2015
   Purpose: Prints out the number in reverse order
*/

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void reverseDigits(int number);

int main()
{
	int number;

	cout << "Enter a number: ";
	cin >> number;
	cout << endl;

	if (number < 0)
	{
		number = -number;
		cout << "The number " << number << " reversed is: -";
	}
	else
	{
		cout << "The number " << number << " reversed is: ";
	}

	reverseDigits(number);

	cout << endl << endl << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

// returns the reverse order of the digits
void reverseDigits(int number)
{
	if (number == 0)
		return;

	else
	{
		cout << number % 10;
		return reverseDigits(number / 10);
	}
}