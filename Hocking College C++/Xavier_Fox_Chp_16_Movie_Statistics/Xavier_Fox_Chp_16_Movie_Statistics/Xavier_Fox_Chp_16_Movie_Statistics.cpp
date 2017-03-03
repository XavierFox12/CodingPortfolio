/* Program: Xavier_Fox_Chp_16_Movie_Statistics.cpp
   Programmer: Xavier Fox
   Date: 22 Apr. 2015
   Purpose: To determine the mean, median, mode, and range
   from the number of movies watched by college students.
*/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

void loadMoviesWatched(vector<double>& moviesWatched);
void sortVector(vector<double>& moviesWatched, int size);
void mean(vector<double>& moviesWatched, int size);
void median(vector<double>& moviesWatched, int size);
void mode(vector<double>& moviesWatched, int size);
void range(vector<double>& moviesWatched, int size);

int main()
{
	vector<double> moviesWatched;
	int size;

	loadMoviesWatched(moviesWatched);
	size = moviesWatched.size();

	cout << "Number surveyed: " << size << endl << endl;

	sortVector(moviesWatched, size);
	mean(moviesWatched, size);
	median(moviesWatched, size);
	mode(moviesWatched, size);
	range(moviesWatched, size);

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

// loads the movies watched into a vector
void loadMoviesWatched(vector<double>& moviesWatched)
{
	int movies;

	cout << "Enter the number of movies watched by each student (-1 to end):"
		 << endl << "\t";
	cin >> movies;

	while (movies != -1)
	{
		moviesWatched.push_back(movies);
		cin >> movies;
	}
	cout << endl;
}

// Sorts the vector
void sortVector(vector<double>& moviesWatched, int size)
{
	int index, smallestIndex, location;
	double temp;

	for(index = 0; index < size - 1; index++)
	{
		smallestIndex = index;
		for (location = index + 1; location < size; location++)
			if (moviesWatched[location] < moviesWatched[smallestIndex])
				smallestIndex = location;

		temp = moviesWatched[smallestIndex];
		moviesWatched[smallestIndex] = moviesWatched[index];
		moviesWatched[index] = temp;
	}
}

// Determines the mean and prints it out
void mean(vector<double>& moviesWatched, int size)
{
	double average = 0;

	for (int i = 0; i < size; i++)
	{
		average += moviesWatched[i];
	}

	cout << "Mean: " << average / size << ", ";
}

// determines the median and prints it out
void median(vector<double>& moviesWatched, int size)
{
	if ((size % 2) == 0)
	{
		cout << "Median: " << ((moviesWatched[size / 2] + moviesWatched[size / 2 -1]) / 2)
			 << ", ";
	}
	else
		cout << "Median: " << moviesWatched[size / 2] << ", ";
}

// Determines the mode and prints it out
void mode(vector<double>& moviesWatched, int size)
{
	int* repetition = new int[size];
    for (int i = 0; i < size; ++i)
	{
        repetition[i] = 0;
        int j = 0;
        bool found = false;
		while ((j < i) && (moviesWatched[i] != moviesWatched[j])) {
			if (moviesWatched[i] != moviesWatched[j]) {
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
    cout << "Mode: " << moviesWatched[maxRepeat] << ", ";
}

// determines the range and prints it out
void range(vector<double>& moviesWatched, int size)
{
	cout << "Range: " << moviesWatched.back() - moviesWatched.front() << endl << endl;
}