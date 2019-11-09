/* Program: Xavier_Fox_Chp_16_Exercise_15.cpp
   Programmer: Xavier Fox
   Date: 20 Apr. 2015
   Purpose: Use binary search to search a vector
   for a string item.
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void selectionSort(vector<string>& list);
int binarySearch(vector<string>& list, string searchItem);

int main()
{
	vector<string> nameList;
	string name, searchItem;
	int index, searchIndex;
	int size;
	char searchAgain = 'y';

	cout << "Enter first names (zzz to end):" << endl << "\t";
	cin >> name;

	while (name != "zzz")
	{
		nameList.push_back(name);
		cin >> name;
	}
	cout << endl;

	selectionSort(nameList);

	cout << "The names after sorting are:" << endl << "\t";

	size = static_cast<int>(nameList.size());

	for (index = 0; index < size; index++)
		cout << nameList[index] << " ";
	cout << endl << endl;

	while (searchAgain == 'y')
	{
		cout << "Enter the string you want to search for: ";
		cin >> searchItem;
		cout << "\t";

		searchIndex = binarySearch(nameList, searchItem);

		if (searchIndex >= 0)
		{
			cout << searchItem << " is found in the list at position (index): "
				 << searchIndex << endl << endl;
		}
		else
			cout << searchItem << " is not found in the list" << endl << endl;

		cout << "Search again (y/n)? ";
		cin >> searchAgain;
		cout << endl;
	}

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

// sorts the string array
void selectionSort(vector<string>& list)
{
	int index, smallestIndex, location;
	string temp;

	int size = static_cast<int>(list.size());

	for(index = 0; index < size - 1; index++)
	{
		smallestIndex = index;
		for (location = index + 1; location < size; location++)
			if (list[location] < list[smallestIndex])
				smallestIndex = location;

		temp = list[smallestIndex];
		list[smallestIndex] = list[index];
		list[index] = temp;
	}
}

// searches the array for the string item
int binarySearch(vector<string>& list, string searchItem)
{
	int size = static_cast<int>(list.size());
	int first = 0;
	int last = size - 1;
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