/* Program: Xavier_Fox_Chp_10_Exercise_9.cpp
   Programmer: Xavier Fox
   Date: 21 Jan. 2015
   Purpose: To print off student's names and 
   to determine if they share the same name to
   another student
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include "personType.h"

using namespace std;

int main()
{
	personType englishStudent("Thomas", "Louis", "Jones");
	personType mathStudent, cppStudent;
	string first, middle, last;

	cout << "Enter Math student's first, middle, and last name: ";
	cin >> first >> middle >> last;
	mathStudent.setName(first, middle, last);

	cout << "Enter C++ student's first, middle, and last name: ";
	cin >> first >> middle >> last;
	cout << endl;
	cppStudent.setFirstName(first);
	cppStudent.setMiddleName(middle);
	cppStudent.setLastName(last);

	cout << "Current Values:" << endl;

	englishStudent.getFirstName();
	englishStudent.getMiddleName();
	englishStudent.getLastName();
	cout << "   English Student: ";
	englishStudent.print();
	cout << endl;

	mathStudent.getFirstName();
	mathStudent.getMiddleName();
	mathStudent.getLastName();
	cout << "   Math Student: ";
	mathStudent.print();
	cout << endl;

	cppStudent.getFirstName();
	cppStudent.getMiddleName();
	cppStudent.getLastName();
	cout << "   C++ Student: ";
	cppStudent.print();
	cout << endl << endl;

	cout << "Comparing English and Math student names:" << endl;

	if (englishStudent.isFirstEqual(mathStudent))
		cout << "   Student's first names are the same" << endl;
	else
		cout << "   Student's first names are different" << endl;

	if (englishStudent.isLastEqual(mathStudent))
		cout << "   Student's last names are the same" << endl << endl;
	else
		cout << "   Student's last names are different" << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

