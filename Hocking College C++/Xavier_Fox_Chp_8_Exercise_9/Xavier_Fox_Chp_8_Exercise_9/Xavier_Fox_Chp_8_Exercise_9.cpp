/* Program: Xavier_Fox_Chp_8_Exercise_9.cpp
   Programmer: Xavier Fox
   Date: 24 Nov. 2014
   Purpose: To determine the highest and lowest temp.
   for the year and to determine the average high
   and low temp.
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int NUMOFROWS = 12;
const int NUMOFCOLS = 2;

void getData(int temperature[][NUMOFCOLS]);
int averageHigh(const int temperature[][NUMOFCOLS]);
int averageLow(const int temperature[][NUMOFCOLS]);
int indexHighTemp(const int temperature[][NUMOFCOLS]);
int indexLowTemp(const int temperature[][NUMOFCOLS]);

int main()
{
	int temperature[NUMOFROWS][NUMOFCOLS];

	getData(temperature);
	cout << "The average high temperature is: "
		 << averageHigh(temperature) << endl;
	cout << "The average low temperature is: " 
		 << averageLow(temperature) << endl;

	cout << "The highest temperature of the year is: "
		 << temperature[indexHighTemp(temperature)][0] << endl;

	cout << "The lowest temperature of the year is: "
		 << temperature[indexLowTemp(temperature)][1] << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

//Reads and stores the data in a two-dimensional array
void getData(int temperature[][NUMOFCOLS])
{
	for (int c = 0; c < NUMOFCOLS; c++)
	{
		if (c == 0)
			cout << "Enter high temperatures for each month: " << endl;
		else
			cout << "Enter low temperatures for each month: " << endl;

		cout << "   ";

		for (int r = 0; r < NUMOFROWS; r++)
			cin >> temperature[r][c];

		cout << endl;
	}

	cout << endl;
}

//Returns the average high temp. for the year.
int averageHigh(const int temperature[][NUMOFCOLS])
{
	int sum, avgHigh;

	for (int c = 0; c < 1; c++)
	{
		sum = 0;
		for (int r = 0; r < NUMOFROWS; r++)
			sum += temperature[r][c];
	}

	avgHigh = sum / 12;

	return avgHigh;
}

//Returns the average low temp for the year.
int averageLow(const int temperature[][NUMOFCOLS])
{
	int sum, avgLow;

	for (int c = 1; c < NUMOFCOLS; c++)
	{
		sum = 0;
		for (int r = 0; r < NUMOFROWS; r++)
			sum += temperature[r][c];
	}

	avgLow = sum / 12;

	return avgLow;
}

//Returns the index of the highest temp.
int indexHighTemp(const int temperature[][NUMOFCOLS])
{
	int highestTemp = 0;
	int highestTempIndex = 0;

	for (int c = 0; c <= 1; c++)
	{
		for (int r = 0; r < NUMOFROWS; r++)
			if (temperature[r][c] > highestTemp)
			{
				highestTemp = temperature[r][c];
				highestTempIndex = r;
			}
	}

	return highestTempIndex;
}

//Returns the index of the lowest temp.
int indexLowTemp(const int temperature[][NUMOFCOLS])
{
	int lowestTemp = 0;
	int lowestTempIndex = 0;

	for (int c = 1; c < NUMOFCOLS; c++)
	{
		for (int r = 0; r < NUMOFROWS; r++)
		{
			if (temperature[r][c] < lowestTemp)
			{
				lowestTemp = temperature[r][c];
				lowestTempIndex = r;
			}
		}
	}

	return lowestTempIndex;
}