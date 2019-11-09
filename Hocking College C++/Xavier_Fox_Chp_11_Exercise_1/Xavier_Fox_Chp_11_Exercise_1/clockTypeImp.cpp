/* Program: clockTypeImp.cpp
   Programmer: Xavier Fox
   Date: 20 Jan. 2015
   Purpose: declares the clockType definitions
*/

#include "stdafx.h"
#include <iostream>
#include "clockType.h"

using namespace std;

// sets hours minutes and seconds
void clockType::setTime(int hours, int minutes, int seconds)
{
	if (0 <= hours && hours < 24)
		hr = hours;
	else
		hr = 0;

	if (0 <= minutes && minutes < 60)
		min = minutes;
	else
		min = 0;

	if (0 <= seconds && seconds < 60)
		sec = seconds;
	else
		sec = 0;
}

// sets hours
void clockType::setHours(int hours)
{
	if (0 <= hours && hours < 24)
		hr = hours;
	else
		hr = 0;
}

// sets minutes
void clockType::setMinutes(int minutes)
{
	if (0 <= minutes && minutes < 60)
		min = minutes;
	else
		min = 0;
}

// sets seconds
void clockType:: setSeconds(int seconds)
{
	if (0 <= seconds && seconds < 60)
		sec = seconds;
	else
		sec = 0;
}

// gets hours minutes and seconds
void clockType::getTime(int& hours, int& minutes, int& seconds) const
{
	hours = hr;
	minutes = min;
	seconds = sec;
}

// gets hours
int clockType::getHours() const
{
	return hr;
}

// gets minutes
int clockType::getMinutes() const
{
	return min;
}

// gets seconds
int clockType::getSeconds() const
{
	return sec;
}

// prints the hours minutes and seconds
void clockType::printTime() const
{
	if (hr < 10)
		cout << "0";
	cout << hr << ":";

	if (min < 10)
		cout << "0";
	cout << min << ":";

	if (sec < 10)
		cout << "0";
	cout << sec;
}

// increments the hours
void clockType::incrementHours()
{
	hr++;
	if (hr > 23)
		hr = 0;
}

// increments the minutes
void clockType::incrementMinutes()
{
	min++;
	if (min > 59)
	{
		min = 0;
		incrementHours();
	}
}

// increments the seconds
void clockType:: incrementSeconds()
{
	sec++;
	if (sec > 59)
	{
		sec = 0;
		incrementMinutes();
	}
}

// determines if the two clocks are equal
bool clockType::equalTime(const clockType& otherClock) const
{
	return (hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec);
}

// constructor with parameters
clockType::clockType(int hours, int minutes, int seconds)
{
	setTime(hours, minutes, seconds);
}

// default constructor
clockType::clockType()
{
	hr = 0;
	min = 0;
	sec = 0;
}
