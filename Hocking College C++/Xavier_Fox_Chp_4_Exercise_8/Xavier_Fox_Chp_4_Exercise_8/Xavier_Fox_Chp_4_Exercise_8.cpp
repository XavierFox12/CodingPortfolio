/* Xavier_Fox_Chp_4_Exercise_8.cpp
   Programmer: Xavier Fox
   Date: 6 Oct. 2014
   Purpose: To create a simple calculator that takes
   two integers and an operator.
*/

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	char operators, yesOrNo = 'y';
	int num1, num2, result;

	while (yesOrNo == 'y')
	{
		cout << "Enter the equation with two integers and "
			 << "an operator (+, -, /, *, ^): ";
		cin >> num1 >> operators >> num2;
		cout << endl;

		switch (operators)
		{
		case '+':
			result = num1 + num2;

			cout << num1 << " " << operators << " " << num2
				 << " = " << result << endl << endl;
			break;

		case '-':
			result = num1 - num2;

			cout << num1 << " " << operators << " " << num2
				 << " = " << result << endl << endl;
			break;

		case '/':
			if (num2 == 0)
			{
				cout << "You cannot have a 0 as the denominator"
					 << endl << endl;
			}

			else
			{
				result = num1 / num2;

				cout << num1 << " " << operators << " " << num2
				 << " = " << result << endl << endl;
			}
			break;

		case '^':
			result = pow(num1, num2);

			cout << num1 << " " << operators << " " << num2
				 << " = " << result << endl << endl;
			break;

		case '*':
			result = num1 * num2;

			cout << num1 << " " << operators << " " << num2
				 << " = " << result << endl << endl;
			break;

		default:
			cout << operators << " is not an acceptable operator."
				 << endl << endl;
		}
		cout << "Do you wish to continue? (y/n) ";
		cin >> yesOrNo;
		cout << endl;
	}

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

