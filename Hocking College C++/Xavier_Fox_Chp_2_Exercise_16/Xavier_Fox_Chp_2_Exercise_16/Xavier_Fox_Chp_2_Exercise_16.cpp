/* Program: Xavier_Fox_Chp_2_Exercise_16.cpp
   Programmer: Xavier Fox
   Date: 16 Sep. 2014
   Purpose:
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

const double CAPACITY = 3.78;
const double COST = .38;
const double PROFIT = .27;

int main()
{
	int milkProduced, milkCartons;
	double totalCost, totalProfit;

	cout << "Enter, in liters, the total quantity of milk produced: ";
	cin >> milkProduced;

	milkCartons = static_cast<int>(milkProduced / CAPACITY + .5);

	totalCost = milkProduced * COST;
	totalProfit = milkCartons * PROFIT;

	cout << showpoint << fixed << setprecision(2);
	cout << endl << "The number of milk cartons needed to hold milk: "
		 << milkCartons << endl << "The cost of producing milk: "
		 << totalCost << endl
		 << "Profit: " << totalProfit << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

