/* Program: cylinderTypeImp.cpp
   Programmer: Xavier Fox
   Date: 26 Jan. 2015
   Purpose: Establishes the members of the 
   cylinderType class
*/

#include "stdafx.h"
#include "circleType.h"
#include "cylinderType.h"
#include <iostream>

using namespace std;

// prints out the volume, surface area, height, and radius
void cylinderType::print()
{
	cout << "Radius = " << getRadius() << ", height = " << height
		 << ", surface area = " << area() << ", volume = " << volume();
}

// sets the height
void cylinderType::setHeight(double cylinderHeight)
{
	if (cylinderHeight >= 0)
		height = cylinderHeight;
	else
		height = 0;
}

// gets the height
double cylinderType::getHeight()
{
	return height;
}

// determines the surface area of the cylinder
double cylinderType::area()
{
	return 2 * 3.1416 * getRadius() * height + 2 * 3.1416 *
		   getRadius() * getRadius();
}

// determines the volume of the cylinder
double cylinderType::volume()
{
	return 3.1416 * circleType::getRadius() * circleType::getRadius() * height;
}

// constructor
cylinderType::cylinderType(double circleRadius, double cylinderHeight)
			:circleType(circleRadius)
{
	setHeight(cylinderHeight);
}