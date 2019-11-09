/* Program: extClockType.h
   Programmer: Xavier Fox
   Date: Jan. 23 2015
   Purpose: 
*/

#ifndef H_ExtClockType
#define H_ExtClockType

#include <string>
#include "clockType.h"

using namespace std;

class extClockType:public clockType
{
private:
	string timeZone;

public:
	void setTime(int hours, int minutes, int seconds, string tZone);
	void printTime();
	extClockType(int = 0, int = 0, int = 0, string = "EST");
};

#endif