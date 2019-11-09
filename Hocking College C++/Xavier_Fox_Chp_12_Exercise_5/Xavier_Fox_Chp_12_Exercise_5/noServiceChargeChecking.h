/* Program: noServiceChargeChecking.h
   Programmer: Xavier Fox
   Date: 18 Feb. 2015
   Purpose:
*/

#ifndef noServiceChargeChecking_H
#define noServiceChargeChecking_H

#include <string>
#include "checkingAccount.h"

using namespace std;

class noServiceChargeChecking: public checkingAccount
{
public:
	noServiceChargeChecking(string n, int acctNum, double bal);
	noServiceChargeChecking(string n, int acctNum, double bal, double minBalance,
							double intRate);
	double getMinimumBalance();
	void setMinimumBalance(double minBalance);
	bool verifyMinimumBalance(double amount);
	void writeCheck(double amount);
	void withdraw(double amount);
	virtual void createMonthlyStatement();
	virtual void print();

protected:
	double minimumBalance;
	double interestRate;

private:
	static const double MIN_BALANCE;
	static const double INTEREST_RATE;
};

#endif