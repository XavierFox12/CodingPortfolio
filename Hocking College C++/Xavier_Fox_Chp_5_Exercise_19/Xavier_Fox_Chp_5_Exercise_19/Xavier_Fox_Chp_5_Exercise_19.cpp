/* Program: Xavier_Fox_Chp_5_Exercise_19.cpp
   Programmer: Xavier Fox
   Date: 21 Oct. 2014
   Purpose: To determine who sold the most boxes, and to
   determine how much those people will donate to their charity.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const double DONATION = .1;
int main()
{
	double oneBoxCost, totalBefore = 0, totalAfter, 
		   charityDonation, totalCharityDonation = 0;
	int boxesSold, totalBoxesSold = 0, numOfVolunteers = 0,
		maximumBoxesSold = 0, averageSold;
	string names;

	ifstream inFile;

	inFile.open("E:\\C++\\Chp19Data.txt");
	if (!inFile)
	{
		cout << "Cannot find Chp19Data.txt" <<endl
			 << "The program terminates" << endl << endl;
		return 1;
	}

	cout << fixed << showpoint << setprecision(2);

	inFile >> oneBoxCost >> names >> boxesSold;

	while (inFile)
	{
		totalBefore += boxesSold * oneBoxCost;
		totalBoxesSold += boxesSold;
		numOfVolunteers++;
		if (boxesSold > maximumBoxesSold)
		{
			maximumBoxesSold = boxesSold;
			charityDonation = (oneBoxCost * boxesSold) * DONATION;
		}

		inFile >> names >> boxesSold;
	}
	averageSold = totalBoxesSold / numOfVolunteers;

	cout << "Total number of boxes sold: " << totalBoxesSold
		 << endl << endl;
	cout << "The total money made by selling cookies before donating to charity: $"
		 << totalBefore << endl << endl;
	cout << "The average number of boxes sold by each volunteer: "
		 << averageSold << endl << endl;
	cout << "The maximum number of boxes sold by an individual student: "
		 << maximumBoxesSold << endl << endl;
	cout << "The amount donated to each charity is: " << charityDonation
		 << endl << endl;

	inFile.close();
	inFile.clear();

	inFile.open("E:\\C++\\Chp19Data.txt");

	inFile >> oneBoxCost >> names >> boxesSold;

	cout << "The names of students selling the maximum number of boxes are:"
		 << endl;

	while (inFile)
	{
		if (boxesSold >= maximumBoxesSold)
		{
			charityDonation = (oneBoxCost * boxesSold) * DONATION;
			totalCharityDonation += charityDonation;
			cout << "     " << names << endl;
		}
		inFile >> names >> boxesSold;
	}

	totalAfter = totalBefore - totalCharityDonation;

	cout << endl << "The total money donated to charity: $"
		 << totalCharityDonation << endl << endl;
	cout << "The net money made from selling cookies: $" << totalAfter 
		 << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	inFile.close();
	return 0;
}

