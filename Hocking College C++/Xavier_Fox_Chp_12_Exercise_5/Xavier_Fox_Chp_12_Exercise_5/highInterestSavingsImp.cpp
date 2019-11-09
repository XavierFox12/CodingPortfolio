/* Program: highInterestSavingsImp.cpp
   Programmer: Xavier Fox
   Date: 17 Feb. 2015
   Purpose: defines the highInterestSavings
   class.
*/

#include "stdafx.h"
#include "highInterestSavings.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

const double highInterestSavings::MINIMUM_BALANCE = 2500.00;
const double highInterestSavings::INTEREST_RATE = 0.05;

// constructor
highInterestSavings::highInterestSavings(string n, int acctNum, double bal)
					: savingsAccount(n, acctNum, bal, INTEREST_RATE)
{
	minimumBalance = MINIMUM_BALANCE;
}

// constructor
highInterestSavings::highInterestSavings(string n, int acctNum, double bal,
										 double intRate, double minBal)
					:savingsAccount(n, acctNum, bal, intRate)
{
	minimumBalance = minBal;
}

// gets the minimum balance
double highInterestSavings::getMinimumBalance()
{
	return minimumBalance;
}

// verifies the minimum balance
bool highInterestSavings::verifyMinimumBalance(double amount)
{
	return (balance - amount >= minimumBalance);
}

// accounts for a withdraw
void highInterestSavings::withdraw(double amount)
{
	if (verifyMinimumBalance(amount))
		balance -= amount;
}

// prints the high interest savings account
void highInterestSavings::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << left << setw(29) << "High Interest Savings:" << setw(12) << getName()
		 << "ACCT# " << setw(8) << getAccountNumber() << setw(11) << "Balance: $"
		 << right << setw(9) << getBalance();
}