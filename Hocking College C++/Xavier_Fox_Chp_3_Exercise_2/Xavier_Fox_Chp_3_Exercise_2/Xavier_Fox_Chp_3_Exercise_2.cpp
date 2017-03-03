/* Program: Xavier_Fox_Chp_3_Exercise_2.cpp
   Programmer: Xavier Fox
   Date: 22 Sep. 2014
   Purpose: To determine the volume and radius of
   a cylinder.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double PI = 3.14159;

int main()
{
	double height;
	double radius;

	cout << "Enter the height of the cylinder: ";
	cin >> height;
	cout << endl;

	cout << "Enter the radius of the base of the cylinder: ";
	cin >> radius;
	cout << endl;

	cout << fixed << showpoint << setprecision(2);

	cout << "Volume of the cylinder = "
		 << PI * pow(radius, 2.0)* height << endl;

	cout << "Surface area: "
		 << 2 * PI * radius * height + 2 * PI * pow(radius, 2.0)
		 << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

