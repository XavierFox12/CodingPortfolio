/* Program: Xavier_Fox_Chp_15_Exercise_3.cpp
   Programmer: Xavier Fox
   Date: 27 Mar. 2015
   Purpose: Uses recursion to determine how many
   vowels are in the string variable.
*/

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int vowels(string inputString, int pos);

int main()
{
	string inputString;

	cout << "Enter a string: ";
	getline(cin, inputString);
	cout << endl;

	cout << '"'<< inputString << '"' << " has: " << vowels(inputString, 0) << " vowel(s)."
		 << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

// Finds the number of vowels in a string
int vowels(string inputString, int pos)
{
	if (pos == inputString.length())
		return 0;
	
	if (inputString[pos] == 'a' || inputString[pos] == 'A')
		return 1 + vowels(inputString, pos+1);

	else if (inputString[pos] == 'e' || inputString[pos] == 'E')
		return 1 + vowels(inputString, pos+1);

	else if (inputString[pos] == 'i' || inputString[pos] == 'I')
		return 1 + vowels(inputString, pos+1);

	else if (inputString[pos] == 'o' || inputString[pos] == 'O')
		return 1 + vowels(inputString, pos+1);

	else if (inputString[pos] == 'u' || inputString[pos] == 'U')
		return 1 + vowels(inputString, pos+1);

	else
		return vowels(inputString, pos+1);
}