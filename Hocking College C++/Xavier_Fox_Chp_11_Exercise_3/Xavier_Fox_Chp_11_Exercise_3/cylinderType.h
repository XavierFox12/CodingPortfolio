/* Program: cylinderType.h
   Programmer: Xavier Fox
   Date: 26 Jan. 2015
   Purpose: Creates the members of the 
   cylinderType class.
*/

#ifndef H_cylinderType
#define H_cylinderType

#include "circleType.h"

class cylinderType:public circleType
{
private:
	double height;

public:
	void print();
	void setHeight(double cylinderHeight);
	double getHeight();
	double area();
	double volume();
	cylinderType(double circleRadius=0.0, double cylinderHeight=0.0);
};

#endif