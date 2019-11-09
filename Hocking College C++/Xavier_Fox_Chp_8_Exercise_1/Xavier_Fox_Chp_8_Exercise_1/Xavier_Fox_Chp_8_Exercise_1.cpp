/* Program: Xavier_Fox_Chp_8_Exercise_1.cpp
   Programmer: Xavier Fox
   Date: 17 Nov. 2014
   Purpose: To print out 10 elements per line, and
   print out the first 25 elements squared and the rest
   of the elements are multiplied by 3.
*/

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const int SIZE = 50;

void initialize(double alpha[], int i);
void printArray(const double alpha[], int i);

int main()
{
	double alpha[SIZE];
	int i = 0;

	for (i = 0; i <= 49; ++i)
	{
		initialize(alpha, i);
		printArray(alpha, i);
	}

	cout << endl << endl << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

void initialize(double alpha[], int i)
{
	if (i < 25)
		alpha[i] = pow(i, 2.0);
	else
		alpha[i] = i * 3;
}

void printArray(const double alpha[], int i)
{
	if (i % 10 == 0 && i > 0)
		cout << endl;

	cout << setw(4) << alpha[i] << " ";
}