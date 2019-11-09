/* Program: Xavier_Fox_Chp_4_Exercise_5.cpp
   Programmer: Xavier Fox
   Date: 30 Sep. 2014
   Purpose: To determine if the 3 sides given are enough
   to be a right triangle
*/

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double side1, side2, side3;

	cout << "Enter the three lengths of a triangle: ";
	cin >> side1 >> side2 >> side3;
	cout << endl;

	side1 = pow(side1, 2.0);
	side2 = pow(side2, 2.0);
	side3 = pow(side3, 2.0);

	if (side1 == side2 + side3 || side2 == side1 + side3 || side3 ==
		side1 + side2)
	{
		cout << "It is a right angled triangle" << endl << endl;
	}
	else
	{
		cout << "It is not a right angled triangle" << endl << endl;
	}

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

