/* Program: Xavier_Fox_Sales_Figures.cpp
   Programmer: Xavier Fox
   Date: 11 Feb. 2015
   Purpose: Determines the total and average sales
   figures for any day number of days.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double *saleFigures;
	double total = 0;
	int numOfDays;

	cout << "How many days of sales figures do you wish to process? ";
	cin >> numOfDays;
	cout << endl;

	saleFigures = new double[numOfDays];

	cout << "Enter the sale figures below." << endl;
	for (int i = 0; i < numOfDays; i++)
	{
		cout << "   Day " << i + 1 << ": ";
		cin >> saleFigures[i];
		total += saleFigures[i];
	}
	
	cout << fixed << showpoint << setprecision(2);

	cout << endl << "Total Sales: $" << total << endl;
	cout << "Average Sales: $" << total / numOfDays << endl << endl;

	delete [] saleFigures;
	saleFigures = NULL;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

