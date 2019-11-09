/* Program: Xavier_Fox_Chp_14_Exercise_5.cpp
   Programmer: Xavier Fox
   Date: 23 Mar. 2015
   Purpose: To find the users birth date
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include "invalidYear.h"
#include "invalidMonth.h"
#include "invalidDay.h"

using namespace std;

int getYear();
int getMonth();
int getDay(int amountOfDays);

int main()
{
	int day, month, year, amountOfDays;
	string nameOfMonth[12] = {"January", "February", "March", "April",
							  "May", "June", "July", "August",
							  "September", "October", "November", "December"};

	cout << "Enter your birthdate in numeric form." << endl;

	year = getYear();
	month = getMonth();

	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		amountOfDays = 31;
		break;

	case 2:
		if (year % 4 == 0)
			amountOfDays = 29;
		else
			amountOfDays = 28;
		break;

	default:
		amountOfDays = 30;
	}

	day = getDay(amountOfDays);

	cout << endl << "Birth Day: " << nameOfMonth[month - 1] << " " << day
		 << ", " << year << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

// gets the year
int getYear()
{
	bool done = false;
	int year = 1900;
	string str = "Year must be numeric.";

	do
	{
		try
		{
			cout << "   Year: ";
			cin >> year;
			
			if (year < 0)
				throw invalidYear();
			else if (!cin)
				throw invalidYear(year);

			done = true;
		}
		catch(invalidYear yearObj)
		{
			cout << yearObj.what() << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (!done);

	return year;
}

// gets the month
int getMonth()
{
	bool done = false;
	int month = 1;

	do
	{
		try
		{
			cout << "   Month: ";
			cin >> month;

			if (month < 1 || month > 12)
				throw invalidMonth();

			else if (!cin)
				throw invalidMonth(month);
			
			done = true;
		}
		catch(invalidMonth monthObj)
		{
			cout << monthObj.what() << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (!done);

	return month;
}

// gets the day
int getDay(int amountOfDays)
{
	bool done = false;
	int day = 1;

	do
	{
		try
		{
			cout << "   Day: ";
			cin >> day;

			if (day < 1 || day > amountOfDays)
				throw invalidDay(amountOfDays);

			else if (!cin)
				throw invalidDay();
			
			done = true;
		}
		catch(invalidDay dayObj)
		{
			cout << dayObj.what() << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (!done);

	return day;
}
