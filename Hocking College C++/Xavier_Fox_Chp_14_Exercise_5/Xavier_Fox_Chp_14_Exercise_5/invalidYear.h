/* Program: invalidYear.h
   Programmer: Xavier Fox
   Date: 23 Mar. 2015
   Purpose: Catches the year error
*/

#include <iostream>
#include <string>

using namespace std;

class invalidYear
{
private:
	string message;

public:
	invalidYear()
	{
		message = "Year must be nonnegative";
	}

	invalidYear(int)
	{
		message = "Year must be numeric.";
	}

	invalidYear(string str)
	{
		message = str;
	}

	string what()
	{
		return message;
	}
};