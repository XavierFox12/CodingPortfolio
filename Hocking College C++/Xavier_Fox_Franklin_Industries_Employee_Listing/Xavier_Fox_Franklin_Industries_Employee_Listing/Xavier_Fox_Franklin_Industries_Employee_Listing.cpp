/* Program: Xavier_Fox_Franklin_Industries_Employee_Listing.cpp
   Programmer: Xavier Fox
   Date: 27 Apr. 2015
   Purpose: Print out the employees names for each
   department for Franklin industries.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void sortEmployees(vector<string>& department, vector<string>& fullName, int nameSize);
void print(vector<string> department, vector<string> fullName, int nameSize);

int main()
{
	vector<string> department;
	vector<string> fullName;
	string name, fName, lName, dept;
	ifstream inFile;

	inFile.open("E:\\SP2015\\C++\\employees.txt");
	if (!inFile)
	{
		cout << "Cannot find employees.txt" << endl
			 << "  The Program terminates " << endl << endl;
		return 1;
	}

	inFile >> fName >> lName >> dept;

	while (inFile)
	{
		name = lName +", "+ fName;
		fullName.push_back(name);
		department.push_back(dept);
		inFile >> fName >> lName >> dept;
	}
	inFile.close();

	int size = fullName.size();

	sortEmployees(department, fullName, size);
	print(department, fullName, size);

	return 0;
}

// sorts the departments and employees
void sortEmployees(vector<string>& department, vector<string>& fullName, int nameSize)
{
	string nameTemp;
	string deptTemp;
	int iteration;
	int index;
	
	// sorts the names
	for (iteration = 1; iteration < nameSize; iteration++)
	{
		for (index = 0; index < nameSize - iteration; index++)
			if (fullName[index] > fullName[index + 1])
			{
				nameTemp = fullName[index];
				fullName[index] = fullName[index + 1];
				fullName[index + 1] = nameTemp;
				deptTemp = department[index];
				department[index] = department[index + 1];
				department[index + 1] = deptTemp;
			}
	}

	// sorts the departments
	for (iteration = 1; iteration < nameSize; iteration++)
	{
		for (index = 0; index < nameSize - iteration; index++)
			if (department[index] > department[index + 1])
			{
				nameTemp = fullName[index];
				fullName[index] = fullName[index + 1];
				fullName[index + 1] = nameTemp;
				deptTemp = department[index];
				department[index] = department[index + 1];
				department[index + 1] = deptTemp;
			}
	}
}

// prints out the employees names and their departments
void print(vector<string> department, vector<string> fullName, int size)
{
	ofstream outFile;
	string departmentPrint = "";

	outFile.open("E:\\SP2015\\C++\\employeesOut.txt");

	outFile << setw(36) << "Franklin Industries" << endl
		    << setw(36) << "  Employee Listing " << endl
			<< setw(36) << "    By Department  " << endl << endl;
	outFile << "\tDepartment \t \t Employee Name" << endl;

	for (int i = 0; i < size; i++)
	{
		if (department[i] == departmentPrint)
			outFile << "\t \t \t \t " << fullName[i] << endl;
		else
		{
			departmentPrint = department[i];
			outFile << endl << "\t" << department[i] << "\t \t "
				    << fullName[i] << endl;
		}
	}

	outFile << endl << endl << "\t \t \t \t " << "Program by: Xavier Fox"
		    << endl << endl;

	outFile.close();
}