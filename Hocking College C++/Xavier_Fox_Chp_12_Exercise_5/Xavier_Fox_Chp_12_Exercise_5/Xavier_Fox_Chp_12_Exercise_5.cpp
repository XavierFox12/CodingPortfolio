/* Program: Xavier_Fox_Chp_12_Exercise_5.cpp
   Programmer: Xavier Fox
   Date: 16 Feb. 2015
   Purpose: Prints the customers bill depending on
   their account.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "bankAccount.h"
#include "savingsAccount.h"
#include "highInterestSavings.h"
#include "serviceChargeChecking.h"
#include "noServiceChargeChecking.h"
#include "highInterestChecking.h"
#include "certificateOfDeposit.h"

using namespace std;

int main()
{
	bankAccount *accountsList[6];

	accountsList[0] = new savingsAccount("Bill", 10200, 2500);
	accountsList[1] = new highInterestSavings("Susan", 10210, 2000);
	accountsList[2] = new noServiceChargeChecking("John", 20100, 3500);
	accountsList[3] = new serviceChargeChecking("Ravi", 30100, 1800);
	accountsList[4] = new highInterestChecking("Sheila", 20200, 6000);
	accountsList[5] = new certificateOfDeposit ("Hamid", 51001, 18000, 0.075, 18); 
	
	cout << "January:" << endl
		 << "--------------" << endl;
	for (int i=0; i < 6; i++)
	{
		accountsList[i]->createMonthlyStatement();
		accountsList[i]->print();

		cout << endl;
	}

	cout << endl << "February:" << endl
		 << "--------------" << endl;
	for (int i=0; i < 6; i++)
	{
		accountsList[i]->createMonthlyStatement();
		accountsList[i]->print();

		cout << endl;
	}

	for (int i=0; i < 6; i++)
		accountsList[i]->withdraw(500);

	cout << endl << "March:" << endl
		 << "--------------" << endl;
	for (int i=0; i < 6; i++)
	{
		accountsList[i]->createMonthlyStatement();
		accountsList[i]->print();

		cout << endl;
	}

	cout << endl << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

