/* Program: Xavier_Fox_Chp_1_Exercise_20.cpp
   Programmer: Xavier Fox
   Date: 2 Sep. 2014
   Purpose: To determine the billing amount for the yard,
   fertilizing, trees, and the total billing amount.
*/

#include "stdafx.h"

#include <iostream>

#include <iomanip>

using namespace std;

int main()
{
	int applications, treesPlanted;
	double areaOfYard, mowingBill, fertilizingBill,
		   treeBill, billTotal;

	cout << "Enter the area of the yard: ";
	cin >> areaOfYard;

	cout << "Enter the number of fertilizing applications: ";
	cin >> applications;

	cout << "Enter the number of trees to be planted: ";
	cin >> treesPlanted;

	mowingBill = areaOfYard / 5000 * 35;

	fertilizingBill = applications * 30;

	treeBill = treesPlanted * 50;

	billTotal = mowingBill + fertilizingBill + treeBill;

	cout << showpoint << fixed << setprecision(2);

	cout << endl
		 << "Customer Bill:" << endl
		 << "     Mowing:      " << setw(6) << mowingBill << endl
		 << "     Fertilizing: " << setw(6) << fertilizingBill << endl
		 << "     Tree(s):     " << setw(6) << treeBill << endl << endl
		 << "     Total:      $" << setw(6) << billTotal << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;
	return 0;
}

