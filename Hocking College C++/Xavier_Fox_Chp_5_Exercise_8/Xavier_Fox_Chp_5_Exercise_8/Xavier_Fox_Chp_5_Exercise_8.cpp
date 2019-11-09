/* Program: Xavier_Fox_Chp_5_Exercise_8.cpp
   Programmer: Xavier Fox
   Date: 20 Oct. 2014
   Purpose: To determine all the odd numbers between the first number
   and second number, output the sum of all the even numbers,
   the squares between 1 and 10, the sum of the square of the odd
   numbers between the first and second number, and output all the
   uppercase letters.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	int firstNum, secondNum, sum = 0,
		squaredSum = 0, squaredNumber, i;
	char upperCaseLetter = 'A';

	cout << "Enter two integers: ";
	cin >> firstNum >> secondNum;
	cout << endl;

	while (firstNum >= secondNum)
	{
		cout << "The second number must be greater than the first number"
			 << endl << endl;
		cout << "Enter two integers: ";
		cin >> firstNum >> secondNum;
		cout << endl;
	}

	cout << "Odd integers between " << firstNum << " and " << secondNum
		 << " are: ";

	do
	{
		if (firstNum % 2 == 0)
			sum += firstNum;
		else
		{
			squaredSum += pow(firstNum, 2.0);
			cout << firstNum << " ";
		}

		firstNum += 1;
	}
	while (firstNum <= secondNum);

	cout << endl << endl << "Even Sum: " << sum << endl;

	cout << setw(25) << "Number" << setw(45) << "Square of Number"
		 << endl;

	for (i = 1; i <= 10; i++)
	{
		squaredNumber = pow(i, 2.0);
		cout << setw(23) << i << setw(40) << squaredNumber << endl;
	}

	cout << endl << "Squared Sum: " << squaredSum << endl << endl;

	cout << "Uppercase letters are: ";

	do 
	{
		cout << upperCaseLetter << " ";
		upperCaseLetter++;
	}
	while (upperCaseLetter <= 'Z');


	cout << endl << endl << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

