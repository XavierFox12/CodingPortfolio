/* Program: Xavier_Fox_Chp_4_Exercise_6.cpp
   Programmer: Xavier Fox
   Date: 2 Oct. 2014
   Purpose: To determine the amount boxes and containers are
   used to hold cookies.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int cookies, boxes, containers,
		boxRemainder, containerRemainder;

	cout << "Enter the total number of cookies: ";
	cin >> cookies;
	cout << endl;

	if (cookies >= 24)
	{
		boxes = cookies / 24;
		boxRemainder = cookies % 24;

		cout << "Number of cookie boxes: " << boxes
			 << endl << "Leftover cookies: " << boxRemainder
			 << endl;

		if (boxes >=75)
		{
			containers = boxes / 75;
			containerRemainder = boxes % 75;

			cout << "Number of cookie containers: " << containers
				 << endl << "Leftover boxes: " << containerRemainder
				 << endl << endl;
		}
	}
	else
	{
		cout << "There are only " << cookies << " in one box"
			 << endl << endl;
	}

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

