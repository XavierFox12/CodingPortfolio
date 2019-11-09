/* Program: Xavier_Fox_Chp_5_Exercise_4.cpp
   Programmer: Xavier Fox
   Date: 14 Oct. 2014
   Purpose: To convert a string into a telephone number.
*/

#include "stdafx.h"
#include <iostream>
#include <cctype>

using namespace std;

int main()
{
	char yesOrNo = 'y', letter;
	int digits;

	while (yesOrNo == 'y')
	{
		cout << "Enter a telephone number using letters: ";
		cin >> letter;
		cout << endl;

		cout << "The corresponding telephone number is: ";

		digits = 1;

		while (digits <= 7)
		{
			switch (toupper(letter))
			{
			case 'A':
			case 'B':
			case 'C':
				cout << '2';
				break;
			case 'D':
			case 'E':
			case 'F':
				cout << '3';
				break;
			case 'G':
			case 'H':
			case 'I':
				cout << '4';
				break;
			case 'J':
			case 'K':
			case 'L':
				cout << '5';
				break;
			case 'M':
			case 'N':
			case 'O':
				cout << '6';
				break;
			case 'P':
			case 'Q':
			case 'R':
				cout << '7';
				break;
			case 'S':
			case 'T':
			case 'U':
				cout << '8';
				break;
			case 'V':
			case 'W':
			case 'X':
				cout << '9';
				break;
			case 'Y':
			case 'Z':
				cout << '0';
				break;

			default:
			{
				cout << endl << endl 
					 << "*** Invalid charater: " << letter << " ***";
				digits = 7;
			}

			}
			if (digits == 3)
				cout << '-';

			if (digits != 7)
				cin >> letter;
			
			digits++;
		}

		cin.ignore(100, '\n');

		cout << endl << endl
			 << "Do you want to enter another telephone number? (y/n) ";
		cin >> yesOrNo;
		cout << endl;
	}

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

