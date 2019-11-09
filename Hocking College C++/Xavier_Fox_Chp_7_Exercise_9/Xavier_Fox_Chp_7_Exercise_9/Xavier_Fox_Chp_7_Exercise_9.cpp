/* Program: Xavier_Fox_Chp_7_Exercise_9.cpp
   Programmer: Xavier Fox
   Date: 13 Nov. 2014
   Purpose: To alter the names given in a file by converting them
   to first name middle name last name.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

string alterName(string fullName);

int main()
{
	string fullName;

	ifstream inFile;
	ofstream outFile;

	inFile.open("E:\\C++\\Ch7_Ex9In.txt");
	if (!inFile)
	{
		cout << "Cannot find Ch7_Ex9.txt" << endl
			 << "The program terminates" << endl << endl;
		return 1;
	}
	outFile.open("E:\\C++\\Ch7_Ex9Out.txt");

	outFile << setw(50) << " Xavier Fox Conversion " << endl
		    << setw(50) << "Program by:  Xavier Fox" << endl << endl;

	getline(inFile, fullName);

	while (inFile)
	{
		outFile << setw(30) << "" << left << alterName(fullName)
			    << endl;

		getline(inFile, fullName);
	}

	inFile.close();
	outFile.close();
	return 0;
}

string alterName(string fullName)
{
	int len, index;
	string lastName, firstMiddle;

	len = fullName.length();
	index = fullName.find(',');
	lastName = fullName.substr(0, index);
	firstMiddle = fullName.substr(index + 2, len);
	return firstMiddle + ' ' + lastName;
}