/* Program: Xavier_Fox_Chp_16_Exercise_3.cpp
   Programmer: Xavier Fox
   Date: 7 Apr. 2015
   Purpose: To remove a number from an array using the
   number entered from the user
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

bool remove(int list[], int& length, int removeItem);

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

	cout << "Enter the number to be removed: ";
	cin >> removeItem;
	cout << endl;

	if (remove(list, length, removeItem))
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

// removes the number given
bool remove(int list[], int& length, int removeItem)
{	
	for (int i = 0; i < length; i++)
	{	
		if (list[i] == removeItem)
		{
			for (int l = i; l < length; l++)
				list[l] = list[l + 1];

			length--;
			return true;
		}
	}
	
	return false;
}