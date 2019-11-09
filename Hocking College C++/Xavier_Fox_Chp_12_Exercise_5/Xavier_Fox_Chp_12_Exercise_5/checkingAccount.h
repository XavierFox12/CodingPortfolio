/* Program: checkingAccount.h
   Programmer: Xavier Fox
   Date: 18 Feb. 2015
   Purpose: gives the parameters of the checking account class
*/

#ifndef checkingAccount_H
#define checkingAccount_H

#include <string>
#include "bankAccount.h"

using namespace std;

class checkingAccount: public bankAccount
{
public:
	checkingAccount(string n, int acctNum, double bal);
	virtual void writeCheck(double amount) = 0;
};

#endif