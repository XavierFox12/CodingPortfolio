/* Program: invalidMin.h
   Programmer: Xavier Fox
   Date: 17 Mar. 2015
   Purpose: catches the minutes error message
*/

#include <iostream>
#include <string>

class invalidMin
{
private:
	string message;

public:
	invalidMin()
	{
		message = "   The value of minutes must range 0 to 59.";
	}

	invalidMin(string str)
	{
		message = str;
	}

	string what()
	{
		return message;
	}
};