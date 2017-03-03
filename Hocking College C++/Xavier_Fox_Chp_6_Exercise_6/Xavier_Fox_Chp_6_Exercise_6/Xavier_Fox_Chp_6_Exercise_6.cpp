/* Program: Xavier_Fox_Chp_6_Exercise_6.cpp
   Programmer: Xavier Fox
   Date: 30 Oct. 2014
   Purpose: To reverse the number from the
   input given.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int reverseDigit(int num);

int main()
{
	int number;

	cout << "Enter an integer: ";
	cin >> number;
	cout << endl;

	reverseDigit(number);

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

int reverseDigit(int num)
{
	int reverseNum = 0;
	bool isNegative = false;

	cout << "The reversed number of " << num
		 << " = ";

	if (num < 0)
	{
		num = -num;
		isNegative = true;
	}

	while (num > 0)
	{
		reverseNum = reverseNum * 10 + num % 10;
		num = num / 10;
	}

	if (isNegative == true)
		reverseNum = -reverseNum;

	cout << reverseNum << ", leading zeros if any are not shown"
		 << endl << endl;

	return reverseNum;
}
