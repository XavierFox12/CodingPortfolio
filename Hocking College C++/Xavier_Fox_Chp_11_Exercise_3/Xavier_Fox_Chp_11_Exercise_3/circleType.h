/* Program: circleType.h
   Programmer: Xavier Fox
   Date: 26 Jan. 2015
   Purpose: Creates the members of the 
   circleType class.
*/

#ifndef H_circleType
#define H_circleType

class circleType
{
private:
	double radius;

public:
	void setRadius(double circleRadius);
	double getRadius();
	double area();
	double circumference();
	void print();
	circleType(double circleRadius = 0.0);
};

#endif