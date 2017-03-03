/* Program: savingsAccountImp.cpp
   Programmer: Xavier Fox
   Date: 17 Feb. 2015
   Purpose: defines the savingsAccount class
*/

#include "stdafx.h"
#include "savingsAccount.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const double savingsAccount::INTEREST_RATE=0.03;

// constructor
savingsAccount::savingsAccount(string n, int acctNum, double bal)
			   :bankAccount(n, acctNum, bal)
{
	interestRate = INTEREST_RATE;
}

// constructor
savingsAccount::savingsAccount(string n, int acctNum, double bal, double intRate)
			   :bankAccount(n, acctNum, bal)
{
	setInterestRate(intRate);
}

// gets the interest rate
double savingsAccount::getInterestRate()
{
	return interestRate;
}

// sets the interest rate
void savingsAccount::setInterestRate(double rate)
{
	interestRate = rate;
}

// adding the interest to the balance
void savingsAccount::postInterest()
{
	balance += balance * interestRate;
}

// creates the monthly statement
void savingsAccount::createMonthlyStatement()
{
	postInterest();
}

// prints the savings account
void savingsAccount::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << left << setw(29) << "Savings account:" << setw(12) << getName()
		 << "ACCT# " << setw(8) << getAccountNumber() << setw(11) << "Balance: $"
		 << right << setw(9) << getBalance();
}