/* Program: doctorType.h
   Programmer: Xavier Fox
   Date: 30 Jan. 2015
   purpose: Establishes the members of the doctorType class
*/
#ifndef H_doctorType
#define H_doctorType

#include "stdafx.h"
#include "personType.h"
#include <iostream>
#include <string>

using namespace std;

class doctorType:public personType
{
private:
	string doctorSpeciality;
public:
	void print() const;
	void setSpeciality(string speciality);
	string getSpeciality() const;
	doctorType(string fName="", string lName="", string speciality="");
};
#endif