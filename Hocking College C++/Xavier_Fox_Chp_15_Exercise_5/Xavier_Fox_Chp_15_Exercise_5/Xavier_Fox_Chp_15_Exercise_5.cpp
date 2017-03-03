/* Program: Xavier_Fox_Chp_15_Exercise_5.cpp
   Programmer: Xavier Fox
   Date: 30 Mar. 2015
   Purpose: To return the sum of the elements in the arrays.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int elementSum(int list[], int first, int last);

int main()
{
	int listA[10] = {1, 9, 3, 6, 5, 4, 7, 8, 2, 10};
	int listB[1] = {5};

	cout << "Sum of listA = " << elementSum(listA, 0, 9) << endl << endl;
	cout << "Sum of listB = " << elementSum(listB, 0, 0) << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

// Returns the sum of all the elements in an array
int elementSum(int list[], int first, int last)
{
	if (first == last)
		return list[first];
	else
		return list[first] + elementSum(list, first + 1, last);
}