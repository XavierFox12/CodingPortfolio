/* Program: invalidMonth.h
   Programmer: Xavier Fox
   Date: 23 Mar. 2015
   Purpose: Catches the month error
*/

#include <iostream>
#include <string>

using namespace std;

class invalidMonth
{
private:
	string message;

public:
	invalidMonth()
	{
		message = "Month must be between 1 and 12.";
	}

	invalidMonth(int)
	{
		message = "Month must be numeric.";
	}

	invalidMonth(string str)
	{
		message = str;
	}

	string what()
	{
		return message;
	}
};