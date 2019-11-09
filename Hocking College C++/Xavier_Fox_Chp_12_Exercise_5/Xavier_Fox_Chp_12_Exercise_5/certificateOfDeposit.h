/* Program: certificateOfDeposit.h
   Programmer: Xavier Fox
   Date: 20 Feb. 2015
   Purpose: Gives the parameters of the 
   certificateOfDeposit class.
*/

#ifndef certificateOfDeposit_H
#define certificateOfDeposit_H

#include "bankAccount.h"
#include <string>

using namespace std;

class certificateOfDeposit:public bankAccount
{
public:
	certificateOfDeposit(string n, int acctNum, double bal);
	certificateOfDeposit(string n, int acctNum, double bal, double intRate,
						 int maturityMon);
	double getInterestRate();
	void setInterestRate(double intRate);
	double getCurrentCDMonth();
	void setCurrentCDMonth(int month);
	double getMaturityMonth();
	void setMaturityMonth(int month);
	void postInterest();
	void withdraw(double amount);
	void withdraw();
	void createMonthlyStatement();
	void print();

private:
	static const double INTEREST_RATE;
	static const int NUMBER_OF_MATURITY_MONTHS;

	double interestRate;
	int maturityMonth;

	int cdMonth;
};

#endif