/* Program: Xavier_Fox_Chp_4_Exercise_1.cpp
   Programmer: Xavier Fox
   Date: 29 Sep. 2014
   Purpose: To determine if the number entered
   is positive, negative, or a zero.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int num1;

	cout << "Enter a number: ";
	cin >> num1;

	if (num1 > 0)
	{
		cout << endl << "The number you entered is "
			 << num1 << ", and this is a positive number"
			 << endl << endl;
	}
	else if (num1 < 0)
	{
		cout << endl << "The number you entered is "
			 << num1 << ", and this is a negative number"
			 << endl << endl;
	}
	else if (num1 == 0)
	{
		cout << endl << "The number you entered is "
			 << num1 << ", and this is a zero"
			 << endl << endl;
	}

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

