/* Program: rectangleTypeImp.cpp
   Programmer: Xavier Fox
   Date: 25 Feb. 2015
   Purpose: Defines the rectangleType class
*/

#include "stdafx.h"
#include "rectangleType.h"
#include <iostream>

using namespace std;

// sets the length and the width
void rectangleType::setDimensions(double l, double w)
{
	if (l >= 0)
		length = l;
	else
		length = 0;
	
	if (w >= 0)
		width = w;
	else
		length = 0;
}

// gets the length
double rectangleType::getLength() const
{
	return length;
}
// gets the width
double rectangleType::getWidth() const
{
	return width;
}

// gets the area
double rectangleType::area() const
{
	return length * width;
}

// gets the perimeter
double rectangleType::perimeter() const
{
	return 2 * (length * width);
}

// constuctor
rectangleType::rectangleType(double l, double w)
{
	setDimensions(l, w);
}

// constructor
rectangleType::rectangleType()
{
	length = 0;
	width = 0;
}

// + operator
rectangleType operator+(const rectangleType& rectangle,
						const rectangleType& rectangle2)
{
	rectangleType tempRect;

	tempRect.length = rectangle.length + rectangle2.length;
	tempRect.width = rectangle.width + rectangle2.width;

	return tempRect;
}

// - operator
rectangleType operator-(const rectangleType& rectangle,
						const rectangleType& rectangle2)
{
	rectangleType tempRect;

	tempRect.length = rectangle.length - rectangle2.length;
	tempRect.width = rectangle.width - rectangle2.width;

	return tempRect;
}

// * operator
rectangleType operator*(const rectangleType& rectangle,
						const rectangleType& rectangle2)
{
	rectangleType tempRect;

	tempRect.length = rectangle.length * rectangle2.length;
	tempRect.width = rectangle.width * rectangle2.width;

	return tempRect;
}

// / operator
rectangleType operator/(const rectangleType& rectangle,
						const rectangleType& rectangle2)
{
	rectangleType tempRect;

	tempRect.length = rectangle.length / rectangle2.length;
	tempRect.width = rectangle.width / rectangle2.width;

	return tempRect;
}

// pre ++ operator
rectangleType operator++(rectangleType& rectangle)
{
	++(rectangle.length);
	++(rectangle.width);

	return rectangle;
}

// post ++ operator
rectangleType operator++(rectangleType& rectangle, int u)
{
	rectangleType temp = rectangle;

	(rectangle.length)++;
	(rectangle.width)++;

	return temp;
}

// pre -- operator
rectangleType operator--(rectangleType& rectangle)
{
	--(rectangle.length);
	--(rectangle.width);

	return rectangle;
}

// post -- operator
rectangleType operator--(rectangleType& rectangle, int u)
{
	rectangleType temp = rectangle;

	(rectangle.length)--;
	(rectangle.width)--;

	return temp;
}

// == operator
bool operator==(const rectangleType& rectangle,
				const rectangleType& rectangle2)
{
	return (rectangle.length == rectangle2.length && rectangle.width == rectangle2.width);
}

// != operator
bool operator!=(const rectangleType& rectangle,
				const rectangleType& rectangle2)
{
	return (rectangle.length != rectangle2.length || rectangle.width != rectangle2.width);
}

// < operator
bool operator<(const rectangleType& rectangle,
			   const rectangleType& rectangle2)
{
	return (rectangle.area() < rectangle2.area());
}

// > operator
bool operator>(const rectangleType& rectangle,
			   const rectangleType& rectangle2)
{
	return (rectangle.area() > rectangle2.area());
}

// <= operator
bool operator<=(const rectangleType& rectangle,
		        const rectangleType& rectangle2)
{
	return (rectangle.area() <= rectangle2.area());
}

// >= operator
bool operator>=(const rectangleType& rectangle,
				const rectangleType& rectangle2)
{
	return (rectangle.area() >= rectangle2.area());
}

// output operator
ostream& operator<<(ostream& osObject, const rectangleType& rectangle)
{
	osObject << "Length = " << rectangle.length << "; "
		   	 << "Width = " << rectangle.width;

	return osObject;
}

// input operator
istream& operator>> (istream& isObject, rectangleType& rectangle)
{
	isObject >> rectangle.length >> rectangle.width;

	return isObject;
}