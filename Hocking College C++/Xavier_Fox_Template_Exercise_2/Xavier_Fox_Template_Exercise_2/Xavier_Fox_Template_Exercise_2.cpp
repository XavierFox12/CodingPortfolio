/* Program: Xavier_Fox_Template_Exercise_2.cpp
   Programmer: Xavier Fox
   Date: 10 Mar. 2015
   Purpose: To sort the arrays using the sort
   template and print the results using the print
   template.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

template <class Type>
void print(Type array[], int size);

template <class Type>
void sort(Type array[], int size);

int main()
{
	int intArray[] = {5, 4, 6, 3, 9};
  	double dblArray[] = {2.3, 4.1, 7.6, 1.5, 3.2, 4.4, 9.4};
  	char charArray[] = {'F', 'K', 'L', 'A', '\0'};

	cout << "Contents of the integer array (unsorted): " << endl;
	print(intArray, 5);
	cout << endl;

	sort(intArray, 5);

	cout << "Contents of the integer array (sorted): " << endl;
	print(intArray, 5);
	cout << endl << endl;

	cout << "Contents of the floating-point array (unsorted): " << endl;
	print(dblArray, 7);
	cout << endl;

	sort(dblArray, 7);

	cout << "Contents of the floating-point array (sorted): " << endl;
	print(dblArray, 7);
	cout << endl << endl;

	cout << "Contents of the character array (unsorted): " << endl;
	print(charArray, 4);
	cout << endl;

	sort(charArray, 4);

	cout << "Contents of the character array (sorted): " << endl;
	print(charArray, 4);
	cout << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

template <class Type>
void print(Type array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
}

template <class Type>
void sort(Type array[], int size)
{
	Type temp;
	int iteration;
	int index;

	for (iteration = 1; iteration < size; iteration++)
	{
		for (index = 0; index < size - iteration; index++)
			if (array[index] > array[index + 1])
			{
				temp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = temp;
			}
	}
}