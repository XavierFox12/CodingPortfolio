/* Program: invalidSec.h
   Programmer: Xavier Fox
   Date: 17 Mar. 2015
   Purpose: catches the seconds error message.
*/

#include <iostream>
#include <string>

class invalidSec
{
private:
	string message;

public:
	invalidSec()
	{
		message = "   The value of seconds must range 0 to 59.";
	}

	invalidSec(string str)
	{
		message = str;
	}

	string what()
	{
		return message;
	}
};