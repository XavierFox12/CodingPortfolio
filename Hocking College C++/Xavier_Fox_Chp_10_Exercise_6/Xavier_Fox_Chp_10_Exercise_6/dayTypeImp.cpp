/* dayTypeImp.cpp
   Name: Xavier Fox
   Date: 14 Jan. 2015
   Purpose: Defines the members of the dayType
   class
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include "dayType.h"

using namespace std;

// Sets the day of the week
void dayType:: setDay(string day)
{
	dayOfWeek = day;
}

// Prints the day of the week
void dayType:: printDay() const
{
	cout << dayOfWeek << endl;
}

// Gets the day of the week
string dayType:: getDay() const
{
	return dayOfWeek;
}

// Gets the next day of the week
string dayType:: getNextDay() const
{
	int i;
	static string weekDays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday",
								"Thursday", "Friday", "Saturday"};

	for (i=0; i < 7; i++)
		if (weekDays[i] == dayOfWeek)
			break;
	return weekDays[(i+1) % 7];
}

// Gets the previous day of the week
string dayType:: getPrevDay() const
{
	int i;
	static string weekDays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday",
								"Thursday", "Friday", "Saturday"};

	if (dayOfWeek == "Sunday")
		return "Saturday"; 

	for (i=0; i < 7; i++)
		if (weekDays[i] == dayOfWeek)
			break;
	return weekDays[i-1];
}

// Gets the certain day depending on how many days the user entered
void dayType:: getCertainDay(int numOfDays)
{
	int i = 0;
	static string weekDays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday",
								"Thursday", "Friday", "Saturday"};

	for (i=0; i < 7; i++)
		if (weekDays[i] == dayOfWeek)
			break;

	dayOfWeek = weekDays[(numOfDays + i) % 7];
}

// Constructor
dayType:: dayType()
{
	dayOfWeek = "Sunday";
}

//Constructor
dayType:: dayType(string day)
{
	dayOfWeek = day;
}