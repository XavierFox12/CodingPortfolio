/* Program: Xavier_Fox_Chp_16_Exercise_4.cpp
   Programmer: Xavier Fox
   Date: 7 Apr. 2015
   Purpose: To remove the number from the array using
   the index given by the user
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

bool removeAt(int list[], int& length, int removeItem);

int main()
{
	int list[20] = {4, 23, 65, 34, 82, 37, 12, 17, 24, 36, 82, 51};
	int length = 12, removeItem;

	cout << "Before: ";
	for (int i = 0; i < length; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl << endl;

	cout << "Enter the position of the item to be removed: ";
	cin >> removeItem;
	cout << endl;

	if (removeAt(list, length, removeItem))
	{
		cout << "After: ";
		for (int i = 0; i < length; i++)
		{
			cout << list[i] << " ";
		}
		cout << endl << endl;
	}
	else
	{
		cout << "The position entered is out of range." << endl;
		if (removeItem >= length)
			cout << "The list ends at position 11" << endl << endl;
		else
			cout << "The number must be nonnegative." << endl << endl;
	}

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

// removes the number from the index given
bool removeAt(int list[], int& length, int removeItem)
{
	if (removeItem >= length || removeItem < -1)
		return false;
	else
	{
		for (int i = removeItem; i < length; i++)
				list[i] = list[i + 1];

		length--;
		return true;
	}
}