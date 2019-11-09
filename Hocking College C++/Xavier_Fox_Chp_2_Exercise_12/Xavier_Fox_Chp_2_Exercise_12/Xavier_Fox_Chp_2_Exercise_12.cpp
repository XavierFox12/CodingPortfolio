/* Program: Xavier_Fox_Chp_2_Exercise_12.cpp
   Programmer: Xavier Fox
   Date: 16 Sep. 2014
   Purpose: To determine the hours and minutes given the
   seconds.
*/

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string firstName;
	int seconds, minutes, hours;

	cout << "Enter first name: ";
	cin >> firstName;

	cout << "Enter the elapsed time in seconds: ";
	cin >> seconds;
	cout << endl;

	cout << endl << "The elapsed time in seconds: "
		 << seconds << endl;

	hours = seconds / 3600;

	seconds = seconds % 3600;

	minutes = seconds / 60;

	seconds = seconds % 60;
	
	cout << "The equivalent time in hours:minutes:seconds = "
		 << hours << ":" << minutes << ":" << seconds
		 << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

