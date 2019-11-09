/* Program: bankAccountImp.cpp
   Programmer: Xavier Fox
   Date: 17 Feb. 2015
   Purpose: defines the bankAccount class
*/

#include "stdafx.h"
#include "bankAccount.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// constructor
bankAccount::bankAccount(string n, int acctNum, double bal)
{
	name = n;
	accountNumber = acctNum;
	balance = bal;
}


// gets the account number
int bankAccount::getAccountNumber()
{
	return accountNumber;
}

// gets the balance
double bankAccount::getBalance()
{
	return balance;
}

// gets the name
string bankAccount::getName()
{
	return name;
}


// sets the name
void bankAccount::setName(string n)
{
	name = n;
}

// takes away the withdraw amount
void bankAccount::withdraw(double amount)
{
	balance -= amount;
}

// adds the deposit amount
void bankAccount::deposit(double amount)
{
	balance += amount;
}

// prints the name, account number and balance
void bankAccount::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << name << " " << accountNumber << " balance: $"
		 << setw(9) << balance;
}