/* Program: Xavier_Fox_Chp_2_PE_4.cpp
   Programmer: Xavier Fox
   Date: 8 Sep. 2014
   Purpose: To display 3 numbers and to determine
   the average using the double declaration.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	//Variable declaration
	double num1, num2, num3, average;
	num1 = 75.35;
	num2 = -35.56;
	num3 = 15.76;

	//executable statements
	average = (num1 + num2 + num3) / 3;

	//return statement
	cout << "Num1 = " << num1 << endl
		 << "Num2 = " << num2 << endl
		 << "Num3 = " << num3 << endl
		 << "Average = " << average << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;
	return 0;
}

