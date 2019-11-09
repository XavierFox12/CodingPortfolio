/* Program: Xavier_Fox_Chapter_1_Exercise_18.cpp
   Programmer: Xavier Fox
   Date: 2 Sep. 2014
   Purpose: To determine the selling price of an item after
   a 80 % markup and 10% mark down.
*/

#include "stdafx.h"

#include <iostream>

using namespace std;

int main()
{
	double originalPrice, markedUpPrice, sellingPrice;

	cout << "Enter the original price item: ";
	cin >> originalPrice;

	markedUpPrice = (originalPrice * .8) + originalPrice;
	sellingPrice = markedUpPrice - (markedUpPrice * .1);

	cout << endl
		 << "Item Information:" << endl
		 << "    Original Price: $" << originalPrice << endl
		 << "    Selling Price:  $" << sellingPrice << endl << endl;

	cout << "Program by Xavier Fox" << endl << endl;
	return 0;
}

