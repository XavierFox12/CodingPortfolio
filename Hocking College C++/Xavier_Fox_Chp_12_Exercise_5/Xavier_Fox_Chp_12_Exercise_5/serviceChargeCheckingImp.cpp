/* Program: serviceChargeCheckingImp.cpp
   Programmer: Xavier Fox
   Date: 18 Feb. 2015
   Purpose: defines the serviceChargeChecking class
*/

#include "stdafx.h"
#include "serviceChargeChecking.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

const double serviceChargeChecking:: ACCOUNT_SERVICE_CHARGE = 10.00;
const int serviceChargeChecking:: MAXIMUM_NUM_OF_CHECKS = 5;
const double serviceChargeChecking:: SERVICE_CHARGE_EXCESS_NUM_OF_CHECKS = 5.00;

// constructor
serviceChargeChecking::serviceChargeChecking(string n, int acctNum, double bal)
					  :checkingAccount(n, acctNum, bal)
{
	serviceChargeAmount = ACCOUNT_SERVICE_CHARGE;
	numberOfChecksWritten = 0;
	serviceChargeCheck = 0.0;
}

// constructor
serviceChargeChecking::serviceChargeChecking(string n, int acctNum, double bal,
											 double servChargeAmount,
											 double servChargeCheck)
					  :checkingAccount(n, acctNum, bal)
{
	serviceChargeAmount = servChargeAmount;
	numberOfChecksWritten = 0;
	serviceChargeCheck = servChargeCheck;
}

// gets the service charge amount
double serviceChargeChecking::getServiceChargeAmount()
{
	return serviceChargeAmount;
}

// sets the service charge amount
void serviceChargeChecking::setServiceCharge(double amount)
{
	serviceChargeAmount = amount;
}

// gets the service charge check
double serviceChargeChecking::getServiceChargeCheck()
{
	return serviceChargeCheck;
}

// sets the service charge check
void serviceChargeChecking::setServiceChargeCheck(double amount)
{
	serviceChargeCheck = amount;
}

// gets the number of checks written
int serviceChargeChecking::getNumberOfChecksWritten()
{
	return numberOfChecksWritten;
}

// sets the number of checks written
void serviceChargeChecking::setNumberOfChecksWritten(int num)
{
	numberOfChecksWritten = num;
}

// accounts for the post service charge
void serviceChargeChecking::postServiceCharge()
{
	balance -= serviceChargeAmount;
}

// takes the amount of checks written away from the blance
void serviceChargeChecking::writeCheck(double amount)
{
	if (numberOfChecksWritten < MAXIMUM_NUM_OF_CHECKS)
		balance -= amount;
	else
		balance = balance - amount - serviceChargeCheck;

	numberOfChecksWritten++;
}

// creates the monthly statement
void serviceChargeChecking::createMonthlyStatement()
{
	postServiceCharge();
}

// prints the service charge checking
void serviceChargeChecking::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << left << setw(29) << "Service Charge Checking:" << setw(12) << getName()
		 << "ACCT# " << setw(8) << getAccountNumber() << setw(11) << "Balance: $"
		 << right << setw(9) << getBalance();
}