/* Program: Xavier_Fox_Chp_7_Exercise_1.cpp
   Programmer: Xavier Fox
   Date: 10 Nov. 2014
   Purpose: To determine if a triangle is a scalene,
   isosceles, equilateral, or if it is no triangle 
   given the three sides.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

enum triangleType {scalene, isosceles, equilateral, noTriangle};
triangleType triangleShape(double side1, double side2, double side3);
void printShape(triangleType triangle);

int main()
{
	double side1, side2, side3;
	char yesOrNo = 'y';
	triangleType triangle;

	cout << setw(50) << "    Triangle Types    " << endl
		 << setw(50) << "Program by: Xavier Fox" << endl << endl;

	while (yesOrNo == 'y')
	{
		cout << "Enter the three sides of the triangle: ";
		cin >> side1 >> side2 >> side3;
		cout << endl;

		triangle = triangleShape(side1, side2, side3);
		printShape(triangle);
		
		cout << "Do you want to continue? (y/n) ";
		cin >> yesOrNo;
		cout << endl;
	}
	return 0;
}

triangleType triangleShape(double side1, double side2, double side3)
{
	triangleType triangle;

	if (side1 + side2 < side3 || side1 + side3 < side2 ||
		side2 + side3 < side1)
	{
		triangle = noTriangle;
	}
	else
	{
		if (side1 != side2 && side1 != side3 && side2 != side3)
			triangle = scalene;
		else if (side1 == side2 && side1 == side3 && side2 == side3)
			triangle = equilateral;
		else
			triangle = isosceles;
	}
	return triangle;
}

void printShape(triangleType triangle)
{
	switch (triangle)
	{
	case scalene:
		cout << "scalene" << endl << endl;
		break;
	case equilateral:
		cout << "equilateral" << endl << endl;
		break;
	case isosceles:
		cout << "isoceles" << endl << endl;
		break;
	case noTriangle:
		cout << "noTriangle" << endl << endl;
		break;
	}
}

