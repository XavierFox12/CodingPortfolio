/* Program: invalidDay.h
   Programmer: Xavier Fox
   Date: 23 Mar. 2015
   Purpose: catches the day error
*/

#include <iostream>
#include <string>

using namespace std;

class invalidDay
{
private:
	string message;

public:
	invalidDay()
	{
		message = "Day must be numeric";
	}

	invalidDay(int d)
	{
		if (d == 31)
			message = "Day must be between 1 and 31";
		else if (d == 30)
			message = "Day must be between 1 and 30";
		else if (d == 29)
			message = "Day must be between 1 and 29";
		else
			message = "Day must be between 1 and 28";
	}

	invalidDay(string str)
	{
		message = str;
	}

	string what()
	{
		return message;
	}
};