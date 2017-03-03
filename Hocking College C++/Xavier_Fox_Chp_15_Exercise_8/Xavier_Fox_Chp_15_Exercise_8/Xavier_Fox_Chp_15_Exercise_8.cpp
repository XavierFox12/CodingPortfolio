/* Program: Xavier_Fox_Chp_15_Exercise_8.cpp
   Programmer: Xavier Fox
   Date: 31 Mar. 2015
   Purpose: To determine if the digits in a number
   is in increasing order.
*/

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

bool increasingOrder(string number, int index, int length);

int main()
{
	string number;
	int length;

	cout << "Enter a number: ";
	cin >> number;
	cout << endl;

	length = number.length();

	if (increasingOrder(number, 0, length - 1))
	{
		cout << "The digits of " << number << " are in increasing order."
			 << endl << endl;
	}
	else
	{
		cout << "The digits of " << number << " are not in increasing order."
			 << endl << endl;
	}

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

// determines if the digits are in increasing order
bool increasingOrder(string number, int index, int length)
{
	if (index == length)
		return true;

	else if (number[index] < number[index + 1])
		return increasingOrder(number, index + 1, length);

	else
		return false;
}