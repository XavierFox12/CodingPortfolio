/* Program: Xavier_Fox_Chp_14_Exercise_1.cpp
   Programmer: Xavier Fox
   Date: 16 Mar. 2015
   Purpose: To convert feet and inches into
   centimeters.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double getLength();

int main()
{
	double feet, inches, centimeters;
	char yesOrNo = 'y';

	cout << setw(60) << "Converting Feet and Inches to Centimeters" << endl;
	cout << setw(60) << "         Program by: Xavier Fox          " << endl << endl;

	while (yesOrNo == 'y')
	{
		cout << "Feet: ";
		feet = getLength();

		centimeters = feet * 12;

		cout << "Inches: ";
		inches = getLength();

		centimeters = (centimeters + inches) * 2.54;

		cout << showpoint << fixed << setprecision(2);

		cout << "Centimeters: " << centimeters << endl << endl;

		cout << "Do you have another conversion (y/n)? ";
		cin >> yesOrNo;
		cout << endl;
	}

	return 0;
}

// Gets the length
double getLength()
{
	double number = 0;
	char done = 'n';
	string str = "  Error: the input stream is in the fail state.";

	do
	{
		try
		{
			cout << "Enter a nonnegative number: ";
			cin >> number;
			cout << endl;

			if (number < 0)
				throw number;
			else if (!cin)
				throw str;
			done = 'y';
		}
		catch (double)
		{
			cout << "  Error: a negative number is entered" << endl << endl;
			number = 0;
		}
		catch (string s)
		{
			cout << s << endl << "  Restoring the input stream." << endl << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (done != 'y');

	return number;
}

