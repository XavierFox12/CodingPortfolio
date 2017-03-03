/* Program: Xavier_Fox_Chp_6_Exercise_23.cpp
   Programmer: Xavier Fox
   Date: 6 Nov. 2014
   Purpose: To determine the price of a membership
   given the users info.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

void generalInfo();
void getInfo(double& regularMembership, double& sessionCost, char& senior,
			   int& numOfSessions, int& numOfMonths);
double membershipCost(double regularMembership, double sessionCost, char senior,
					  int numOfSessions, int numOfMonths);

int main()
{
	double regularMembership, sessionCost, totalMembershipCost;
	int numOfSessions, numOfMonths;
	char senior;

	generalInfo();
	getInfo(regularMembership, sessionCost, senior, numOfSessions,
			numOfMonths);
	totalMembershipCost = 
		membershipCost(regularMembership, sessionCost, senior, numOfSessions,
		numOfMonths);

	cout << showpoint << fixed << setprecision(2);

	cout << "The membership cost = $" << totalMembershipCost << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

void generalInfo()
{
	cout << setw(65) << "Welcome to the Stay Healthy and Fit Center" << endl
		 << setw(65) << "        Program by: Xavier Fox            " 
		 << endl << endl;
	cout << "This program determines the cost of a new membership."
		 << endl << endl;

	cout << "Discounts:" << endl
		 << " -30% for the senior citizens discount" << endl
		 << " -15% if the membership is bought and paid for 12 or more "
		 << "months." << endl
		 << " -20% if more than five personal training sessions are bought "
		 << "and paid for."
		 << endl << endl;
}

void getInfo(double& regularMembership, double& sessionCost, char& senior,
			   int& numOfSessions, int& numOfMonths)
{
	cout << "Enter the cost of a regular membership: ";
	cin >> regularMembership;
	cout << endl;

	cout << "Enter the cost of one session: ";
	cin >> sessionCost;
	cout << endl;

	cout << "Are you a senior citizen? (y/n) ";
	cin >> senior;
	cout << endl;

	cout << "Enter the number of sessions you are taking: ";
	cin >> numOfSessions;
	cout << endl;

	cout << "Enter the number of months paid for: ";
	cin >> numOfMonths;
	cout << endl;
}

double membershipCost(double regularMembership, double sessionCost, 
					  char senior, int numOfSessions, int numOfMonths)
{
	double totalMembershipCost;

	totalMembershipCost = regularMembership * numOfMonths;

	if (senior == 'y')
		totalMembershipCost = totalMembershipCost - (totalMembershipCost * .3);
	if (numOfMonths >= 12)
		totalMembershipCost = totalMembershipCost - (totalMembershipCost * .15);
	if (numOfSessions > 5)
	{
		totalMembershipCost = totalMembershipCost - (numOfSessions *
							  sessionCost * .2);
	}
	totalMembershipCost += sessionCost * numOfSessions;

	return totalMembershipCost;
}
