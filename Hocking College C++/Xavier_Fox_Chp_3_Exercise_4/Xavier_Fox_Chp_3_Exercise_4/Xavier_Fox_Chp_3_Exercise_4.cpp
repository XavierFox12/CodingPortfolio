/* Program: Xavier_Fox_Chp_3_Exercise_4.cpp
   Programmer: Xavier Fox
   Date: 22 Sep. 2014
   Purpose: To find the logical errors in finding the cost
   of fertilizer per pound and cost of fertilizing per
   square feet.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double cost;
	double area;
	double bagSize;

	cout << "Enter the amount of fertilizer, in pounds, "
		 << "in one bag: ";
	cin >> bagSize;
	cout << endl;

	cout << "Enter the cost of the " << bagSize
		 << " pound fertilizer bag: ";
	cin >> cost;
	cout << endl;

	cout << "Enter the area, in square feet, that can be "
		 << "fertilized by one bag: ";
	cin >> area;
	cout << endl;

	cout << fixed << showpoint << setprecision(2);

	cout << "The cost of the fertilizer per pound is: $"
		 << cost / bagSize << endl;
	cout << "The cost of fertilizing per square foot is: $"
		 << cost / area << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

