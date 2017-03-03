/* Program: Xavier_Fox_Chp_6_Exercise_2.cpp
   Programmer: Xavier Fox
   Date: 27 Oct. 2014
   Purpose:
*/

#include "stdafx.h"
#include <iostream>
#include <cctype>

using namespace std;

char isVowel(char letter)
{
	switch (toupper(letter))
	{
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U':
		cout << letter << " is a vowel" << endl << endl;
		break;
	default:
		cout << letter << " is not a vowel" << endl << endl;
	}

	return letter;
}

int main()
{
	char vowel;

	cout << "Enter a letter: ";
	cin >> vowel;
	cout << endl;

	isVowel(vowel);

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

