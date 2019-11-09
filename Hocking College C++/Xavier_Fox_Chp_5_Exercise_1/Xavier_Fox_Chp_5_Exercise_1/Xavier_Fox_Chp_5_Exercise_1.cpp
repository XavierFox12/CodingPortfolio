/* Program: Xavier_Fox_Chp_5_Exercise_1.cpp
   Programmer: Xavier Fox
   Date: 13 Oct. 2014
   Purpose: To output the individual numbers
   and the sum of the individual numbers.
*/

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{ 
	int	num, sumOfNum = 0, digit, pwr = 0;

	cout << "Enter an integer: ";
	cin >> num;
	cout << endl;

	cout << "The digits of " << num << " are: ";

	if (num < 0)
		num = -num;

	while (num / static_cast<int>(pow(10.0, pwr)) > 10)
		pwr++;

	while (pwr >= 0)
	{
		digit = num / static_cast<int>(pow(10.0, pwr));
		cout << digit << " ";
		sumOfNum += digit;
		num = num % static_cast<int>(pow(10.0, pwr));
		pwr--;
	}

	cout << endl << "The sum of the digits = " << sumOfNum
		 << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	/*while (num != '#')
	{
		number = static_cast<int>(num) - 48;
		cout << number << " ";
		
		if (num != '#')
		{
			sumOfNum += number;
			cin.get(num);
		}
	}
 
		cout << sumOfNum << endl;*/
	return 0;
}

