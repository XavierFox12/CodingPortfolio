/* Program: Xavier_Fox_Chp_12_Exercise_3.cpp
   Programmer: Xavier Fox
   Date: 10 Feb. 2015
   Purpose: Prints out the election results, and
   determines who the winner is.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void initialize(string *candidates, int *numOfVotes,
				int & totalVotes, int numOfCandidates);
void printResults(const string *candidates, const int *numOfVotes,
				  int totalVotes, int numOfCandidates);

int main()
{
	string *candidates;
	int *numOfVotes;
	int numOfCandidates = 0, totalVotes = 0;

	cout << "Enter number of candidates: ";
	cin >> numOfCandidates;
	cout << endl;

	candidates = new string[numOfCandidates];
	numOfVotes = new int[numOfCandidates];
	
	initialize(candidates, numOfVotes,
			   totalVotes, numOfCandidates);

	printResults(candidates, numOfVotes,
				 totalVotes, numOfCandidates);

	return 0;
}

//gets the candidates and the number of votes they recieved
void initialize(string *candidates, int *numOfVotes, 
			    int & totalVotes, int numOfCandidates)
{
	int i;

	cout << "Enter the candidate's name and the votes received by "
		 << "the candidate: " << endl;
	for (i = 0; i < numOfCandidates; ++i)
	{
		cin >> candidates[i] >> numOfVotes[i];

		totalVotes += numOfVotes[i];
	}
	cout << endl;
}

//Prints the results of the election
void printResults(const string *candidates, const int *numOfVotes,
				  int totalVotes, int numOfCandidates)
{
	string winner;
	int winnerVotes = 0;

	cout << fixed << showpoint << setprecision(2);

	cout << setw(40) << "   Election Results   " << endl
		 << setw(40) << "Program by: Xavier Fox" << endl << endl;

	cout << setw(34) << "Candidate      Votes Received"
		 << "      % of Total Votes" << endl << endl;

	for (int i = 0; i < numOfCandidates; ++i)
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
}