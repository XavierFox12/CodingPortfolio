/* Program: checkingAccountImp.cpp
   Programmer: Xavier Fox
   Date: 18 Feb. 2015
   Purpose: defines the checkingAccount class
*/

#include "stdafx.h"
#include "checkingAccount.h"
#include <string>
#include <iostream>

using namespace std;

// constructor
checkingAccount::checkingAccount(string n, int acctNum, double bal)
				:bankAccount(n, acctNum, bal)
{
}
