/* Program: Xavier_Fox_Chp_1_Exercise_21.cpp
   Programmer: Xavier Fox
   Date: 4 Sep. 2014
   Purpose: To determine the total billing amount for
			Jason and to see if he is charged shipping
			and handling.
*/

#include "stdafx.h"

#include <iostream>

#include <iomanip>

using namespace std;


int main()
{
	int numOfItems;
	double billingAmount = 0.0, itemPrice, totalBill = 0.0;
	double shippingAndHandling = 10;

	cout << "Enter the number of items purchased: ";
	cin >> numOfItems;

	for (int count = 1; count <= numOfItems; count++)
	{
		cout << "   Enter the price for item " << count << ": ";
		cin >> itemPrice;

		billingAmount += itemPrice;
	}

	if (billingAmount >= 200)
	
		shippingAndHandling = 0;
	else
		totalBill += shippingAndHandling * numOfItems;
	
	shippingAndHandling = shippingAndHandling * numOfItems;

	totalBill = billingAmount + shippingAndHandling;

	cout << showpoint << fixed << setprecision(2);
	cout << endl
		<< "Billing Amount:         " << setw(6) << billingAmount << endl
		<< "Shiping and Handling:   " << setw(6) << shippingAndHandling << endl
		<< "          Total Bill:  $" << setw(6) << totalBill
		<< endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;
	return 0;
}

