/* Program: rectangleType.h
   Programmer: Xavier Fox
   Date: 25 Feb. 2015
   Purpose: Gives the parameters of the rectangleType
   class
*/

#ifndef rectangleType_H
#define rectangleType_H

#include <iostream>

using namespace std;

class rectangleType
{
	friend ostream& operator<<(ostream&, const rectangleType&);
	friend istream& operator>>(istream&, rectangleType&);

	friend rectangleType operator+(const rectangleType&, const rectangleType&);
	friend rectangleType operator-(const rectangleType&, const rectangleType&);
	friend rectangleType operator*(const rectangleType&, const rectangleType&);
	friend rectangleType operator/(const rectangleType&, const rectangleType&);

	friend rectangleType operator++(rectangleType&);
	friend rectangleType operator++(rectangleType&, int);
	friend rectangleType operator--(rectangleType&);
	friend rectangleType operator--(rectangleType&, int);

	friend bool operator==(const rectangleType&, const rectangleType&);
	friend bool operator!=(const rectangleType&, const rectangleType&);
	friend bool operator<(const rectangleType&, const rectangleType&);
	friend bool operator>(const rectangleType&, const rectangleType&);
	friend bool operator<=(const rectangleType&, const rectangleType&);
	friend bool operator>=(const rectangleType&, const rectangleType&);

public:
	void setDimensions(double l, double w);
	double getLength() const;
	double getWidth() const;
	double area() const;
	double perimeter() const;

	rectangleType();
	rectangleType(double l, double w);

protected:
	double length;
	double width;
};

#endif