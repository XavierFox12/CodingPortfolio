/* Program: Xavier_Fox_Chp_6_Exercise_12.cpp
   Programmer: Xavier Fox
   Date: 11 Nov. 2014
   Purpose: To determines the users billing amount by
   determining if they have low income.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

double billingAmount(double hourlyRate, double consultingTime, bool lowIncome);

int main()
{
	double yearlyIncome, consultingTime;
	int hourlyRate;
	char yesOrNo = 'y';
	bool lowIncome;

	while (yesOrNo == 'y')
	{
		cout << "Enter yearly income: ";
		cin >> yearlyIncome;
		cout << endl;

		cout << "Enter the hourly rate: ";
		cin >> hourlyRate;
		cout << endl;

		cout << "Enter consulting time in minutes: ";
		cin >> consultingTime;
		cout << endl;

		if (yearlyIncome <= 25000)
			lowIncome = true;
		else
			lowIncome = false;

		billingAmount(hourlyRate, consultingTime, lowIncome);

		cout << "Is there another client? (y/n) ";
		cin >> yesOrNo;
		cout << endl;
	}
	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

double billingAmount(double hourlyRate, double consultingTime, bool lowIncome) 
{
	double billingAmount;

	cout << fixed << showpoint << setprecision(2);

	if (lowIncome)
		if (consultingTime <= 30)
			billingAmount = 0;
		else 
			billingAmount = (consultingTime - 30) * .4 * (hourlyRate/60);
	else
		if (consultingTime <= 20)
			billingAmount = 0;
		else
			billingAmount = (consultingTime - 20) * .7* (hourlyRate/60);

	cout << "The billing amount is: $" << billingAmount
		 << endl << endl;
	return (billingAmount);
}

