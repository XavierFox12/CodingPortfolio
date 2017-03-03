/* Program: Xavier_Fox_Chp_14_Exercise_4.cpp
   Programmer: Xavier Fox
   Date: 17 Mar. 2015
   Purpose: Prints the time in 24 hour notation
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include "invalidHr.h"
#include "invalidMin.h"
#include "invalidSec.h"

using namespace std;

int getHours();
int getMinutes();
int getSeconds();

int main()
{
	int hr, min, sec;
	string amOrPm;

	hr = getHours();
	min = getMinutes();
	sec = getSeconds();

	cout << "Enter AM or PM: ";
	cin >> amOrPm;
	cout << endl;

	if (amOrPm == "PM")
		hr = 12 + hr;
	else if (amOrPm == "AM" && hr == 12)
		hr = 0;

	cout << "24 hour clock time: ";

	if (hr < 10)
		cout << "0" << hr << ":";
	else
		cout << hr << ":";
	if (min < 10)
		cout << "0" << min << ":";
	else
		cout << min << ":";
	if (sec < 10)
		cout << "0" << sec << endl << endl;
	else
		cout << sec << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

// gets the hours
int getHours()
{
	bool done = false;
	int hr = 0;

	do
	{
		try
		{
			cout << "Enter hours: ";
			cin >> hr;
			cout << endl;

			if (hr < 0 || hr > 12)
				throw invalidHr();
			
			done = true;
		}
		catch(invalidHr hrObj)
		{
			cout << hrObj.what() << endl << endl;
		}
	}
	while (!done);

	return hr;
}

// gets the minutes
int getMinutes()
{
	bool done = false;
	int min = 0;

	do
	{
		try
		{
			cout << "Enter minutes: ";
			cin >> min;
			cout << endl;

			if (min < 0 || min > 59)
				throw invalidMin();
			
			done = true;
		}
		catch(invalidMin minObj)
		{
			cout << minObj.what() << endl << endl;
		}
	}
	while (!done);

	return min;
}

// gets the seconds
int getSeconds()
{
	bool done = false;
	int sec = 0;

	do
	{
		try
		{
			cout << "Enter seconds: ";
			cin >> sec;
			cout << endl;

			if (sec < 0 || sec > 59)
				throw invalidSec();
			
			done = true;
		}
		catch(invalidSec secObj)
		{
			cout << secObj.what() << endl << endl;
		}
	}
	while (!done);

	return sec;
}