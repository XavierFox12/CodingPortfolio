/* Program: Xavier_Fox_Chp_10_Exercise_6.cpp
   Programmer: Xavier Fox
   Date: 14 Jan. 2015
   Purpose: To determine what day it is, before
   and after today's day by whatthe user enters
   and determine what day it isafter a couple of days.
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include "dayType.h"

using namespace std;

int main()
{
	dayType myDay("Monday");
	dayType yourDay;

	int numDays;
	string weekDay;

	// myDay's data
	cout << "myDay (current): ";
	myDay.printDay();
	cout << "myDay (previous): " << myDay.getPrevDay() << endl;
	cout << "myDay (next): " << myDay.getNextDay() << endl << endl;

	cout << "**********************" << endl << endl;

	// yourDay's data
	cout << "yourDay (current): ";
	yourDay.printDay();
	cout << endl;

	cout << "Enter a value for yourDay: ";
	cin >> weekDay;

	cout << "yourDay (current): ";
	yourDay.setDay(weekDay);
	cout << yourDay.getDay() << endl << endl;

	cout << "Enter the number of days to add to yourDay: ";
	cin >> numDays;

	cout << "yourDay (updated): ";
	yourDay.getCertainDay(numDays);
	cout << yourDay.getDay();

	cout << endl << endl << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

