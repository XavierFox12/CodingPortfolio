/* Program: Xavier_Fox_Chp_15_Exercise_1.cpp
   Programmer: Xavier Fox
   Date: 24 Mar. 2015
   Purpose: Prints out stars from the number of lines given
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

void numOfStars(int numOfLines);

int main()
{
	int numOfLines;

	cout << "Enter the number of lines in the grid: ";
	cin >> numOfLines;
	cout << endl;

	numOfStars(numOfLines);

	cout << endl << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

// Prints out the stars from the number of lines given
void numOfStars(int numOfLines)
{
	int count = numOfLines;

	if (numOfLines > 0)
	{
		while (count > 0)
		{
			cout << "*";
			--count;
		}
		cout << endl;

		numOfStars(numOfLines - 1);

		count = numOfLines;

		while (count > 0)
		{
			cout << "*";
			--count;
		}
		cout << endl;
	}
}