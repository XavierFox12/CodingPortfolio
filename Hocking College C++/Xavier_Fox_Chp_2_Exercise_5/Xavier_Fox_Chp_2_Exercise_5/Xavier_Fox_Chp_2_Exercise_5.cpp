/* Program: Xavier_Fox_Chp_2_Exercise_5.cpp
   Programmer: Xavier Fox
   Date: 9 Sep. 2014
   Purpose: To put the statements in the correct order
   and display the area and circumference.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

const double PI = 3.14;

int main()
{
	double radius, area, circumference;

	cout << "Enter the radius: ";
	cin >> radius;
	cout << endl;

	area = PI * radius * radius;
	circumference = 2 * PI * radius;

	cout << "Area = " << area << endl;
	cout << "Circumference = " << circumference << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

