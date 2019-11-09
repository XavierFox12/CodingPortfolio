/* Program: serviceChargeChecking.h
   Programmer: Xavier Fox
   Date: 18 Feb. 2015
   Purpose: gives the parameters of the serviceChargeChecking
   class
*/

#ifndef serviceChargeChecking_H
#define serviceChargeChecking_H

#include <string>
#include "checkingAccount.h"

using namespace std;

class serviceChargeChecking: public checkingAccount
{
public:
	serviceChargeChecking(string n, int acctNum, double bal);
	serviceChargeChecking(string n, int acctNum, double bal, double servChargeAmount,
						  double servChargeCheck);
	double getServiceChargeAmount();
	void setServiceCharge(double amount);
	double getServiceChargeCheck();
	void setServiceChargeCheck(double amount);
	int getNumberOfChecksWritten();
	void setNumberOfChecksWritten(int num);
	void postServiceCharge();
	void writeCheck(double amount);
	virtual void createMonthlyStatement();
	virtual void print();
	
protected:
	double serviceChargeAmount;
	double serviceChargeCheck;
	int numberOfChecksWritten;

private:
	static const double ACCOUNT_SERVICE_CHARGE;
	static const int MAXIMUM_NUM_OF_CHECKS;
	static const double SERVICE_CHARGE_EXCESS_NUM_OF_CHECKS;
};

#endif