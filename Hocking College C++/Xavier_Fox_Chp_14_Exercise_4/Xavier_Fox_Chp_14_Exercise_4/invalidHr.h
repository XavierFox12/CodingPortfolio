/* Program: invalidHr.h
   Programmer: Xavier Fox
   Date: 17 Mar. 2015
   Purpose: catches the hours error message
*/

#include <iostream>
#include <string>

using namespace std;

class invalidHr
{
private:
	string message;

public:
	invalidHr()
	{
		message = "   The value of hours must range 0 to 12.";
	}

	invalidHr(string str)
	{
		message = str;
	}

	string what()
	{
		return message;
	}
};