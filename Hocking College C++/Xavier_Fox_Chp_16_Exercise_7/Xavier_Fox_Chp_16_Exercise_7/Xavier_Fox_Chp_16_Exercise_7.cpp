/* Program: Xavier_Fox_Chp_16_Exercise_7.cpp
   Programmer: Xavier Fox
   Date: 8 Apr. 2015
   Purpose: Inserts a number into the array at the
   index the user specifies 
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

bool insertAt(int list[], int& length, int insertItem, int index);

const int size = 20;

int main()
{
	int list[size] = {4, 33, 25, 68, 50, 30, 63, 47, 54, 86, 82, 71};
	int length = 12, insertItem, index;

	cout << "Before: ";
	for (int i = 0; i < length; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl << endl;

	cout << "Enter the number to be inserted: ";
	cin >> insertItem;

	cout << "Enter the index you want to insert " << insertItem
		 << " into (starts at 0): ";
	cin >> index;
	cout << endl;

	if (insertAt(list, length, insertItem, index))
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
		if (length == size)
			cout << "The array is full" << endl << endl;
		else
			cout << "The position entered is out of range." << endl;
			if (index >= length)
				cout << "The size of the list is " << size << endl << endl;
			else
				cout << "The number must be nonnegative." << endl << endl;
	}

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

// inserts the number at the index the user specified
bool insertAt(int list[], int& length, int insertItem, int index)
{
	bool found = false;

	if (length == size)
		return found;

	length++;

	if (index > length && index < size)
	{
		cout << "Item will be inserted at the end of the list at position "
			 << length - 1 << endl;
		while (index >= length)
			index--;
	}

	for (int i = 0; i < length; i++)
	{
		if (i == index)
		{
			for (int l = length; l > i; l--)
			{
				list[l] = list[l - 1];
				
			}
			list[i] = insertItem;
			found = true;
		}
	}

	return found;
}