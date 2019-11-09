/* Program: Xavier_Fox_Chp_4_Exercise_2.cpp
   Programmer:Xavier Fox
   Date: 29 Sep. 2014
   Purpose: To list three numbers in acending order.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int num1, num2, num3;

	cout << "Enter three numbers: ";
	cin >> num1 >> num2 >> num3;
	cout << endl;

	if (num1 < num2 && num1 < num3)
	{
		cout << "the numbers in acending order are: " << num1
			 << " ";
		if (num2 < num3)
		{
			cout << num2 << " " << num3;
		}
		else
		{
			cout << num3 << " " << num2;
		}
	}

	if (num2 < num1 && num2 < num3)
	{
		cout << "the numbers in acending order are: " << num2
			 << " ";
		if (num1 < num3)
		{
			cout << num1 << " " << num3;
		}
		else
		{
			cout << num3 << " " << num1;
		}
	}

	if (num3 < num1 && num3 < num2)
	{
		cout << "the numbers in acending order are: " << num3
			 << " ";
		if ( num1 < num2)
		{
			cout << num1 << " " << num2;
		}
		else
		{
			cout << num2 << " " << num1;
		}
	}

	cout << endl << endl <<"Program by: Xavier Fox"
		 << endl << endl;

	return 0;
}

