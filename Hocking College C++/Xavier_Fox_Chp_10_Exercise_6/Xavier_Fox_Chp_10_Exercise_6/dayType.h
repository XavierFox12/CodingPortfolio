/* dayType.h
   Name: Xavier Fox
   Date: 14 Jan. 2015
   Purpose: Establishes the members of the class
   dayType
*/

#ifndef H_dayType
#define H_dayType

#include <string>

using namespace std;

class dayType
{
private:
	string dayOfWeek;
	
public:
	void setDay(string day);
	void printDay() const;
	string getDay() const;
	string getNextDay() const;
	string getPrevDay() const;
	void getCertainDay(int numOfdays);
	dayType();
	dayType(string day);
};

#endif