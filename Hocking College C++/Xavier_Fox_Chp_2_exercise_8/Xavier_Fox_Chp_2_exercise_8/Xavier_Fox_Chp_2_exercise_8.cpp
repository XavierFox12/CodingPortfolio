/* Program: Xavier_Fox_Chp_2_exercise_8.cpp
   Programmer: Xavier Fox
   Date: 11 Sep. 2014
   Purpose: To determine the overall wages are 
   given their name and hours worked.
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int SECRET = 11;
const double RATE = 12.50;

int main()
{
	int num1, num2, newNum;
	string name;
	double hoursWorked, wages;

	cout << "Enter two integers separated by a space: ";
	cin >> num1 >> num2;
	cout << endl;

	cout << "The value of num1 = " << num1
		 << " and the value of num2 = " << num2
		 << endl;

	newNum = num1 * 2 + num2;

	cout << "The value of newNum = " << newNum
		 << endl;

	newNum += SECRET;

	cout << "The new value of newNum = " << newNum
		 << endl;

	cout << "Enter last name: ";
	cin >> name;
	cout << endl;

	cout << "Enter a decimal number between 0 and 70: ";
	cin >> hoursWorked;
	cout << endl;

	wages = hoursWorked * RATE;

	cout << showpoint << fixed << setprecision(2);
	cout << "Name: " << name << endl
		<< "Pay Rate: $" << RATE << endl
		<< "Hours Worked: "<< hoursWorked << endl
		 << "Salary: $" << wages << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

