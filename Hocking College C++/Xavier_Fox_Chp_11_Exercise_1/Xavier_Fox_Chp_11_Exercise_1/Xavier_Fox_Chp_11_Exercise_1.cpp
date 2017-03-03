/* Xavier_Fox_Chp_11_Exercise_1.cpp
   Programmer: Xavier Fox
   Date: 23 Jan. 2015
   Purpose:
*/

#include "stdafx.h"
#include <string>
#include <iomanip>
#include <iostream>
#include "extClockType.h"

using namespace std;

int main()
{
	extClockType myClock;
	extClockType yourClock;
	int hours, minutes, seconds;
	string timeZone;

	myClock.setTime(5, 10, 34, "CST");
	cout << "myClock: ";
	myClock.printTime();
	cout << endl;

	cout << "yourClock: ";
	yourClock.printTime();
	cout << endl << endl;

	yourClock.setHours(5);
	yourClock.setMinutes(45);
	yourClock.setSeconds(16);
	cout << "After setting, yourClock: ";
	yourClock.printTime();
	cout << endl << endl;

	cout << "Enter the hours, minutes, seconds for myClock: ";
	cin >> hours >> minutes >> seconds;
	cout << endl;
	myClock.setHours(hours);
	myClock.setMinutes(minutes);
	myClock.setSeconds(seconds);

	cout << "After setting, myClock: hours = " << hours
		 << ", minutes = " << minutes << ", seconds = " << seconds << endl << endl;

	cout << "After incrementing myClock by one second, myClock: ";
	myClock.incrementSeconds();
	myClock.printTime();
	cout << endl;

	cout << "After incrementing myClock by one minute, myClock: ";
	myClock.incrementMinutes();
	myClock.printTime();
	cout << endl;

	cout << "After incrementing myClock by one hour, myClock: ";
	myClock.incrementHours();
	myClock.printTime();
	cout << endl << endl;

	myClock.getTime(hours, minutes, seconds);
	cout << "Current values, myClock: hours = " << hours
		 << ", minutes = " << minutes << ", seconds = " << seconds << endl;

	cout << "Current values, yourClock: hours = " << yourClock.getHours()
		 << ", minutes = " << yourClock.getMinutes() << ", seconds = " 
		 << yourClock.getSeconds() << endl << endl;

	cout << "When comparing myClock and yourClock, the clocks are: ";
	if (myClock.equalTime(yourClock))
		cout << "The times are equal" << endl << endl;
	else
		cout << "The times are not equal" << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

