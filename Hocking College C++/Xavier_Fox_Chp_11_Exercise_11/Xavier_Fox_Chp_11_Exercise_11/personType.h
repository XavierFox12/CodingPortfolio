/* Program: personType.h
   Programmer: Xavier Fox
   Date: 21 Jan. 2015
   purpose: Establishes the members of the personType class
*/

#include <iostream>
#include <string>

using namespace std;

class personType
{
private:
	string firstName;
	string lastName;
public:
	void print() const;
	void setName(string fName, string lName);
	void setFirstName(string fName);
	void setLastName(string lName);
	string getFirstName() const;
	string getLastName() const;
	personType(string fName="", string lName="");
};