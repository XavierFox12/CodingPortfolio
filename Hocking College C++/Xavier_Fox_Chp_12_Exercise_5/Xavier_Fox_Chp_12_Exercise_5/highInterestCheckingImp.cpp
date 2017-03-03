/* Program: highInterestCheckingImp.cpp
   Programmer: Xavier Fox
   Date: 18 Feb. 2015
   Purpose: defines the parameters of the
   highInterestChecking class.
*/

#include "stdafx.h"
#include "highInterestChecking.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

const double highInterestChecking::INTEREST_RATE = 0.05;
const double highInterestChecking::MIN_BAL = 5000;

// constructor
highInterestChecking::highInterestChecking(string n, int acctNum, double bal)
					:noServiceChargeChecking(n, acctNum, bal)
{
	minimumBalance = MIN_BAL;
	interestRate = INTEREST_RATE;
}

// constructor
highInterestChecking::highInterestChecking(string n, int acctNum, double bal,
										   double minBal, double intRate)
					:noServiceChargeChecking(n, acctNum, bal, minBal, intRate)
{
}

// gets the interest rate
double highInterestChecking::getInterestRate()
{
	return interestRate;
}

// sets the interest rate
void highInterestChecking::setInterestRate(double intRate)
{
	interestRate = intRate;
}

// accounts for the post interest rate
void highInterestChecking::postInterestRate()
{
	balance += (balance * interestRate);
}

// creates the monthly statement
void highInterestChecking::createMonthlyStatement()
{
	postInterestRate();
}

// prints the high interest checking
void highInterestChecking::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << left << setw(29) << "High Interest Checking:" << setw(12) << getName()
		 << "ACCT# " << setw(8) << getAccountNumber() << setw(11) << "Balance: $"
		 << right << setw(9) << getBalance();
}