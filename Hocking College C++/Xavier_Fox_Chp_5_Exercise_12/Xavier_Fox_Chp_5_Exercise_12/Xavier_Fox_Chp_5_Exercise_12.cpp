/* Program: Xavier_Fox_Chp_5_Exercise_12.cpp
   Programmer: Xavier Fox
   Date: 16 Oct. 2014
   Purpose: To determine how many year it will take until
   the population of Town A is greater than or equal to
   Town B.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int townA, townB, yearCounter = 0;
	double growthRateA, growthRateB;

	cout << "Enter the current population for town A: ";
	cin >> townA;
	cout << endl;

	cout << "Enter the current population for town B: ";
	cin >> townB;
	cout << endl;

	cout << "Enter the growth rate for town A: ";
	cin >> growthRateA;
	cout << endl;

	cout << "Enter the growth rate for town B: ";
	cin >> growthRateB;
	cout << endl;

	while (townA < townB)
	{
		yearCounter++;
		townA = static_cast<int>(townA * (1 + growthRateA / 100));
		townB = static_cast<int>(townB * (1 + growthRateB / 100));
	}

	cout << "After " << yearCounter << " year(s) the population of "
		 << "town A will be greater than or equal to the population of "
		 << "town B." << endl << endl;

	cout << "After " << yearCounter << " year(s), population of town A "
		 << "will be: " << townA << endl;
	cout << "After " << yearCounter << " year(s), population of town B "
		 << "will be: " << townB << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

