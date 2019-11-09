/* Program: Xavier_Fox_Chp_6_Exercise_13.cpp
   Programmer: Xavier Fox
   Date: 4 Nov. 2014
   Purpose: To determine the windchill factor given the 
   temperature and wind speed.
*/

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

void getData(int& speed, int& temp);
int windChill(int speed, int temp);

int main()
{
	int speed, temp;

	getData(speed, temp);
	cout << "Current Temperature: " << temp << "F"
		 << endl;

	cout << "Windchill factor: " << windChill(speed, temp)
		 << "F" << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

void getData(int& speed, int& temp)
{
	cout << "Enter wind speed in miles per hour: ";
	cin >> speed;

	cout << "Enter temperature in degrees Fahrenheit: ";
	cin >> temp;
	cout << endl;

}

int windChill(int speed, int temp)
{
	double windchill;

	windchill = 35.74 + .6215 * temp - 35.75 * pow(speed, .16)
				+ .4275 * temp * pow(speed, .16);

	return windchill;
}