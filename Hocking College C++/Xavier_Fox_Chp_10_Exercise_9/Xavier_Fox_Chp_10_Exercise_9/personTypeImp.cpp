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
	cout << firstName << " " << middleName << " " <<lastName;
}

// sets the first, middle and last name
void personType::setName(string fName, string mName, string lName)
{
	firstName = fName;
	middleName = mName;
	lastName = lName;
}

// sets the first name
void personType::setFirstName(string fName)
{
	firstName = fName;
}

// sets the middle name
void personType::setMiddleName(string mName)
{
	middleName = mName;
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

//gets the middle name
string personType::getMiddleName() const
{
	return middleName;
}

// gets the last name
string personType::getLastName() const
{
	return lastName;
}

// Determines if two first names are the same
bool personType::isFirstEqual(const personType& otherStudent) const
{
	return (firstName == otherStudent.firstName);
}

// Determines if two last names are equal
bool personType::isLastEqual(const personType& otherStudent) const
{
	return (lastName == otherStudent.lastName);
}

// personType constructor
personType::personType(string fName, string mName, string lName)
{
	firstName = fName;
	middleName = mName;
	lastName = lName;
}