/* Program: personTypeImp.cpp
   Programmer: Xavier Fox
   Date: 21 Jan. 2015
   Purpose: Defines the members of the personType class
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include "personType.h"

using namespace std;

// prints first, middle, and last name
void personType::print() const
{
	cout << firstName << " " <<lastName;
}

// sets the first, middle and last name
void personType::setName(string fName, string lName)
{
	firstName = fName;
	lastName = lName;
}

// sets the first name
void personType::setFirstName(string fName)
{
	firstName = fName;
}

// sets the last name
void personType::setLastName(string lName)
{
	lastName = lName;
}

// gets the first name
string personType::getFirstName() const
{
	return firstName;
}

// gets the last name
string personType::getLastName() const
{
	return lastName;
}

// personType constructor
personType::personType(string fName, string lName)
{
	firstName = fName;
	lastName = lName;
}