/* Program: Xavier_Fox_Chp_11_Exercise_3.cpp
   Programmer: Xavier Fox
   Date: 26 Jan. 2015
   Purpose: Determines the height, radius, volume
   and surface are of a cylinder.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "circleType.h"
#include "cylinderType.h"

using namespace std;

int main()
{
	cylinderType cylinder1(4.50, 6.75);
	cylinderType cylinder2;

	double radius = 0, height = 0;

	cout << fixed << showpoint << setprecision(2);

	cout << "***** Cylinder 1 *****" << endl;
	cylinder1.print();
	cout << endl << endl;

	cylinder2.setRadius(3.75);
	cylinder2.setHeight(8.25);
	cout << "***** Cylinder 2 *****" << endl
		 << "Radius = " <<cylinder2.getRadius() << ", height = "
		 << cylinder2.getHeight() << ", surface area = " << cylinder2.area()
		 << ", volume = " << cylinder2.volume() << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

