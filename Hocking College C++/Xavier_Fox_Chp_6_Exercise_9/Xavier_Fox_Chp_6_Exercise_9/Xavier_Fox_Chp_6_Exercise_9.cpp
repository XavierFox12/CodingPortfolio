/* Program: Xavier_Fox_Chp_6_Exercise_9.cpp
   Programmer: Xavier Fox
   Date: 30 Oct. 2014
   Purpose: Same program as Chapter 4 exercise 14,
   but now it uses functions.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

int regularBill(int number);
int premiumBill(int number);

int main()
{
	int accountNum;
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
			regularBill(accountNum);
		}

		else if (serviceCode == 'p' || serviceCode == 'P')
		{
			premiumBill(accountNum);
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

int regularBill(int number) 
{
	double amountDue;
	int minutes;

	cout << "Enter the number of minutes used: ";
	cin >> minutes;
	cout << endl;
	amountDue = 10;

	if (minutes > 50)
		amountDue += (minutes - 50) * .2;

	cout << "Account Number: " << number << endl
		 << "Service Type: Regular" << endl
		 << "Minutes used: " << minutes << endl
		 << "Amount Due: $" << amountDue << endl << endl;
	return number;
}

int premiumBill(int number)
{
	double amountDue;
	int dayTimeMinutes, nightTimeMinutes;

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
		
	cout << "Account Number: " << number << endl
		 << "Service Type: Premium" << endl
		 << "Minutes used (Day): " << dayTimeMinutes << endl
		 << "Minutes used (Night): " << nightTimeMinutes << endl
		 << "Amount Due: $" << amountDue << endl << endl;
	return number;
}
