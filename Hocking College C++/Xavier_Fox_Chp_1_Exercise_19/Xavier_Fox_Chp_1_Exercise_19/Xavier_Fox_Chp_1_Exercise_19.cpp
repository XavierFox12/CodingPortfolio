/* Program:Xavier_Fox_Chp_1_Exercise_19.cpp
   Programmer: Xavier Fox
   Date: 2 Sep. 2014
   Purpose: To determine the volume and surface area given
   the radius.
*/

#include "stdafx.h"

#include <iostream>

#include <iomanip>

using namespace std;

int main()
{
	const double PI = 3.141592;
	double radius, volume, surfaceArea;

	cout << "Enter the radius of the sphere: ";
	cin >> radius;

	volume = (4.0 / 3.0) * PI * radius * radius * radius;

	surfaceArea = 4.0 * PI * radius * radius;

	cout << endl
		 << "Sphere Information:" << endl
		 << "    Radius:     " << setw(6) << radius << endl
		 << "    Volume:       " << setw(6) << volume << endl
		 << "    Surface Area: " << setw(6) << surfaceArea << endl << endl;


	cout << "Program by: Xavier Fox" << endl << endl;
	return 0;
}

