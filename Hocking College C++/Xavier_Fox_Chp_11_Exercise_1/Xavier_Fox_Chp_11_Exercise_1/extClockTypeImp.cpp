/* Program: extClockTypeImp.cpp
   Programmer: Xavier Fox 
   Date: 23 Jan. 2015
   Purpose: 
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include "extClockType.h"

using namespace std;

void extClockType::setTime(int hours, int minutes, int seconds, string tZone)
{
	clockType::setTime(hours, minutes, seconds);
	timeZone = tZone;
}

void extClockType::printTime()
{
	clockType::printTime();
	cout << " " << timeZone;
}

extClockType::extClockType(int hours, int minutes, int seconds, string tZone)
			:clockType(hours, minutes, seconds)
{
	timeZone=tZone;
}