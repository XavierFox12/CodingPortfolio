/* Program: Xavier_Fox_Chp_8_Exercise_7.cpp
   Programmer: Xavier Fox
   Date: 18 Nov. 2014
   Purpose: To determine who who the election given the 
   number of votes they got.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void initialize(string candidates[], int numOfVotes[],
				double percentOfVotes[], int & totalVotes, int size);
void printResults(const string candidates[], const int numOfVotes[],
				 const double percentOfVotes[], int totalVotes, int size);

const int SIZE = 5;

int main()
{
	string candidates[SIZE];
	int numOfVotes[SIZE] = {0}, totalVotes = 0;
	double percentOfVotes[SIZE] = {0};
	
	initialize(candidates, numOfVotes, percentOfVotes,
			   totalVotes, SIZE);

	printResults(candidates, numOfVotes, percentOfVotes,
			   totalVotes, SIZE);
	return 0;
}

//gets the candidates and the number of votes they recieved
void initialize(string candidates[], int numOfVotes[], 
				double percentOfVotes[], int & totalVotes, int size)
{
	int i;

	cout << "Enter the candidate's name and the votes received by "
		 << "the candidate: " << endl;
	for (i = 0; i < size; ++i)
	{
		cin >> candidates[i] >> numOfVotes[i];

		totalVotes += numOfVotes[i];
	}
	cout << endl;
}

//Prints the results of the election
void printResults(const string candidates[], const int numOfVotes[],
				const double percentOfVotes[], int totalVotes, int size)
{
	string winner;
	int winnerVotes = 0;

	cout << fixed << showpoint << setprecision(2);

	cout << setw(34) << "Candidate      Votes Received"
		 << "      % of Total Votes" << endl << endl;

	for (int i = 0; i < size; ++i)
	{
		cout << setw(5) << "" << left << setw(12) << candidates[i];
		cout << right << setw(12) << numOfVotes[i] << setw(22) 
			 << 100 * (numOfVotes[i] / static_cast<double>(totalVotes))
			 << endl;

		if (numOfVotes[i] > winnerVotes)
		{
			winner = candidates[i];
			winnerVotes = numOfVotes[i];
		}
	}

	cout << setw(10) << "Total" << setw(19) << totalVotes
		 << endl << endl << setw(35) << "The winner of the Election is "
		 << winner << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;
}