/* Program: Xavier_Fox_Chp_6_Exercise_3.cpp
   Programmer: Xavier Fox
   Date: 27 Oct. 2014
   Purpose: To determine how many vowels are
   in a sentence.
*/

#include "stdafx.h"
#include <iostream>
#include <cctype>

using namespace std;

bool isVowel(char letter)
{
	switch (toupper(letter))
	{
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U':
		return true;
	default:
		return false;
	}
}

int main()
{
	char vowelSentance;
	int count = 0;

	cout << "Enter a sentence: ";
	cin.get(vowelSentance);
	
	while (vowelSentance != '\n')
	{
		if (isVowel(vowelSentance))
			++count;
		
		cin.get(vowelSentance);
	}

	cout << endl << "There are " << count << " vowels in this sentance"
		 << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

