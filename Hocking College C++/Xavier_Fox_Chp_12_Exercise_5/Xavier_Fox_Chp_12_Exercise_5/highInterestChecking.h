/* Program: highInterestChecking.h
   Programmer: Xavier Fox
   Date: 18 Feb. 2015
   Purpose: gives the parameters of the highInterestChecking
   class.
*/

#ifndef highInterestChecking_H
#define highInterestChecking_H

#include "noServiceChargeChecking.h"
#include <string>

using namespace std;

class highInterestChecking: public noServiceChargeChecking
{
public:
	highInterestChecking(string n, int acctNum, double bal);
	highInterestChecking(string n, int acctNum, double bal, double minBal, 
						 double intRate);
	double getInterestRate();
	void setInterestRate(double intRate);
	void postInterestRate();
	virtual void createMonthlyStatement();
	virtual void print();

private:
	static const double INTEREST_RATE;
	static const double MIN_BAL;
};

#endif