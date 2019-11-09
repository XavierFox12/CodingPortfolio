/* Program: Xavier_Fox_Chp_16_Exercise_21.cpp
   Programmer: Xavier Fox
   Date: 14 Apr. 2015
   Purpose: To play the lottery by generating 5 random
   numbers and having the user pick 5 random numbers.
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

const int SIZE = 5;

void initialize(int winningLotteryNumbers[], int userLotteryNumbers[], int SIZE);
void generateNumbers(int winningLotteryNumbers[], int SIZE);
bool checkDuplicates(int winningLotteryNumbers[], int num, int i);
void userNumbers(int userLotteryNumbers[], int SIZE);
void bubbleSort(int list[], int SIZE);
bool winnerOrLoser(int winningLotteryNumbers[], int userLotteryNumber[], int SIZE);
void print(int winningLotteryNumbers[], int SIZE);

int main()
{
	int winningLotteryNumbers[SIZE], userLotteryNumbers[SIZE];
	char yesOrNo;

	cout << "Do you want to play the lottery (y/n): ";
	cin >> yesOrNo;
	cout << endl;

	while (yesOrNo == 'y')
	{
		initialize(winningLotteryNumbers, userLotteryNumbers, SIZE);
		generateNumbers(winningLotteryNumbers, SIZE);
		bubbleSort(winningLotteryNumbers, SIZE);

		cout << "Enter 5 distinct integers between 1 and 40 (inclusive):" << endl;
		userNumbers(userLotteryNumbers, SIZE);
		bubbleSort(userLotteryNumbers, SIZE);

		if (winnerOrLoser(winningLotteryNumbers, userLotteryNumbers, SIZE))
			cout << endl << "You win!" << endl << endl;
		else
			cout << endl << "You lose!" << endl;
			
		cout << "The correct numbers are: ";
		print(winningLotteryNumbers, SIZE);

		cout << "Play again (y/n): ";
		cin >> yesOrNo;
		cout << endl;
	}


	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

// initializes the winning lottery number, and user array array to 0
void initialize(int winningLotteryNumbers[], int userLotteryNumbers[], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		userLotteryNumbers[i] = 0;
		winningLotteryNumbers[i] = 0;
	}
}

// generates 5 random numbers
void generateNumbers(int winningLotteryNumbers[], int SIZE)
{
	int i = 0;

	while (i < SIZE)
	{
		srand(time(0));
		int num = rand() % 40 + 1;

		if (!checkDuplicates(winningLotteryNumbers, num, SIZE))
		{
			winningLotteryNumbers[i] = num;
			i++;
		}
	}
}

// Checks for duplicates in the array
bool checkDuplicates(int winningLotteryNumbers[], int num, int i)
{
	bool duplicate = false;

	for (int l = 0; l < i; l++)
	{
		if (num == winningLotteryNumbers[l])
		{
			duplicate = true;
			break;
		}
	}

	return duplicate;
}

// gets the users 5 distinct numbers
void userNumbers(int userLotteryNumbers[], int SIZE)
{
	string str = "Number already selected. Pick another.";
	bool numbers = false;
	int i = 0;

	do
	{
		try
		{
			for (i; i < SIZE; i++)
			{
				cout << "Enter lottery number " << i + 1 << ": ";
				cin >> userLotteryNumbers[i];

				if (userLotteryNumbers[i] < 1 || userLotteryNumbers[i] > 40)
					throw userLotteryNumbers[i];
				for (int l = 0; l < i; l++)
				{
					if (userLotteryNumbers[i] == userLotteryNumbers[l])
						throw str;
				}
			}
			numbers = true;
		}
		catch(string str)
		{
			cout << endl << str << endl;
		}
		catch(int)
		{
			cout << endl << "Number must be between 1 and 40" << endl;
		}
	}
	while (!numbers);
}

// sorts the arrays
void bubbleSort(int list[], int SIZE)
{
	int temp;
	int iteration;
	int index;
	
	for (iteration = 1; iteration < SIZE; iteration++)
	{
		for (index = 0; index < SIZE - iteration; index++)
			if (list[index] > list[index + 1])
			{
				temp = list[index];
				list[index] = list[index + 1];
				list[index + 1] = temp;
			}
	}
}

// determines if the winning lottery numbers match up with the users
bool winnerOrLoser(int winningLotteryNumbers[], int userLotteryNumber[], int SIZE)
{
	bool winner = true;

	for (int i = 0; i < SIZE; i++)
	{
		while (winner)
		{
			if (winningLotteryNumbers[i] != userLotteryNumber[i])
				winner = false;
		}
	}

	return winner;
}

// prints the winning lottery numbers
void print(int winningLotteryNumbers[], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
		cout << winningLotteryNumbers[i] << " ";
}