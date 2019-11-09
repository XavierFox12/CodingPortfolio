/* Program: Xavier_Fox_Chp_5_Exercise_5.cpp
   Programmer: Xavier Fox
   Date: 13 Oct. 2014
   Purpose: To read a set of integers and print
   the sum of the even and odd numbers
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int num, evenSum = 0, oddSum = 0, i = 1;

	cout << "Enter 7 integers: ";

	while (i <= 7)
	{
		cin >> num;

		if (num % 2 == 0)
			evenSum += num;
		else
			oddSum += num;

		i++;
	}

	cout << endl << "Sum of the even numbers: " << evenSum << endl
		 << "Sum of the odd numbers: " << oddSum << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

