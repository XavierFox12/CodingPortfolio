/* Program: Xavier_Fox_Chp_10_Exercise_1.cpp
   Programmer: Xavier Fox
   Date: 12 Jan. 2015
   Purpose: To determine the users grade based upon
   their test score and programming score.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "studentType.h"

using namespace std;

int main()
{
	studentType student1;
	studentType student2("Brian","Johnson",85,95,3.89);
	studentType student3, student4;

	string fName, lName;
	int test, programming;
	double currentGPA;

	// Input for student 3 (student3)
	cout << "Input for student three:" << endl;
	cout << "    Enter student's first and last name: ";
	cin >> fName >> lName;

	cout << "    Enter student's test and programming scores: ";
	cin >> test >> programming;

	cout << "    Enter student's current GPA: ";
	cin >> currentGPA;
	cout << endl;

	student3.setData(fName, lName, test, programming, currentGPA);


	// Input for student 4 (student4)
	cout << "Input for student four:" << endl;
	cout << "    Enter student's first and last name: ";
	cin >> fName >> lName;

	cout << "    Enter student's test and programming scores: ";
	cin >> test >> programming;

	cout << "    Enter student's current GPA: ";
	cin >> currentGPA;

	student4.setFirstName(fName);
	student4.setLastName(lName);
	student4.setTestScore(test);
	student4.setProgScore(programming);
	student4.setGrade();
	student4.setGPA(currentGPA);

	// Output students information
	cout << fixed << showpoint << setprecision(2)<< endl << endl;
	student1.print();
	cout << "******************" << endl << endl;

	student2.print();
	cout << "******************" << endl << endl;

	student3.print();
	cout << "******************" << endl << endl;

	cout << "Name: " << student4.getFirstName() << " " << student4.getLastName()
		 << endl;
	cout << "Grade: " << student4.getGrade() << endl;
	cout << "Test Score: " << student4.getTestScore() << endl;
	cout << "Programming Score: " << student4.getProgScore() << endl;
	cout << "GPA: " << student4.getGPA() << endl;
	cout << "******************" << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

