/* Program: Xavier_Fox_Chp_6_Exercise_1.cpp
   Programmer: Xavier Fox
   Date: 27 Oct. 2014
   Purpose: To determine is the characters given
   can be a palidrome.
*/

#include "stdafx.h"
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

bool isPalidrome(string str)
{
	int length = str.length();
	for (int i = 0; i < length / 2; i++)
		if (toupper(str[i]) != toupper(str[length - 1 -i]))
			return false;
	return true;
}

int main()
{
	string characterString;
	char yesOrNo = 'y';

	while (yesOrNo == 'y')
	{
		cout << "Enter a character string: ";
		cin >> characterString;

		if (isPalidrome(characterString))
			cout << characterString << " is a palidrome" << endl << endl;
		else
			cout << characterString << " is not a palidrome" << endl << endl;

		cout << "Do you wish to continue? (y/n) ";
		cin >> yesOrNo;
		cout << endl;
	}

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

