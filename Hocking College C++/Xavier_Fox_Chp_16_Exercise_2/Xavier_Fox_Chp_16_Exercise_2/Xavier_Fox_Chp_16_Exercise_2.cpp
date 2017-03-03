/* Program: Xavier_Fox_Chp_16_Exercise_2.cpp
   Programmer: Xavier Fox
   Date: 6 Apr. 2015
   Purpose: Using the binarySearch function to search
   for a number after using the insertionSort function.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

const int listLength = 10;

void insertionSort(int list[], int listLength);
int binarySearch(const int list[], int listLength, int searchItem);

int main()
{
	int list[listLength], numberSearch, searchIndex, i;

	cout << "Enter 10 integers: ";
	for (i = 0; i < listLength; i++)
		cin >> list[i];
	cout << endl;

	insertionSort(list, listLength);

	cout << "Sorted list: ";
	for (int i = 0; i < listLength; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl << endl;

	cout << "Enter the number to be searched: ";
	cin >> numberSearch;
	cout << endl;

	searchIndex = binarySearch(list, listLength, numberSearch);

	if (searchIndex >= 0)
	{
		cout << numberSearch << " is found at postition (index) "
			 << searchIndex << endl << endl;
	}
	else
	{
		cout << numberSearch << " is not found in the list" << endl << endl;
	}

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

// Sorts the array using the insertion sort
void insertionSort(int list[], int listLength)
{
	int firstOutOfOrder, location;
	int temp;
	
	for (firstOutOfOrder = 1; firstOutOfOrder < listLength; firstOutOfOrder++)
		if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])
		{
			temp = list[firstOutOfOrder];
			location = firstOutOfOrder;
			
			do
			{
				list[location] = list[location - 1];
				location--;
			}
			while (location > 0 && list[location - 1] > temp);
			
			list[location] = temp;
		}
}

// searches for the number entered
int binarySearch(const int list[], int listLength, int searchItem)
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