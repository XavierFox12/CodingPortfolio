/* Program: Xavier_Fox_Template_Exercise_3.cpp
   Programmer: Xavier Fox
   Date: 11 Mar. 2015
   Purpose: Sorts the arrays and determines the mean,
   median, mode, and range.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

template <class Type>
void print(Type array[], int size);

template <class Type>
void sort(Type array[], int size);

template <class Type>
Type mean(Type array[], int size);

template <class Type>
Type median(Type array[], int size);

template <class Type>
Type mode(Type array[], int size);

template <class Type>
Type range(Type array[], int size);

int main()
{
	int intArray[] = {21, 21, 14, 44, 17, 21, 14, 16};
    double dblArray[] = {2.3, 4.1, 3.7, 2.3, 3.2, 2.3, 2.5};

	cout << "==================================================================="
		 << endl << endl;

	cout << "Contents of the integer array (unsorted): ";
	print(intArray, 8);
	cout << endl;

	sort(intArray, 8);

	cout << "Contents of the integer array (sorted):   ";
	print(intArray, 8);
	cout << endl << endl;

	cout << "Mean: " << mean(intArray, 8) << " Median: " << median(intArray, 8)
		 << " Mode: " << mode(intArray, 8)<< " Range: " << range(intArray, 8)
		 << endl << endl;

	cout << "==================================================================="
		 << endl << endl;

	cout << showpoint << fixed << setprecision(1);

	cout << "Contents of the floating-point array (unsorted): ";
	print(dblArray, 7);
	cout << endl;

	sort(dblArray, 7);

	cout << "Contents of the floating-point array (sorted):   ";
	print(dblArray, 7);
	cout << endl << endl;

	cout << "Mean: " << mean(dblArray, 7) << " Median: " << median(dblArray, 7)
		 << " Mode: " << mode(dblArray, 7)<< " Range: " << range(dblArray, 7)
		 << endl << endl;

	cout << "==================================================================="
		 << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

// prints the array
template <class Type>
void print(Type array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
}

// sorts the array
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

// Determines the average
template <class Type>
Type mean(Type array[], int size)
{
	Type average = 0;

	for (int i = 0; i < size; i++)
	{
		average += array[i];
	}

	return average / size;
}

// Finds the middle value
template <class Type>
Type median(Type array[], int size)
{
	if ((size % 2) == 0)
		return ((array[size / 2] + array[size / 2 -1]) / 2);
	else
		return array[size / 2];
}

// determines the mode
template <class Type>
Type mode(Type array[], int size)
{
	int* repetition = new int[size];
    for (int i = 0; i < size; ++i)
	{
        repetition[i] = 0;
        int j = 0;
        bool found = false;
        while ((j < i) && (array[i] != array[j])) {
            if (array[i] != array[j]) {
                ++j;
            }
        }
        ++(repetition[j]);
    }
    int maxRepeat = 0;
    for (int i = 1; i < size; ++i) {
        if (repetition[i] > repetition[maxRepeat]) {
            maxRepeat = i;
        }
    }
    delete [] repetition;
    return array[maxRepeat];
}

// determines the range
template <class Type>
Type range(Type array[], int size)
{
	return array[size - 1] - array[0];
}