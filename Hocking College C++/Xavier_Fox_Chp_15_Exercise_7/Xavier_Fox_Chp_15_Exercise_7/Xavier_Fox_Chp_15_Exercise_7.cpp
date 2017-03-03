/* Program: Xavier_Fox_Chp_15_Exercise_7.cpp
   Programmer: Xavier Fox
   Date: 31 Mar. 2015
   Purpose: To determine the smallest and largest
   element in an array.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

void smallestAndLargest(const int list[], int i, int size, int &min, int&max);

int main()
{
	int list[10] = {23, 43, 35, 20, 87, 12, 76, 10, 34, 48};
	int min, max;

	smallestAndLargest(list, 0, 10, min, max);

	cout << "The smallest element is " << min << ", and the largest element is "
		 << max << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

// determines the min and max
void smallestAndLargest(const int list[], int i, int size, int &min, int&max)
{
	if (i == size - 1)
	{
		min = list[i];
		max = list[i];
	}

	else
	{
		smallestAndLargest(list, i + 1, size, min, max);
		if (list[i] > max)
			max = list[i];
		if (list[i] < min)
			min = list[i];
	}
}