/* Program: Xavier_Fox_Chp_1_Exercise_17.cpp
   Programmer: Xavier Fox
   Date: 28 Aug 2014
   Purpose: To determine the price of a pizza per suare inch.
*/

#include "stdafx.h"

#include <iostream>

#include <iomanip>

using namespace std;


int main()
{
	double radiusOfPizza, pizzaPrice, pricePerInch,
		   area;

	cout << "Enter the radius of the pizza in inches: ";
	cin >> radiusOfPizza;

	cout << "Enter the total price of the pizza: ";
	cin >> pizzaPrice;

	area = 3.14 * radiusOfPizza * radiusOfPizza;

	pricePerInch = pizzaPrice / area;

	cout << showpoint << fixed << setprecision(2);
	cout << endl
		 <<"Price per square inch: " << pricePerInch
		 << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;
	return 0;
}

