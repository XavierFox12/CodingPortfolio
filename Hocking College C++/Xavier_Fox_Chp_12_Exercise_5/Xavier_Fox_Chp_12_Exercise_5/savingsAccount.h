/* Program: savingsAccount.h
   Programmer: Xavier Fox
   Date: 17 Feb. 2015
   Purpose: gives the parameters of the savingsAccount class
*/

#ifndef savingsAccount_H
#define savingsAccount_H

#include <string>
#include "bankAccount.h"

using namespace std;

class savingsAccount: public bankAccount
{
private:
	static const double INTEREST_RATE;
	
protected:
	double interestRate;

public:
	savingsAccount(string n, int acctNum, double bal);
	savingsAccount(string n, int acctNum, double bal, double intRate);
	double getInterestRate();
	void setInterestRate(double rate);
	void postInterest();
	virtual void createMonthlyStatement();
	virtual void print();
};

#endif