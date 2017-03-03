// studentTypeImp.cpp

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "studentType.h"

using namespace std;

void studentType::setData(string fn, string ln, int tScore, int prgScore, double gpa)
{
	firstName = fn;
	lastName = ln;
	testScore = tScore;
	programmingScore = prgScore;
	GPA = gpa;
	setGrade();
}

void studentType:: setFirstName(string fn)
{
	firstName = fn;
}

void studentType:: setLastName(string ln)
{
	lastName = ln;
}

void studentType:: setTestScore(int tScore)
{
	testScore = tScore;
}

void studentType:: setProgScore(int prgScore)
{
	programmingScore = prgScore;
}

void studentType:: setGPA(double gpa)
{
	GPA = gpa;
}

void studentType:: setGrade()
{
	int score = (testScore + programmingScore) / 2;

	if (score >= 90)
		courseGrade = 'A';
	else if (score >= 80)
		courseGrade = 'B';
	else if (score >= 70)
		courseGrade = 'C';
	else if (score >= 60)
		courseGrade = 'D';
	else
		courseGrade = 'F';
}

string studentType:: getFirstName() const
{
	return firstName;
}

string studentType:: getLastName() const
{
	return lastName;
}

char studentType:: getGrade() const
{
	return courseGrade;
}

int studentType:: getTestScore() const
{
	return testScore;
}

int studentType:: getProgScore() const
{
	return programmingScore;
}

double studentType:: getGPA() const
{
	return GPA;
}

void studentType:: print() const
{
	cout << fixed << showpoint << setprecision(2);

	cout << "Name: " << firstName << " " << lastName << endl;
	cout << "Grade: " << courseGrade << endl;
	cout << "Test Score: " << testScore << endl;
	cout << "Programming Score: " << programmingScore << endl;
	cout << "GPA: " << GPA << endl;
}

studentType:: studentType(string fn, string ln, int tScore, int prgScore,
						  double gpa, char grade)
{
	firstName = fn;
	lastName = ln;
	testScore = tScore;
	programmingScore = prgScore;
	GPA = gpa;
	setGrade();
}