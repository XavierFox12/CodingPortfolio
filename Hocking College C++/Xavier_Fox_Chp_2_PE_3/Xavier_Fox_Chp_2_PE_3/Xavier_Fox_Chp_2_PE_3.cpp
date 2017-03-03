/* Program: Xavier_Fox_Chp_2_PE_3.cpp
   Programmer: Xavier Fox
   Date: 8 Sep. 2014
   Purpose: To display 3 numbers and to determine
   the average using the int declaration.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	//Variable declaration
	int num1, num2, num3; 
	int average;
	num1 = 125;
	num2 = 28;
	num3 = -25;

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

