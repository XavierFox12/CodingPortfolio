/* Program: Xavier_Fox_Chp_2_Exercise_11.cpp
   Programmer: Xavier Fox
   Date: 16 Sep. 2014
   Purpose: To determine the total miles a car can be driven
   given the fuel capacity and miles per gallon.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double fuelCapacity, milesPerGallon, totalMiles;

	cout << "Enter the fuel tank capacity in gallons: ";
	cin >> fuelCapacity;
	cout << endl;

	cout << "Enter the miles per gallon: ";
	cin >> milesPerGallon;

	totalMiles = fuelCapacity * milesPerGallon;

	cout << showpoint << fixed << setprecision(1);
	cout << endl << "The number of miles the car can be driven is "
		 << totalMiles << " miles" << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

