/* Program: Xavier_Fox_Chp_5_Exercise_20.cpp
   Programmer: Xavier Fox
   Date: 23 Oct. 2014
   Purpose: Determines how many months it will take
   to pay off a loan.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

const int MONTHS = 12;
int main()
{
	double loanAmount, interestRatePerYear, monthlyPayment,
		   interestRatePerMonth, nextPayment, interest;
	int overallMonths = 0;

	cout << "Enter the loan amount: ";
	cin >> loanAmount;
	cout << endl;

	cout << "Enter the interest rate per year: ";
	cin >> interestRatePerYear;
	cout << endl;

	cout << "Enter the monthly payment: ";
	cin >> monthlyPayment;
	cout << endl;

	while (loanAmount >= 0)
	{
		interestRatePerMonth = interestRatePerYear / MONTHS;

		interest = loanAmount * (interestRatePerMonth / 100);

		nextPayment = monthlyPayment - interest;

		loanAmount = loanAmount - nextPayment;
		++overallMonths;

		if (monthlyPayment < interest)
		{
			cout << "The monthly payment is too low. The loan cannot be repaid"
				 << endl << endl;

			cout << "Program by: Xavier Fox" << endl << endl;
			return 1;
		}
	}

	cout << "It will take " << overallMonths << " months to repay the loan"
		 << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

