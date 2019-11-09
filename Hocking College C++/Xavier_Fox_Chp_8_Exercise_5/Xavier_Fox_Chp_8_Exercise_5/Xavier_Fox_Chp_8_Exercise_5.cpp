/* Program: Xavier_Fox_Chp_8_Exercise_5.cpp
   Programmer: Xavier Fox
   Date: 20 Nov. 2014
   Purpose: To convert a string into uppercase letters.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	char letterArray[81];
	int stringLength;

	cout << "Enter a string of characters: ";
	cin.get(letterArray, 80);
	cout << endl;

	cout << "String in upper case letters is: " << endl;
	stringLength = strlen(letterArray);

	for (int i = 0; i < stringLength; ++i)
		cout << static_cast<char>(toupper(letterArray[i]));

	cout << endl << endl << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

