/* Program: Xavier_Fox_Chp_16_Exercise_1.cpp
   Programmer: Xavier Fox
   Date: 6 Apr. 2015
   Purpose: Using sequential search to find the number entered
   and using the bubble sort to sort the array before searching.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

const int listLength = 10;

void bubbleSort(int list[], int length);
int seqSearch(const int list[], int listLength, int searchItem);

int main()
{
	int list[listLength], numberSearch;
	int i, searchedIndex;

	cout << "Enter 10 integers: ";
	for (i = 0; i < listLength; i++)
		cin >> list[i];
	cout << endl;

	bubbleSort(list, listLength);

	cout << "Sorted list: ";
	for (i = 0; i < listLength; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl << endl;

	cout << "Enter the number to be searched: ";
	cin >> numberSearch;
	cout << endl;

	searchedIndex = seqSearch(list, listLength, numberSearch);

	if (searchedIndex >= 0)
	{
		cout << numberSearch << " is found at postition (index) "
			 << searchedIndex << endl << endl;
	}
	else
	{
		cout << numberSearch << " is not found in the list" << endl << endl;
	}

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

// sorts the array using a bubble sort
void bubbleSort(int list[], int length)
{
	int temp;
	int iteration;
	int index;
	
	for (iteration = 1; iteration < length; iteration++)
	{
		for (index = 0; index < length - iteration; index++)
			if (list[index] > list[index + 1])
			{
				temp = list[index];
				list[index] = list[index + 1];
				list[index + 1] = temp;
			}
	}
}

// searches for the number entered
int seqSearch(const int list[], int listLength, int searchItem)
{
	int loc;
	bool found = false;
	loc = 0;

	while (loc < listLength && !found)
	{
		if (list[loc] == searchItem)
			found = true;
		else
			loc++;
	}

	if (found)
		return loc;
	else
		return -1;
}