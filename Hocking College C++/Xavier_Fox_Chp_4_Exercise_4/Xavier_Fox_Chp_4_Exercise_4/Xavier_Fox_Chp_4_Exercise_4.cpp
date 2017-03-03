/* Program: Xavier_Fox_Chp_4_Exercise_4.cpp
   Programmer: Xavier Fox
   Date: 29 Sep. 2014
   Purpose: To determine what shape the user entered
   and determine its area, or circumference.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

const double PI = 3.1416;
int main()
{
	string shape;
	double height, length, width, radius;

	cout << "Enter the shape type: (rectangle, circle, cylinder) ";
	cin >> shape;
	cout << endl;

	cout << fixed << showpoint << setprecision(2);

	if (shape == "rectangle")
	{
		cout << "Enter the length of the rectangle: ";
		cin >> length;
		cout << endl;

		cout << "Enter the width of the rectangle: ";
		cin >> width;
		cout << endl;

		cout << "Area of the rectangle = "
			 << length * width << endl;
		cout << "Perimeter of the rectangle = "
			 << 2 * (length + width) << endl;
	}

	else if (shape == "circle")
	{
		cout << "Enter radius of the circle: ";
		cin >> radius;
		cout << endl;

		cout << "Area of the circle = "
			 << PI * pow(radius, 2.0) << endl;

		cout << "Circumference of the circle: "
			 << 2 * PI * radius << endl;
	}

	else if (shape == "cylinder")
	{
		cout << "Enter the height of the cylinder: ";
		cin >> height;
		cout << endl;

		cout << "Enter the radius of the base of the cylinder: ";
		cin >> radius;
		cout << endl;

		cout << "Volume of the cylinder = "
			 << PI * pow(radius, 2.0)* height << endl;

		cout << "Surface area of the cylinder: "
			 << 2 * PI * radius * height + 2 * PI * pow(radius, 2.0)
			 << endl;
	}

	else
		cout << "The program does not handle " << shape << endl;


	cout << endl << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

