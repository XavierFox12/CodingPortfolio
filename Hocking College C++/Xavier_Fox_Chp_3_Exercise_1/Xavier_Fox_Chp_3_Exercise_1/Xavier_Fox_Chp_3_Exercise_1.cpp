/* Program: Xavier_Fox_Chp_3_Exercise_1.cpp
   Programmer: Xavier Fox
   Date: 22 Sep. 2014
   Purpose: To take the data from inData.txt and 
   move it to outData.txt and determine paycheck,
   averageSpeed, and salesAmount.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	string firstName, lastName, department;
	double monthlyGrossSalary, bonus, taxes,
		   distanceTravled, travelingTime,
		   coffeeSold, coffeeCost, paycheck,
		   averageSpeed, salesAmount, netPay;

	ifstream inFile;
	ofstream outFile;

	inFile.open("E:\\C++\\inData.txt");
	if (!inFile)
	{
		cout << "Cannot find inData.txt" << endl
			 << "The program terminates" << endl << endl;
		return 1;
	}
	outFile.open("E:\\C++\\outData.txt");

	inFile >> firstName >> lastName >> department >> monthlyGrossSalary
		   >> bonus >> taxes >> distanceTravled
		   >> travelingTime >> coffeeSold >> coffeeCost;

	netPay = (bonus / 100) * monthlyGrossSalary + monthlyGrossSalary;
			  
	paycheck = netPay - ((taxes / 100) * netPay);

	averageSpeed = distanceTravled / travelingTime;

	salesAmount = coffeeSold * coffeeCost;

	outFile << fixed << showpoint << setprecision(2);

	outFile << "Name: " << firstName << lastName << ", Department: " << department
		    << endl << "Monthly Gross Salary: $" << monthlyGrossSalary
		    << ", Monthly Bonus: " << bonus << "%, Taxes: " << taxes
			<< "%" << endl << "Paycheck: $" << paycheck << endl << endl;

	outFile << "Distance Traveled: " << distanceTravled
		    << "miles, Traveling Time: " << travelingTime << " hours"
		    << endl << "Average Speed: " << averageSpeed
		    << " miles per hour" << endl << endl;

	outFile << "Number of Coffee Cups Sold: " << coffeeSold
			<< ", Cost: $" << coffeeCost << " per cup" << endl
			<< "Sales Amount = $" << salesAmount << endl << endl;

	outFile << "Program by: Xavier Fox" << endl << endl;

	inFile.close();
	outFile.close();
	return 0;
}

