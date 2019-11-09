/* Program: Xavier_Fox_Chp_6_Exercise_4.cpp
   Programmer: Xavier Fox
   Date: 28 Oct. 2014
   Purpose: To determine the square root of PI, and
   the volume and surface area of the sphere
*/

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14159;

int main()
{
	double surfaceArea, volume, radius;

	cout << "sqrt(PI) = " << sqrt(PI) << endl
		 << endl;

	cout << "Enter the value of r: ";
	cin >> radius;
	cout << endl;

	surfaceArea = 4 * PI * (pow(radius, 2.0));
	volume = 4.0 / 3 * PI * (pow(radius, 3.0));

	cout << "4 * PI * (r to the power of 2) = " << surfaceArea
		 << endl;
	cout << "4.0 / 3 * PI * (r to the power of 3) = "
		 << volume << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

