/* Program: Xavier_Fox_Chp_15_Exercise_4.cpp
   Programmer: Xavier Fox
   Date: 30 Mar. 2015
   Purpose: Use recursion to return the squares of numbers from 0
   to the number entered.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int numSquares(int num1, int num2);

int main()
{
	int number;

	cout << "Enter a nonnegative integer: ";
	cin >> number;
	cout << endl;

	cout << "The sum of the numbers from 0 to " << number << " = "
		 << numSquares(0, number) << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

// returns the value of 0 to the number entered squared
int numSquares(int num1, int num2)
{
	if (num2 == 0)
		return 0;
	else if (num1 == num2)
		return num1 * num1;
	else
		return num1 * num1 + numSquares(num1 + 1, num2);
}