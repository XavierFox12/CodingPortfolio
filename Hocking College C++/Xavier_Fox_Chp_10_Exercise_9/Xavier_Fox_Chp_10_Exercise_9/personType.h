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
	string middleName;
	string lastName;
public:
	void print() const;
	void setName(string fName, string middleName, string lName);
	void setFirstName(string fName);
	void setMiddleName(string mName);
	void setLastName(string lName);
	string getFirstName() const;
	string getMiddleName() const;
	string getLastName() const;
	bool isFirstEqual(const personType& otherStudent) const;
	bool isLastEqual(const personType& otherStudent) const;
	personType(string fName="", string mName="", string lName="");
};