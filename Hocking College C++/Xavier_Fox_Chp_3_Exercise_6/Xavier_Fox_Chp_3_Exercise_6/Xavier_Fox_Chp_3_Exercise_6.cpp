/* Program: Xavier_Fox_Chp_3_Exercise_6.cpp
   Programmer: Xavier Fox
   Date: 23 Sep. 2014
   Purpose: To determine the pay increase of each
   employee.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string fName, lName;
	double currentSalary, payIncrease, overallSalary;

	ifstream inFile;
	ofstream outFile;
	inFile.open("E:\\C++\\Ch3_Ex6Data.txt");
	if (!inFile)
	{
		cout << "Cannot open the file Ch3_Ex6Data.txt" << endl
			 << "The program terminates" << endl << endl;
		return 1;
	}
	outFile.open("E:\\C++\\Ch3_Ex6Output.dat");

	inFile >> lName >> fName >> currentSalary >> payIncrease;

	while (inFile)
	{
		outFile << fixed << showpoint << setprecision(2);

		overallSalary = currentSalary + (currentSalary * (payIncrease / 100));

		outFile << fName << " " << lName << " " << overallSalary << endl;

		inFile >> lName >> fName >> currentSalary >> payIncrease;
	}

	inFile.close();
	outFile.close();

	return 0;
}

