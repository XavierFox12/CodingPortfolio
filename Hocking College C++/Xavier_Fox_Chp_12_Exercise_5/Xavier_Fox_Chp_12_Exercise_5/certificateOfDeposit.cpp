/* Program: certificateOfDeposit.cpp
   Programmer: Xavier Fox
   Date: 20 Feb. 2015
   Purpose: Defines the certificateOfDeposit class
*/

#include "stdafx.h"
#include "certificateOfDeposit.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

const double certificateOfDeposit::INTEREST_RATE = 0.05;
const int certificateOfDeposit::NUMBER_OF_MATURITY_MONTHS = 6;

// constructor
certificateOfDeposit::certificateOfDeposit(string n, int acctNum, double bal)
					:bankAccount(n, acctNum, bal)
{
	interestRate = INTEREST_RATE;
	maturityMonth = NUMBER_OF_MATURITY_MONTHS;
	cdMonth = 0;
}

// constructor
certificateOfDeposit::certificateOfDeposit(string n, int acctNum, double bal,
										   double intRate, int maturityMon)
					 :bankAccount(n, acctNum, bal)
{
	interestRate = intRate;
	maturityMonth = maturityMon;
	cdMonth = 0;
}

// gets the interest rate
double certificateOfDeposit::getInterestRate()
{
	return interestRate;
}

// sets the interest rate
void certificateOfDeposit::setInterestRate(double intRate)
{
	interestRate = intRate;
}

// gets the current CD month
double certificateOfDeposit::getCurrentCDMonth()
{
	return cdMonth;
}

// sets the current CD month
void certificateOfDeposit::setCurrentCDMonth(int month)
{
	cdMonth = month;
}

// gets the maturity month
double certificateOfDeposit::getMaturityMonth()
{
	return maturityMonth;
}

// sets the maturity month
void certificateOfDeposit::setMaturityMonth(int month)
{
	maturityMonth = month;
}

// accounts for the post interest
void certificateOfDeposit::postInterest()
{
	balance += (balance * interestRate);
}

void certificateOfDeposit::withdraw(double amount)
{
	// no withdrawl until maturity
}

// accounts for the withdrawl
void certificateOfDeposit::withdraw()
{
	if (cdMonth > maturityMonth)
		balance = 0;
	else
		cout << "CD has not been matured. No withdrawal." << endl;
}

// creates the monthly statement
void certificateOfDeposit::createMonthlyStatement()
{
	postInterest();
}

// prints the certificate of deposit account
void certificateOfDeposit::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << left << setw(29) << "Certificate Of Deposit:" << setw(12) << getName()
		 << "ACCT# " << setw(8) << getAccountNumber() << setw(11) << "Balance: $"
		 << right << setw(9) << getBalance();
}