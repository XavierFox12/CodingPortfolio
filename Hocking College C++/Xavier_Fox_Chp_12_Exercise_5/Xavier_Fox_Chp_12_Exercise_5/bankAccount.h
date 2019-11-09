/* Program: bankAccount.h
   Programmer: Xavier Fox
   Date: 17 Feb. 2015
   Purpose: gives the parameters of the bankAccount class
*/

#ifndef bankAccount_H
#define bankAccount_H

#include <string>

using namespace std;

class bankAccount
{
protected:
	int accountNumber;
	string name;
	double balance;

public:
	bankAccount(string n="", int acctNum=0, double bal=0.0);
	int getAccountNumber();
	double getBalance();
	string getName();
	void setName(string n);
	virtual void withdraw(double amount);
	void deposit(double amount);
	virtual void createMonthlyStatement() = 0;
	virtual void print();
};

#endif