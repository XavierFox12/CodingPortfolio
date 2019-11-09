/* Program: rectangleTypeImp.cpp
   Programmer: Xavier Fox
   Date: 23 Feb. 2015
   Purpose: Defines the rectangleType class
*/

#include "stdafx.h"
#include "rectangleType.h"
#include <iostream>

using namespace std;

// sets the dimensions
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

// constructor
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
rectangleType rectangleType::operator+(const rectangleType& rectangle) const
{
	rectangleType tempRect;

	tempRect.length = length + rectangle.length;
	tempRect.width = width + rectangle.width;

	return tempRect;
}

// - operator
rectangleType rectangleType::operator-(const rectangleType& rectangle) const
{
	rectangleType tempRect;

	tempRect.length = length - rectangle.length;
	tempRect.width = width - rectangle.width;

	return tempRect;
}

// * operator
rectangleType rectangleType::operator*(const rectangleType& rectangle) const
{
	rectangleType tempRect;

	tempRect.length = length * rectangle.length;
	tempRect.width = width * rectangle.width;

	return tempRect;
}

// / operator
rectangleType rectangleType::operator/(const rectangleType& rectangle) const
{
	rectangleType tempRect;

	tempRect.length = length / rectangle.length;
	tempRect.width = width / rectangle.width;

	return tempRect;
}

// pre ++ operator
rectangleType rectangleType::operator++()
{
	++length;
	++width;

	return *this;
}

// post ++ operator
rectangleType rectangleType::operator++(int u)
{
	rectangleType temp = *this;

	length++;
	width++;

	return temp;
}

// pre -- operator
rectangleType rectangleType::operator--()
{
	--length;
	--width;

	return *this;
}

// post -- operator
rectangleType rectangleType::operator--(int u)
{
	rectangleType temp = *this;

	length--;
	width--;

	return temp;
}

// == operator
bool rectangleType::operator==(const rectangleType& rectangle) const
{
	return (length == rectangle.length && width == rectangle.width);
}

// != operator
bool rectangleType::operator!=(const rectangleType& rectangle) const
{
	return (length != rectangle.length || width != rectangle.width);
}

// < operator
bool rectangleType::operator<(const rectangleType& rectangle) const
{
	return (area() < rectangle.area());
}

// > operator
bool rectangleType::operator>(const rectangleType& rectangle) const
{
	return (area() > rectangle.area());
}

// <= operator
bool rectangleType::operator<=(const rectangleType& rectangle) const
{
	return (area() <= rectangle.area());
}

// >= operator
bool rectangleType::operator>=(const rectangleType& rectangle) const
{
	return (area() >= rectangle.area());
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