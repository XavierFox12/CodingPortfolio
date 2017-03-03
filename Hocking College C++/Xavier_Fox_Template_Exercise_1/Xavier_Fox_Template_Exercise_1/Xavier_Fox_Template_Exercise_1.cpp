/* Program: Xavier_Fox_Template_Exercise_1.cpp
   Programmer: Xavier Fox
   Date: 9 Mar. 2015
   Purpose: Determines the smallest, middle, and largest
   value given.
*/

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

template <class Type>
Type min(Type x, Type y, Type z);

template <class Type>
Type med(Type x, Type y, Type z);

template <class Type>
Type max(Type x, Type y, Type z);

int main()
{
	int intX, intY, intZ;
	char charX, charY, charZ;
	string stringX, stringY, stringZ;

	cout << "Enter three integers: ";
	cin >> intX >> intY >> intZ;

	cout << "The minimum value is: " << min(intX, intY, intZ) << endl
		 << "the middle value is: " << med(intX, intY, intZ) << endl
		 << "the maximum value is: " << max(intX, intY, intZ) << endl << endl;

	cout << "Enter three characters: ";
	cin >> charX >> charY >> charZ;

	cout << "The minimum value is: " << min(charX, charY, charZ) << endl
		 << "the middle value is: " << med(charX, charY, charZ) << endl
		 << "the maximum value is: " << max(charX, charY, charZ) << endl << endl;

	cout << "Enter three strings: ";
	cin >> stringX >> stringY >> stringZ;

	cout << "The minimum value is: " << min(stringX, stringY, stringZ) << endl
		 << "the middle value is: " << med(stringX, stringY, stringZ) << endl
		 << "the maximum value is: " << max(stringX, stringY, stringZ)
		 << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

// returns the smallest value
template <class Type>
Type min(Type x, Type y, Type z)
{
	if (x < y && x < z)
		return x;
	else if (y < x && y < z)
		return y;
	else
		return z;
}

// returns the middle value
template <class Type>
Type med(Type x, Type y, Type z)
{
	if ((x < y && x > z) || (x > y && x < z))
		return x;
	else if ((y < x && y > z) || (y > x && y < z))
		return y;
	else
		return z;
}

// returns the largest value
template <class Type>
Type max(Type x, Type y, Type z)
{
	if (x > y && x > z)
		return x;
	else if (y > x && y > z)
		return y;
	else
		return z;
}