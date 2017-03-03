/* Program: Xavier_Fox_Chp_2_Exercsise_18.cpp
   Programmer: Xavier Fox
   Date: 18 Sep. 2014
   Purpose: To determine how much money you have earned in
   five weeks and how much money goes in to paying for
   clothes, school supplies, savings bonds, and additional
   savingsbonds.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

const double TAX = .14;
const double ACCESSORIES = .1;
const double SCHOOL = .01;
const double BONDS = .25;
const double ADDITIONALBONDS = .5;
int main()
{
	double payPerHour, week1, week2, week3, week4,
		   week5, beforeTaxes, netIncome, clothesAndAccessories,
		   schoolSupplies, savingsBonds, additionalSavingsBonds;

	cout << "Enter the per hour pay rate: ";
	cin >> payPerHour;
	cout << endl;

	cout << "Enter the number of hours worked for week 1: ";
	cin >> week1;
	cout << endl;

	cout << "Enter the number of hours worked for week 2: ";
	cin >> week2;
	cout << endl;

	cout << "Enter the number of hours worked for week 3: ";
	cin >> week3;
	cout << endl;

	cout << "Enter the number of hours worked for week 4: ";
	cin >> week4;
	cout << endl;

	cout << "Enter the number of hours worked for week 5: ";
	cin >> week5;
	cout << endl;

	beforeTaxes = payPerHour * (week1 + week2 + week3 + week4 +
								week5);

	netIncome = beforeTaxes - (beforeTaxes * TAX);

	clothesAndAccessories = netIncome * ACCESSORIES;

	schoolSupplies = netIncome * SCHOOL;

	savingsBonds = (netIncome - clothesAndAccessories - schoolSupplies) *
					BONDS;

	additionalSavingsBonds = savingsBonds * ADDITIONALBONDS;

	cout << showpoint << fixed << setprecision(2);

	cout << "Total Income before taxes: $" << beforeTaxes
		 << endl << "Net Income: $" << netIncome << endl
		 << "Money spent on clothes and other accessories: $"
		 << clothesAndAccessories << endl
		 << "Money spent on school supplies: $" << schoolSupplies
		 << endl << "Money spent on savings bonds: $" << savingsBonds
		 << endl << "Money spent by parents on additional savings bonds: $"
		 << additionalSavingsBonds << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

