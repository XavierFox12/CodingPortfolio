/* Program: Xavier_Fox_Chp_16_Exercise_9.cpp
   Programmer: Xavier Fox
   Date: 10 Apr. 2015
   Purpose: Use binary search to find a string variable
   in an array.
*/

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void selectionSort(string list[], int length);
int binarySearch(const string list[], int listLength, string searchItem);

const int length = 10;

int main()
{
	string list[length];
	string searchItem;
	int searchIndex;

	cout << "Enter 10 strings: ";
	for (int i = 0; i < length; i++)
		cin >> list[i];
	cout << endl;

	selectionSort(list, length);

	cout << "Sorted List: ";
	for (int i = 0; i < length; i++)
		cout << list[i] << " ";
	cout << endl << endl;

	cout << "Enter the string you want to search for: ";
	cin >> searchItem;
	cout << endl;

	searchIndex = binarySearch(list, length, searchItem);

	if (searchIndex >= 0)
	{
		cout << searchItem << " is found at postition (index) " << searchIndex
			 << endl << endl;
	}
	else
		cout << searchItem << " is not found in the list" << endl << endl;

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

// finds the string in the array and returns the index
int binarySearch(const string list[], int listLength, string searchItem)
{
	int first = 0;
	int last = listLength - 1;
	int mid;
	bool found = false;
	
	while (first <= last && !found)
	{
		mid = (first + last) / 2;
		
		if (list[mid] == searchItem)
			found = true;
		else if (list[mid] > searchItem)
			last = mid - 1;
		else
			first = mid + 1;
	}
	
	if (found)
		return mid;
	else
		return -1;
}