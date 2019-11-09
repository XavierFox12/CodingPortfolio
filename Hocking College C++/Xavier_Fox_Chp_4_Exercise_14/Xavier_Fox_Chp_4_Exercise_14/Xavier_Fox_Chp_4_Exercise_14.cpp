/* Program:Xavier_Fox_Chp_4_Exercise_14.cpp
   Programmer: Xavier Fox
   Date: 6 Oct. 2014
   Purpose: To determine the amount due for cellular
   telephone company.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int accountNum, minutes, dayTimeMinutes, nightTimeMinutes;
	double amountDue;
	char serviceCode;

	cout << "Enter your account number or 0 to exit: ";
	cin >> accountNum;
	cout << endl;

	while (accountNum != 0)
	{

		cout << "Enter service type: (r) for regular, (p) for premium: ";
		cin >> serviceCode;
		cout << endl;

		cout << fixed << showpoint << setprecision(2);

		if (serviceCode == 'r' || serviceCode == 'R')
		{
			cout << "Enter the number of minutes used: ";
			cin >> minutes;
			cout << endl;
			amountDue = 10;

			if (minutes > 50)
				amountDue += (minutes - 50) * .2;

			cout << "Account Number: " << accountNum << endl
				 << "Service Type: Regular" << endl
				 << "Minutes used: " << minutes << endl
				 << "Amount Due: $" << amountDue << endl << endl;
		}

		else if (serviceCode == 'p' || serviceCode == 'P')
		{
			cout << "Enter the number of day time minutes: ";
			cin >> dayTimeMinutes;
			cout << "Enter the number of night time minutes: ";
			cin >> nightTimeMinutes;
			cout << endl;

			amountDue = 25;

			if (dayTimeMinutes > 75)
				amountDue += (dayTimeMinutes - 75) * .1;

			if (nightTimeMinutes > 100)
				amountDue += (nightTimeMinutes - 100) * .05;
		
			cout << "Account Number: " << accountNum << endl
				 << "Service Type: Premium" << endl
				 << "Minutes used (Day): " << dayTimeMinutes << endl
				 << "Minutes used (Night): " << nightTimeMinutes << endl
				 << "Amount Due: $" << amountDue << endl << endl;
		}

		else
		{
			cout << serviceCode << " is not a valid service type"
				 << endl << endl;
		}

		cout << "Enter your account number or 0 to exit: ";
		cin >> accountNum;
		cout << endl;
	}

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

