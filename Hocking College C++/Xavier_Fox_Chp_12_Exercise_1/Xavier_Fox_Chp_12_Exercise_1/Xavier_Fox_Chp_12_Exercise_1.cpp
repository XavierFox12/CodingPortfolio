/* Program: Xavier_Fox_Chp_12_Exercise_1.cpp
   Programmer: Xavier Fox
   Date: 9 Feb. 2015
   Purpose: To output string characters all in uppercase
   letters.
*/

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
	char *letterArray;
	int stringLength;

	cout << "Enter the size of the string: ";
	cin >> stringLength;
	cout << endl;
	cin.get();

	letterArray = new char[stringLength+1];

	cout << "Enter a string of characters at most " << stringLength << ": ";
	cin.get(letterArray, stringLength+1);
	cout << endl;

	cout << "String in upper case letters is: ";
	stringLength = strlen(letterArray);

	for (int i = 0; i < stringLength; ++i)
		cout << static_cast<char>(toupper(letterArray[i]));

	cout << endl << endl << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

