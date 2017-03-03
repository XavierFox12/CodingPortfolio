/* Program: Xavier_Fox_Chp_8_Exercise_2.cpp
   Programmer: Xavier Fox
   Date: 17 Nov. 2014
   Purpose: Returns the index of the first occurance of
   the smallest number in the array.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

const int ARRAY_SIZE = 15;

void printElements(const int smallNum[]);
int smallestIndex(const int smallNum[]);

int main()
{
	int smallNum[ARRAY_SIZE] = {56, 34, 67, 54, 23, 87, 66, 92, 15, 32, 15,
		54, 88, 92, 30};
	int i = 0;

	cout << "List elements: ";

	printElements(smallNum);

	cout << endl << endl << "The position (index) of the first occurance of the "
		 << "smallest element in the list is: " << smallestIndex(smallNum)
		 << endl << endl;

	cout << "The smallest element in the list is: " 
		 << smallNum[smallestIndex(smallNum)] << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

void printElements(const int smallNum[])
{
	int i;

	for (i = 0; i < ARRAY_SIZE; ++i)
		cout << smallNum[i] << " ";
}

int smallestIndex(const int smallNum[])
{
	int smallestNum = smallNum[0];
	int smallIndex = 0;
	int i;

	for (i = 0; i < ARRAY_SIZE; ++i)
	{
		if (smallNum[i] < smallestNum)
		{
			smallestNum = smallNum[i];
			smallIndex = i;
		}
	}
	return smallIndex;
}

