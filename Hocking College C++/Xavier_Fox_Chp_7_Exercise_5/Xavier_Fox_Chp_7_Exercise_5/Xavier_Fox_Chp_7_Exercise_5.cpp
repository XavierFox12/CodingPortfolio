/* Program: Xavier_Fox_Chp_7_Exercise_5.cpp
   Programmer: Xavier Fox
   Date: 10 Nov. 2014
   Purpose: Determines the federal tax amount.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

void getData(int& children, double& grossSalary, double& percentage,
			 char& maritalStatus);
double taxAmount(int children, char maritalStatus, double grossSalary,
				 double percentage);

int main()
{
	int children;
	double grossSalary, percentage;
	char maritalStatus, yesOrNo = 'y';

	cout << showpoint << fixed << setprecision(2);

	cout << setw(50) << "Calculating Federal Tax" << endl
		 << setw(50) << "Program by:  Xavier Fox" << endl << endl;

	while (yesOrNo == 'y')
	{
		getData(children, grossSalary, percentage, maritalStatus);
		cout << "Your tax for the year is: "
			 << taxAmount(children, maritalStatus, grossSalary, percentage)
			 << endl << endl;

		cout << "Do you wish to continue? (y/n) ";
		cin >> yesOrNo;
		cout << endl;
	}
	return 0;
}

void getData(int& children, double& grossSalary, double& percentage,
			 char& maritalStatus)
{
	cout << "Enter your marital status: m (married) s (single) ";
	cin >> maritalStatus;
	cout << endl;

	if (maritalStatus == 'm')
	{
		cout << "Enter the number of children under the age of 14: ";
		cin >> children;
		cout << endl;
	}
	cout << "Enter the gross salary: ";
	cin >> grossSalary;
	cout << endl;

	cout << "Enter the percentage of gross income(between 0 and 6): ";
	cin >> percentage;
	cout << endl;
}

double taxAmount(int children, char maritalStatus, double grossSalary,
				 double percentage)
{
	double overallTax, pensionPlan;
	int standExem, personalExem;

	pensionPlan = grossSalary * (percentage / 100);

	if (maritalStatus == 'm')
		standExem = 7000;

	else
		standExem = 4000;

	if (children >= 2)
		personalExem = 1500 * (children + 2);

	else if (maritalStatus == 'm')
		personalExem = 1500 * (children + 2);

	else
		personalExem = 1500;

	if (grossSalary > 0 && grossSalary < 15000)
		overallTax = (grossSalary - (standExem + personalExem + pensionPlan))
		* .15;

	else if (grossSalary < 40000)
		overallTax = ((grossSalary - 15000) - (standExem + personalExem + pensionPlan))
		* .25 + 2250;

	else
		overallTax = ((grossSalary - 40000) - (standExem + personalExem + pensionPlan))
		* .35 + 8460;

	return overallTax;
}

