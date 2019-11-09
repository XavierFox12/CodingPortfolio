/* Program: Xavier_Fox_Random_Numbers.cpp
   Programmer: Xavier Fox
   Date: 11 Feb. 2015
   Purpose: prints out random numbers depending
   on how many random numbers the user wants.
*/

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int *getRandomNumbers(int amountOfNumbers);

int main()
{
	int amountOfNumbers;
	int *randomNumber;

	cout << "How many random values do you need? ";
	cin >> amountOfNumbers;
	cout << endl;

	randomNumber = getRandomNumbers(amountOfNumbers);

	for(int i = 0; i < amountOfNumbers; i++)
		cout << randomNumber[i] << endl;

	delete [] randomNumber;
	randomNumber = NULL;

	cout << endl << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

int *getRandomNumbers(int amountOfNumbers)
{
	int *array;

	array = new int[amountOfNumbers];

	srand(time(NULL));

	for (int i = 0; i < amountOfNumbers; i++)
		array[i] = rand();

	return array;
}