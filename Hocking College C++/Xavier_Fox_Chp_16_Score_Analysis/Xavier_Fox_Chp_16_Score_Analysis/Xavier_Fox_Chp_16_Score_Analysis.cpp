/* Program: Xavier_Fox_Chp_16_Score_Analysis.cpp
   Programmer: Xavier Fox
   Date: 21 Apr. 2015
   Purpose: Determines the lowest test score and
   removes it from the vector, sorts the vector,
   and determines the average.
*/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

void loadTests(vector<int>& testList);
void sortTests(vector<int>& list);
void dropLowest(vector<int>& testList);
void printResults(vector<int>& testList);

int main()
{
	vector<int> testList;

	loadTests(testList);
	sortTests(testList);
	dropLowest(testList);
	printResults(testList);

	return 0;
}

// loads the tests into the vector
void loadTests(vector<int>& testList)
{
	int testScore;

	cout << "Enter test scores (-1 to end)" << endl << "\t";
	cin >> testScore;

	while (testScore != -1)
	{
		testList.push_back(testScore);
		cin >> testScore;
	}
	cout << endl;
}

// sorts the test scores
void sortTests(vector<int>& list)
{
	int index, smallestIndex, location;
	int temp;

	int size = list.size();

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

// drops the lowest test score
void dropLowest(vector<int>& testList)
{
	int i;

	int size = testList.size();

	for (i = 0; i < size - 1; i++)
		testList[i] = testList[i + 1];

	testList.pop_back();
}

// prints the test results
void printResults(vector<int>& testList)
{
	int size = testList.size();
	int i;
	double average = 0;

	cout << "Test statistics with the lowest score dropped!" << endl << endl;
	cout << "   Sorted Scores : ";
	
	for (i = 0; i < size; i++)
		cout << testList[i] << " ";

	cout << endl;
	cout << "   Lowest Score  : " << testList.front() << endl;
	cout << "   Highest Score : " << testList.back() << endl;
	cout << "   Average Score : ";

	for (i = 0; i < size; i++)
		average += testList[i];

	cout << average / size << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;
}