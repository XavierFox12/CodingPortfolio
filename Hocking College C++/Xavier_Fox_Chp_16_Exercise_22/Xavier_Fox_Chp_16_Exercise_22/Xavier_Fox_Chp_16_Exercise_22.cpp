/* Program: Xavier_Fox_Chp_16_Exercise_22.cpp
   Programmer: Xavier Fox
   Date: 20 Apr. 2015
   Purpose: To print out the election results and
   determine the winner.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

const int NO_OF_REGIONS = 4;
const int NO_OF_CANDIDATES = 6;

void printHeading();
void initialize(int vbRegion[][NO_OF_REGIONS], vector<int>& tVotes, int noOfRows);
void getCandidatesName(ifstream& inp, vector<string>& cNames, int noOfRows);
void sortCandidatesName(vector<string>& cNames, int noOfRows);
int binSearch(vector<string>& cNames, int noOfRows, string name);
void processVotes(ifstream& inp, vector<string>& cNames,
				  int vbRegion[][NO_OF_REGIONS], int noOfRows);
void addRegionsVote(int vbRegion[][NO_OF_REGIONS], vector<int>& tVotes, int noOfRows);
void printResults(vector<string>& cNames, int vbRegion[][NO_OF_REGIONS], 
				  vector<int>& tVotes, int noOfRows);

int main()
{
	vector<string> candidatesName;
	int votesByRegion[NO_OF_CANDIDATES][NO_OF_REGIONS];
	vector<int> totalVotes;
	ifstream inFile;

	inFile.open("E:\\SP2015\\C++\\candData.txt");
	if (!inFile)
	{
		cout << "Cannot find candData.txt" << endl
			 << " The Program terminates " << endl << endl;
		return 1;
	}

	getCandidatesName(inFile, candidatesName, NO_OF_CANDIDATES);

	int candSize = static_cast<int>(candidatesName.size());

	sortCandidatesName(candidatesName, candSize);

	inFile.close();
	inFile.clear();

	inFile.open("E:\\SP2015\\C++\\voteData.txt");
	if (!inFile)
	{
		cout << "Cannot find voteData.txt" << endl
			 << " The Program terminates " << endl << endl;
		return 1;
	}

	initialize(votesByRegion, totalVotes, candSize);
	processVotes(inFile, candidatesName, votesByRegion, candSize);
	addRegionsVote(votesByRegion, totalVotes, candSize);
	printHeading();
	printResults(candidatesName, votesByRegion, totalVotes, candSize);

	return 0;
}

// Prints the heading of the election results
void printHeading()
{
	cout << "      -------------Election Results----------"
		 << "----" << endl << endl;
	cout << "Candidate                  Votes" << endl;
	cout << "Name        Region1   Region2   Region3   "
		 << "Region4    Total" << endl;
	cout << "---------   -------   -------   -------   "
		 << "-------   ------" << endl;
}

// initializes the array
void initialize(int vbRegion[][NO_OF_REGIONS], vector<int>& tVotes, int noOfRows)
{
	int r, c;

	for (r = 0; r < noOfRows; r++)
		for (c = 0; c < NO_OF_REGIONS; c++)
			vbRegion[r][c] = 0;

	tVotes.clear();
}

// gets the candidates name from the file
void getCandidatesName(ifstream& inp, vector<string>& cNames, int noOfRows)
{
	string name;
	int i;

	for (i = 0; i < noOfRows; i++)
	{
		inp >> name;
		cNames.push_back(name);
	}
}

// sorts the candidates name
void sortCandidatesName(vector<string>& cNames, int noOfRows)
{
	int firstOutOfOrder, location;
	string temp;

	for (firstOutOfOrder = 1; firstOutOfOrder < noOfRows; firstOutOfOrder++)
		if (cNames[firstOutOfOrder] < cNames[firstOutOfOrder - 1])
		{
			temp = cNames[firstOutOfOrder];
			location = firstOutOfOrder;

			do
			{
				cNames[location] = cNames[location - 1];
				location--;
			}
			while (location > 0 && cNames[location - 1] > temp);

			cNames[location] = temp;
		}
}

// uses binary search to search through the array
int binSearch(vector<string>& cNames, int noOfRows, string name)
{
	int first, last, mid;
	bool found;
	first = 0;
	last = noOfRows - 1;
	found = false;

	while (!found && first <= last)
	{
		mid = (first + last) / 2;

		if (cNames[mid] == name)
			found = true;
		else if (cNames[mid] > name)
			last = mid - 1;
		else
			first = mid + 1;
	}
	if (found)
		return mid;
	else
		return -1;
}

// processes the votes from the file
void processVotes(ifstream& inp, vector<string>& cNames,
				  int vbRegion[][NO_OF_REGIONS], int noOfRows)
{
	string candName;
	int region;
	int noOfVotes;
	int loc;

	inp >> candName >> region >> noOfVotes;

	while (inp)
	{
		loc = binSearch(cNames, noOfRows, candName);

		if (loc != -1)
			vbRegion[loc][region - 1] = vbRegion[loc][region - 1] + noOfVotes;

		inp >> candName >> region >> noOfVotes;
	}
}

// adds in the 4 regions votes
void addRegionsVote(int vbRegion[][NO_OF_REGIONS], vector<int>& tVotes, int noOfRows)
{
	int r, c;
	int totalVotes;

	for (r = 0; r < noOfRows; r++)
	{
		totalVotes = 0;
		for (c = 0; c < NO_OF_REGIONS; c++)
			totalVotes = totalVotes + vbRegion[r][c];
		tVotes.push_back(totalVotes);
	}
}

// Prints the results of the election
void printResults(vector<string>& cNames, int vbRegion[][NO_OF_REGIONS], 
				  vector<int>& tVotes, int noOfRows)
{
	int r, c;
	int largestVotes = 0;
	int winLoc = 0;
	int sumVotes = 0;

	for (r = 0; r < noOfRows; r++)
	{
		if (largestVotes < tVotes[r])
		{
			largestVotes = tVotes[r];
			winLoc = r;
		}

		sumVotes = sumVotes + tVotes[r];

		cout << left;
		cout << setw(9) << cNames[r] << "  ";
		cout << right;
		
		for (c = 0; c < NO_OF_REGIONS; c++)
			cout << setw(8) << vbRegion[r][c] << "  ";

		cout << setw(6) << tVotes[r] << endl;
	}

	cout << endl << endl << "Winner: " << cNames[winLoc] << ", Votes Recieved: "
		 << tVotes[winLoc] << endl << endl;
	cout << "Total Votes polled: " << sumVotes << endl << endl;
	
	cout << "Program by: Xavier Fox" << endl << endl;
}