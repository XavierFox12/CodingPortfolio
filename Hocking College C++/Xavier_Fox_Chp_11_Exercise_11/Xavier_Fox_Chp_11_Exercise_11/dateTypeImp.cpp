/* Program: dateTypeImp.h
   Programmer: Xavier Fox
   Date: 30 Jan. 2015
   purpose: Establishes the members of the dateType class
*/

#include "stdafx.h"
#include <iostream>
#include "dateType.h"

using namespace std;

void dateType::setDate(int month, int day, int year)
{
	dMonth = month;
	dDay = day;
	dYear = year;
}

int dateType::getDay() const
{
	return dDay;
}

int dateType::getMonth() const
{
	return dMonth;
}

int dateType::getYear() const
{
	return dYear;
}

void dateType::printDate() const
{
	cout << dMonth << "-" << dDay << "-" << dYear;
}

dateType::dateType(int month, int day, int year)
{
	dMonth = month;
	dDay = day;
	dYear = year;
}