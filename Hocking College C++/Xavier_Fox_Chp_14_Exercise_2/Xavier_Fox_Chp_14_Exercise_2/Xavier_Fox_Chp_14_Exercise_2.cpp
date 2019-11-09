/* Program: Xavier_Fox_Chp_14_Exercise_2.cpp
   Programmer: Xavier Fox
   Date: 16 Mar. 2015
   Purpose: To create a simple calculator that takes
   two integers and an operator. Also handles exceptions
   such as dividing by 0 and invalid input.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

double getNum(char operators, string num);

int main()
{
	char operators, yesOrNo = 'y';
	double result, num1, num2;

	cout << setw(50) << "The Calculator Program" << endl;
	cout << setw(50) << "Program by: Xavier Fox" << endl << endl;

	while (yesOrNo == 'y')
	{
		cout << "Enter an operator:" << endl
				<< "   + (addition)" << endl
				<<	"   - (subtraction)" << endl
				<<	"   * (multiplication)" << endl
				<<	"   / (division): ";
		cin >> operators;
		cout << endl;

		num1 = getNum(operators, "first");
		num2 = getNum(operators, "second");

		switch (operators)
		{
		case '+':
			result = num1 + num2;

			cout << endl << num1 << " " << operators << " " << num2
					<< " = " << result << endl << endl;
			break;

		case '-':
			result = num1 - num2;

			cout << endl << num1 << " " << operators << " " << num2
					<< " = " << result << endl << endl;
			break;

		case '/':
			result = num1 / num2;

			cout << endl << num1 << " " << operators << " " << num2
				<< " = " << result << endl << endl;
			break;

		/* case '^':
			result = pow(num1, num2);

			cout << num1 << " " << operators << " " << num2
					<< " = " << result << endl << endl;
			break; */

		case '*':
			result = num1 * num2;

			cout << endl << num1 << " " << operators << " " << num2
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

	return 0;
}

// gets the number
double getNum(char operators, string num)
{
	double number;
	string str = "  Error: the input stream is in the fail state.";
	char done = 'n';

	cout << showpoint << fixed << setprecision(2);

	while (done != 'y')
	{
		try
		{
			cout << "Enter the " << num << " number: ";
			cin >> number;

			if (!cin)
				throw str;
			else if (num == "second" && operators == '/' && number == 0)
				throw number;

			done = 'y';
		}
		catch (double n)
		{
			cout << endl << "  You cannot have a 0 as the denominator"
					<< endl << endl;
			n = 0;
		}
		catch (string s)
		{
			cout << endl << s << endl << "  Restoring the input stream."
					<< endl << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	return number;
}