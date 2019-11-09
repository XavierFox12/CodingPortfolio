/* Program: highInterestSavings.h
   Programmer: Xavier Fox
   Date: 17 Feb. 2015
   Purpose: gives the parameters of the highInteresSavings
   class
*/

#ifndef highInterestSavings_H
#define highInterestSavings_H

#include <string>
#include "savingsAccount.h"

using namespace std;

class highInterestSavings: public savingsAccount
{
private:
	static const double MINIMUM_BALANCE;
	static const double INTEREST_RATE;

protected:
	double minimumBalance;

public:
	highInterestSavings(string n, int acctNum, double bal);
	highInterestSavings(string n, int acctNum, double bal, double intRate,
						double minBalance);
	double getMinimumBalance();
	bool verifyMinimumBalance(double amount);
	virtual void withdraw(double amount);
	virtual void print();
};

#endif