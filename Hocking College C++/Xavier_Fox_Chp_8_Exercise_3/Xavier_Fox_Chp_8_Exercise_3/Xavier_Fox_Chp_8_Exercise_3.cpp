/* Program: Xavier_Fox_Chp_8_Exercise_3.cpp
   Programmer: Xavier Fox
   Date: 17 Nov. 2014
   Purpose:Returns the index of the last occurrence of
   the largest element in the array.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

void printElements(const int largeNum[]);
int lastLargestIndex(const int largeNum[]);

const int ARRAY_SIZE = 15;

int main()
{
	int largeNum[ARRAY_SIZE] = {56, 34, 67, 54, 23, 87, 66, 92, 15, 32, 15,
		54, 88, 92, 30};

	cout << "List elements: ";

	printElements(largeNum);

	cout << endl << endl << "The position (index) of the last occurance of the "
		 << "largest element in the list is: " << lastLargestIndex(largeNum)
		 << endl << endl;

	cout << "The largest element in the list is: "
		 << largeNum[lastLargestIndex(largeNum)] << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

void printElements(const int largeNum[])
{
	int i;

	for (i = 0; i < ARRAY_SIZE; ++i)
		cout << largeNum[i] << " ";
}

int lastLargestIndex(const int largeNum[])
{
	int largestNum = largeNum[0];
	int largeIndex = 0;
	int i;

	for (i = 0; i < ARRAY_SIZE; ++i)
	{
		if (largeNum[i] >= largestNum)
		{
			largestNum = largeNum[i];
			largeIndex = i;
		}
	}
	return largeIndex;
}