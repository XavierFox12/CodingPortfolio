/* Program: rectangleType.h
   Programmer: Xavier Fox
   Date: 23 Feb. 2015
   Purpose: Gives the parameters of the rectangleType
   class
*/

#ifndef rectangleType_H
#define rectangleType_H

#include <iostream>

using namespace std;

class rectangleType
{
	friend ostream& operator<<(ostream&, const rectangleType &);
	friend istream& operator>>(istream&, rectangleType &);

public:
	void setDimensions(double l, double w);
	double getLength() const;
	double getWidth() const;
	double area() const;
	double perimeter() const;

	rectangleType operator+(const rectangleType &) const;
	rectangleType operator-(const rectangleType &) const;
	rectangleType operator*(const rectangleType &) const;
	rectangleType operator/(const rectangleType &) const;

	rectangleType operator++();
	rectangleType operator++(int);
	rectangleType operator--();
	rectangleType operator--(int);

	bool operator==(const rectangleType&) const;
	bool operator!=(const rectangleType&) const;
	bool operator<(const rectangleType&) const;
	bool operator>(const rectangleType&) const;
	bool operator<=(const rectangleType&) const;
	bool operator>=(const rectangleType&) const;

	rectangleType();
	rectangleType(double l, double w);

protected:
	double length;
	double width;
};

#endif