/* Program: circleTypeImp.cpp
   Programmer: Xavier Fox
   Date: 28 Jan. 2015
   Purpose: Establishes the members of the
   circleType class.
*/

#include "stdafx.h"
#include <iostream>
#include "circleType.h"

using namespace std;

// sets the radius
void circleType::setRadius(double circleRadius)
{
	if (circleRadius >= 0)
		radius = circleRadius;
	else
		radius = 0;
}

// returns the radius
double circleType::getRadius()
{
	return radius;
}

// returns the area
double circleType::area()
{
	return 3.1416 * radius * radius;
}

// returns the circumference
double circleType::circumference()
{
	return 2 * 3.1416 * radius;
}

// prints the radius, area, and circumference
void circleType::print()
{
	cout << "radius: " << radius
		 << ", area: " << area()
		 << ", circumference: " << circumference()
		 << endl;
}

// constructor
circleType::circleType(double circleRadius)
{
	setRadius(circleRadius);
}