/* Program: Xavier_Fox_Chp_16_Exercise_5.cpp
   Programmer: Xavier Fox
   Date: 7 Apr. 2015
   Purpose: removes all of the occurrences of the number
   given by the user
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

bool removeAll(int list[], int& length, int removeItem);

int main()
{
	int list[20] = {4, 7, 4, 4, 4, 3, 4, 4, 4, 8, 4, 4};
	int length = 12, removeItem;

	cout << "Before: ";
	for (int i = 0; i < length; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl << endl;

	cout << "Enter the number to be removed: ";
	cin >> removeItem;
	cout << endl;

	if (removeAll(list, length, removeItem))
	{
		cout << "After: ";
		for (int i = 0; i < length; i++)
		{
			cout << list[i] << " ";
		}
		cout << endl << endl;
	}
	else
		cout << removeItem << " is not in the list" << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

// removes all occurrences of the number given
bool removeAll(int list[], int& length, int removeItem)
{
	bool found = false;

	for (int i = 0; i < length; i++)
	{
		if (list[i] == removeItem)
		{
			for (int l = i; l < length; l++)
				list[l] = list[l + 1];

			length--;
			i--;
			found = true;
		}
	}

	if (found)
		return true;
	else
		return false;
}