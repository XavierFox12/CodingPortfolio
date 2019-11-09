/* Program: Xavier_Fox_Chp_4_Exercise_3.cpp
   Programmer: Xavier Fox
   Date: 29 Sep. 2014
   Purpose: To convert any number between 10 and
   35 into a letter.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int number;
	char letter;

	cout << "Enter an integer between 0 and 35: ";
	cin >> number;
	cout << endl;

	cout << "The number you entered is: " << number << endl;

	if (number <= 9)
	{
		cout << "Output: " << number << endl << endl;
	}

	else if (number >= 10)
	{
		number = number + 55;
		letter = static_cast<char>(number);
		cout << "Output: " << letter << endl << endl;
	}

	else if (number > 35)
	{
		cout << "Your number was not between 0 and 35. Try again"
			 << endl << endl;
	}

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

