/* Program: Xavier_Fox_Chp_6_Exercise_14.cpp
   Programmer: Xavier Fox
   Date: 4 Nov. 2014
   Purpose: Determines the value for x, y, and z. It also determines
   the salary amount given the hours worked and their pay rate.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

void initialize(int& x, int& y, char& z);
void hoursRate(double& hours, double& rate);
double payCheck(double hours, double rate);
void printCheck(double hours, double rate, double amount);
void funcOne(int& x, int y);
void nextChar(char& z);

int main()
{
	int x, y;
	char z;
	double rate, hours;
	double amount;

	cout << showpoint << fixed << setprecision(2);

	initialize(x, y, z);
	hoursRate(hours, rate);
	amount = payCheck(hours, rate);
	printCheck(hours, rate, amount);

	x = 35;
	y = 20;
	cout << "Before calling funcOne: x = " << x << ", y = "
		 << y << endl << endl;
	funcOne(x, y);
	cout << "After funcOne: x = " << x << endl << endl;

	z = 'B';
	nextChar(z);
	cout << "After nextChar: z = " << z << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

// initializes x y and z
void initialize(int& x, int& y, char& z)
{
	x = 0;
	y = 0;
	z = ' ';

	cout << "After initialization: x = " << x 
		 << ", y = " << y << ", z = " << z
		 << endl << endl;
}

// askes the user for hours worked and pay rate
void hoursRate(double& hours, double& rate)
{
	cout << "Enter hours worked: ";
	cin >> hours;

	cout << "Enter pay rate: ";
	cin >> rate;
}

// calculates the amount to be paid
double payCheck(double hours, double rate)
{
	double salary;

	if (hours > 40)
		salary = 1.5 * rate * (hours - 40) + (40 * rate);
	else
		salary = hours * rate;
	
	return salary;
}

// prints out the salary.
void printCheck(double hours, double rate, double amount)
{
	cout << "Hours worked:       " << hours << endl
		 << "Pay rate:           $" << rate << endl;

		cout << "This week's salary: $" << amount << endl << endl;
}

// Askes the user to enter and integer and changes the value of x.
void funcOne(int& x, int y)
{
	int integer;

	cout << "Enter an integer: ";
	cin >> integer;
	cout << endl;

	x = 2 * x + y - integer;
}

// Determines the next character for z
void nextChar(char& z)
{
	cout << "z = " << z << endl;

	z = z + 1;
}