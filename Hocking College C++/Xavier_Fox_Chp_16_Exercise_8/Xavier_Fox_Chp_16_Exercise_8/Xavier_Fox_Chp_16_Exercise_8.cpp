/* Program: Xavier_Fox_Chp_16_Exercise_8.cpp
   Programmer: Xavier Fox
   Date: 8 Apr. 2015
   Purpose: Sorts the string array using a selection 
   sort.
*/

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

const int length = 10;

void selectionSort(string list[], int length);

int main()
{
	string list[length];

	cout << "Enter 10 strings: ";
	for (int i = 0; i < length; i++)
		cin >> list[i];
	cout << endl;

	selectionSort(list, length);

	cout << "Strings sorted: ";
	for (int i = 0; i < length; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

// sorts the string array
void selectionSort(string list[], int length)
{
	int first, minIndex;
	string minValue;

	for(first = 0; first < (length - 1); first++)
	{
		minIndex = first;
		minValue = list[first];
		for(int index = first + 1; index < length; index++)
		{
			if (list[index] < minValue)
			{
				minValue = list[index];
				minIndex = index;
			}
		}
		list[minIndex] = list[first];
		list[first] = minValue;
	}
}
