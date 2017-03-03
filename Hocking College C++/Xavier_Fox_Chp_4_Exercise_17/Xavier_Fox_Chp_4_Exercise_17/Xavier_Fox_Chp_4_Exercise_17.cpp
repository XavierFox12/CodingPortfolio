/* Program: Xavier_Fox_Chp_4_Exercise_17.cpp
   Programmer: Xavier Fox
   Date: 7 Oct. 2014
   Purpose: To determine which model is the least in price
   per square foot.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	double colonialPrice, splitEntryPrice, singleStoryPrice,
		colonialSquareFeet, splitEntrySquareFeet, singleStorySquareFeet,
		colonialTotal, splitEntryTotal, singleStoryTotal;

	cout << "Enter the price of the colonial model: ";
	cin >> colonialPrice;
	cout << "Ente the finished area in square feet of the colonial model: ";
	cin >> colonialSquareFeet;
	cout << endl;

	cout << "Enter the price of the split entry model: ";
	cin >> splitEntryPrice;
	cout << "Enter the finished area in square feet of the split entry "
		 << "model: ";
	cin >> splitEntrySquareFeet;
	cout << endl;

	cout << "Enter the price of the single story model: ";
	cin >> singleStoryPrice;
	cout << "Enter the finished area in square feet of the single story "
		 << "model: ";
	cin >> singleStorySquareFeet;
	cout << endl;

	colonialTotal = colonialPrice / colonialSquareFeet;

	splitEntryTotal = splitEntryPrice / splitEntrySquareFeet;

	singleStoryTotal = singleStoryPrice / singleStorySquareFeet;
	
	if (colonialTotal <= splitEntryTotal && colonialTotal <= singleStoryTotal)
	{
		if (colonialTotal == splitEntryTotal)
		{
			cout << "   The price per square foot of the colonial and split model "
				 << "are the same and less than the single story model"
				 << endl << endl;
		}
		else if (colonialTotal == singleStoryTotal)
		{
			cout << "   The price per square foot of the colonial and single story "
				 << "model are the same and less than the split entry model"
				 << endl << endl;
		}
		else
		{
			cout << "   The price of the colonial model per square foot is the least"
				 << endl << endl;
		}
	}

	else if (splitEntryTotal <= colonialTotal && splitEntryTotal <= singleStoryTotal)
	{
		if (colonialTotal == splitEntryTotal)
		{
			cout << "   The price per square foot of the colonial and split model "
				 << "are the same and less than the single story model"
				 << endl << endl;
		}
		else if (splitEntryTotal == singleStoryTotal)
		{
			cout << "   The price per square foot of the split entry and single story "
				 << "model are the same and less than the colonial model"
				 << endl << endl;
		}
		else
		{
			cout << "   The price of the split entry model per square foot is the least"
				 << endl << endl;
		}
	}

	else
	{
		if (singleStoryTotal == splitEntryTotal)
		{
			cout << "   The price per square foot of the single story and split model "
				 << "are the same and less than the colonial model"
				 << endl << endl;
		}
		else if (colonialTotal == singleStoryTotal)
		{
			cout << "   The price per square foot of the colonial and single story "
				 << "model are the same and less than the split entry model"
				 << endl << endl;
		}
		else
		{
			cout << "   The price of the single story model per square foot is the least"
				<< endl << endl;
		}
	}

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

