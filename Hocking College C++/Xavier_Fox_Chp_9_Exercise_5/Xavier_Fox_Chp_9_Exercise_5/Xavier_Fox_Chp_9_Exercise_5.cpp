/* Program: Xavier_Fox_Chp_9_Exercise_5.cpp
   Programmer: Xavier Fox
   Date: 8 Dec. 2014
   Purpose: To determine the customers total bill
   by asking them what they want from the menu and
   how many orders they want.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int ARRAY_SIZE = 8;
const double TAX = .05;

struct menuItemType
{
	string menuItem;
	double menuPrice;
	int itemSelection;
	int numOfOrders;
};

void getData(ifstream& inFile, menuItemType menuList[]);
void showMenu(menuItemType menuList[]);
void printCheck(const menuItemType menuList[]);

int main()
{
	menuItemType menuList[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; ++i)
		menuList[i].itemSelection = 0;

	ifstream inFile;

	inFile.open("E:\\C++\\Ch9_Ex4Data.txt");
	if (!inFile)
	{
		cout << "Cannot find Ch9_Ex4Data.txt" << endl
			 << "  The Program terminates   " << endl << endl;
		return 1;
	}

	cout << showpoint << fixed << setprecision(2);

	getData(inFile, menuList);

	inFile.close();

	showMenu(menuList);
	printCheck(menuList);

	return 0;
}

//Loads the data into the array
void getData(ifstream& inFile, menuItemType menuList[])
{
	while (inFile)
	{
		for (int i = 0; i < ARRAY_SIZE; ++i)
		{
			getline(inFile, menuList[i].menuItem);
			inFile >> menuList[i].menuPrice;
			inFile.get();
		}
	}
}

//Shows the different items offered by the restaurant
void showMenu(menuItemType menuList[])
{
	char yesOrNo;
	int itemNum;

	cout << setw(50) << "Welcome to Xavier's Restaurant" << endl
		 << setw(50) << "    ----Today's Menu----      " << endl;

	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		cout << setw(24) << i + 1 << ":  " << left << setw(13) << menuList[i].menuItem
			 << right << setw(3) << "$" << menuList[i].menuPrice << endl;
	}

	cout << "You can make up to 8 single order selections" << endl << endl;

	cout << "Do you want to make a selection (y/n): ";
	cin >> yesOrNo;
	cout << endl;

	while (yesOrNo == 'y')
	{
		cout << "Enter item number: ";
		cin >> itemNum;
		menuList[itemNum - 1].itemSelection = 1;

		cout << "How many orders: ";
		cin >> menuList[itemNum - 1].numOfOrders;
		cout << endl;

		menuList[itemNum - 1].menuPrice = menuList[itemNum - 1].menuPrice *
										  menuList[itemNum - 1].numOfOrders;

		cout << "Do you want to make a selection (y/n): ";
		cin >> yesOrNo;
		cout << endl;
	}
}

//Calculates and prints the check
void printCheck(const menuItemType menuList[])
{
	double totalBill = 0, tax;

	cout << setw(50) << "Welcome to Xavier's Restaurant" << endl
		 << setw(50) << "   ----Customer's Bill----    " << endl;

	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		if (menuList[i].itemSelection == 1)
		{
			cout << setw(22) << menuList[i].numOfOrders << " " << left << "" 
				 << setw(15) << menuList[i].menuItem << right << setw(6) << "$"
				 << setw(5) << menuList[i].menuPrice << endl;
			totalBill += menuList[i].menuPrice;
		}
	}
	cout << endl;

	tax = totalBill * TAX;

	cout << setw(23) << left << "" << setw(12) << "Tax" << right 
		 << setw(9) << "$" << setw(5) << tax << endl;
	cout << setw(23) << left << "" << setw(12) << "Amount Due" << right
		 << setw(9) << "$" << setw(5) <<  tax + totalBill
		 << endl << endl;
}