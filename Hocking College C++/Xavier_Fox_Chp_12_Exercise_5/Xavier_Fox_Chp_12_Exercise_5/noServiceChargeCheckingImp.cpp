/* Program: noServiceChargeCheckingImp.h
   Programmer: Xavier Fox
   Date: 18 Feb. 2015
   Purpose: defines the noServiceChargeChecking
   class
*/

#include "stdafx.h"
#include "noServiceChargeChecking.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

const double noServiceChargeChecking:: MIN_BALANCE = 1000.00;
const double noServiceChargeChecking:: INTEREST_RATE = 0.02;

// constructor
noServiceChargeChecking::noServiceChargeChecking(string n, int acctNum, double bal)
						:checkingAccount(n, acctNum, bal)
{
	minimumBalance = MIN_BALANCE;
	interestRate = INTEREST_RATE;
}

// constructor
noServiceChargeChecking::noServiceChargeChecking(string n, int acctNum, double bal,
												 double minBalance, double intRate)
						:checkingAccount(n, acctNum, bal)
{
	minimumBalance = minBalance;
	interestRate = intRate;
}

// gets the minimum balance
double noServiceChargeChecking::getMinimumBalance()
{
	return minimumBalance;
}

// sets the minimum balance
void noServiceChargeChecking::setMinimumBalance(double minBalance)
{
	minimumBalance = minBalance;
}

// verifies the minimum balance
bool noServiceChargeChecking::verifyMinimumBalance(double amount)
{
	return (balance - amount >= minimumBalance);
}

// takes away the amount from balance from the check
void noServiceChargeChecking::writeCheck(double amount)
{
	if (verifyMinimumBalance(amount))
		balance -= amount;
}

// accounts for a withdraw
void noServiceChargeChecking::withdraw(double amount)
{
	if (verifyMinimumBalance(amount))
		balance -= amount;
}

// creates a monthly statement
void noServiceChargeChecking::createMonthlyStatement()
{
}

// prints the no service charge checking
void noServiceChargeChecking::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << left << setw(29) << "No Service Charge Checking:" << setw(12) << getName()
		 << "ACCT# " << setw(8) << getAccountNumber() << setw(11) << "Balance: $"
		 << right << setw(9) << getBalance();
}