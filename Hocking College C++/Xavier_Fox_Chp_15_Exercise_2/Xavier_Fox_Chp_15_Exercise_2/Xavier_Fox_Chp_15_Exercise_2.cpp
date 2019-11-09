/* Program: Xavier_Fox_Chp_15_Exercise_2.cpp
   Programmer: Xavier Fox
   Date: 24 Mar. 2015
   Purpose: Prints out stars from the number of lines given
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

void numOfStars(int count, int numOfLines);

int main()
{
	int numOfLines, count = 1;

	cout << "Enter the number of lines in the grid: ";
	cin >> numOfLines;
	cout << endl;

	numOfStars(count, numOfLines);

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

// Prints out the stars from the number of lines given
void numOfStars(int count, int numOfLines)
{
	int i;

	if (numOfLines >= count)
	{
		cout << setw(numOfLines - count + 1) << " ";

		for (i = 1; i <= count; i++)
			cout << "* ";

		cout << endl;

		numOfStars(count + 1, numOfLines);

		count -= 1;

		cout << setw(numOfLines - count + 1) << " ";

		for (i = count; i > 0; i--)
		{
			cout << "* ";
		}
		--count;
		cout << endl;
	}
}