/* Program: Xavier_Fox_Chp_6_Exercise_5.cpp
   Programmer: Xavier Fox
   Date: 28 Oct. 2014
   Purpose: To determine either the area of a rectangle,
   volume of a cylinder, or the area of a circle.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double rectangle(double l, double w);
double circle(double r);
double cylinder(double bR, double h);
const double PI = 3.1419;

int main()
{
	double radius;
	double height;
	int choice;

	cout << fixed << showpoint << setprecision(2) << endl;
	cout << "This program can calculate the area of a rectangel, "
		 << "the area of a circle, or volume of a cylinder." << endl;
	cout << "To run the program enter: " << endl;
	cout << "   1: To find the area of rectangle." << endl;
	cout << "   2: To find the area of a circle." << endl;
	cout << "   3: To find the volume of a cylinder." << endl;
	cout << "  -1: To terminate the program.  ";
	cin >> choice;
	cout << endl;

	while (choice != -1)
	{
		switch (choice)
		{
		case 1:
			double length, width;
			cout << "Enter the length and the width "
				 << "of the rectangle: ";
			cin >> length >> width;
			cout << endl;

			cout << "Area = " << rectangle(length, width)
				 << endl << endl;
			break;

		case 2:
			cout << "Enter the radius of the circle: ";
			cin >> radius;
			cout << endl;

			cout << "Area = " << circle(radius)
				 << endl << endl;
			break;

		case 3:
			cout << "Enter the radius of the base and the "
				 << "height of the cylinder: ";
			cin >> radius >> height;
			cout << endl;

			cout << "Volume = " << cylinder(radius, height) << endl
				 << endl;
			break;

		default:
			cout << "Invalid choice!" << endl << endl;
		}

		cout << "To run the program enter: " << endl;
		cout << "   1: To find the area of rectangle." << endl;
		cout << "   2: To find the area of a circle." << endl;
		cout << "   3: To find the volume of a cylinder." << endl;
		cout << "  -1: To terminate the program.  ";
		cin >> choice;
		cout << endl;
	}

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

double rectangle(double l, double w)
{
	return l * w;
}

double circle(double r)
{
	return PI * (pow(r, 2.0));
}

double cylinder(double bR, double h)
{
	return PI * bR * bR * h;
}

