/* Program: Xavier_Fox_Chp_1_Exercise_16.cpp
   Programmer: Xavier Fox
   Date: 28 Aug 2014
   Purpose: To convert quarters, dimes, nickels, and pennies into pennies.
*/

#include "stdafx.h"

#include <iostream>

using namespace std;

int main()
{
	int quarters, dimes, nickels, pennies, changeInPennies;

	cout << "Enter the number of quarters: ";
	cin >> quarters;

	cout << "Enter the number of dimes: ";
	cin >> dimes;

	cout << "Enter the number of nickels: ";
	cin >> nickels;

	cout << "Enter the number of pennies: ";
	cin >> pennies;

	changeInPennies = quarters * 25 +
					  dimes * 10 +
					  nickels * 5 +
					  pennies;

	cout << endl
		 << "Change in Pennies: " << changeInPennies
		 << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;
	return 0;
}

