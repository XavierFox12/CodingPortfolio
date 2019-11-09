/* Program: Xavier_Fox_Chp_16_Exercise_12.cpp
   Programmer: Xavier Fox
   Date: 17 Apr. 2015
   Purpose: To use a selection sort algorithm to
   sort a string vecotor object.
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void selectionSort(vector<string>& list);

int main()
{
	vector<string> nameList;
	string name;
	int index;
	int size;

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

	cout << endl << endl << "Program by: Xavier Fox" << endl << endl;

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