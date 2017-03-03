/* Program: Xavier_Fox_Chp_2_Exercise_6.cpp
   Programmer: Xavier Fox
   Date: 9 Sep. 2014
   Purpose: To display the users first name and
   the amount of hours he or she needs to study.
*/

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string name;
	double studyHours;

	cout << "Enter first name: ";
	cin >> name;
	cout << endl;

	cout << "Enter study hours: ";
	cin >> studyHours;

	cout << endl << "Hello, " << name
		 << "! On Saturday, you need to study " << studyHours
		 << " hours for the exam." << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

