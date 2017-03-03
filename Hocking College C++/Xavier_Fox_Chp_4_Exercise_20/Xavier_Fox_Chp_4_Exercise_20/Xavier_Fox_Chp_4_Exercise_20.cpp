/* Program: Xavier_Fox_Chp_4_Exercise_20.cpp
   Programmer: Xavier Fox
   Date: 9 Oct. 2014
   Purpose: To determine the rooms cost after determing what
   discounts are given and how many rooms are booked.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

const double TENROOMS = .1, TWENTYROOMS = .2, THIRTYROOMS = .3,
	         THREEDAYDISCOUNT = .05;
int main()
{
	double roomCost, salesTax, totalRoomCost, billingAmount,
		   discount;
	int roomsBooked, numOfDays;
	char yesOrNo = 'y';

	while (yesOrNo == 'y')
	{
		cout << "Enter the cost to rent one room: ";
		cin >> roomCost;
		cout << endl;

		cout << "Enter the number of rooms booked: ";
		cin >> roomsBooked;
		cout << endl;

		cout << "Enter the number of days the rooms are booked: ";
		cin >> numOfDays;
		cout << endl;

		cout << "Enter the sales tax as a percentage: ";
		cin >> salesTax;
		cout << endl;

		cout << fixed << showpoint << setprecision(2);

		if (roomsBooked >= 30)
		{
			discount = THIRTYROOMS;

			if (numOfDays >= 3)
				discount += THREEDAYDISCOUNT;

			totalRoomCost = roomCost * roomsBooked * numOfDays;
			totalRoomCost = totalRoomCost - (totalRoomCost * discount);
			salesTax = totalRoomCost * (salesTax / 100);
			billingAmount = totalRoomCost + salesTax;

			cout << "Cost of one room: $" << roomCost << endl
				 << "Discount on each room: " << discount * 100 << "%" << endl
				 << "Rooms booked: " << roomsBooked << endl
				 << "Number of days each room is booked: " << numOfDays 
				 << endl << "Total cost: $" << totalRoomCost << endl
				 << "Sales tax: $" << salesTax << endl
				 << "Total billing amount: $" << billingAmount << endl << endl;
		}

		else if (roomsBooked >= 20)
		{
			discount = TWENTYROOMS;

			if (numOfDays >= 3)
				discount += THREEDAYDISCOUNT;

			totalRoomCost = roomCost * roomsBooked * numOfDays;
			totalRoomCost = totalRoomCost - (totalRoomCost * discount);
			salesTax = totalRoomCost * (salesTax / 100);
			billingAmount = totalRoomCost + salesTax;

			cout << "Cost of one room: $" << roomCost << endl
				 << "Discount on each room: " << discount * 100 << "%" << endl
				 << "Rooms booked: " << roomsBooked << endl
				 << "Number of days each room is booked: " << numOfDays
				 << endl << "Total cost: $" << totalRoomCost << endl
				 << "Sales tax: $" << salesTax << endl
				 << "Total billing amount: $" << billingAmount << endl << endl;
		}

		else if (roomsBooked >= 10)
		{
			discount = TENROOMS;

			if (numOfDays >= 3)
				discount += THREEDAYDISCOUNT;

			totalRoomCost = roomCost * roomsBooked * numOfDays;
			totalRoomCost = totalRoomCost - (totalRoomCost * discount);
			salesTax = totalRoomCost * (salesTax / 100);
			billingAmount = totalRoomCost + salesTax;

			cout << "Cost of one room: $" << roomCost << endl
				 << "Discount on each room: " << discount * 100 << "%" << endl
				 << "Rooms booked: " << roomsBooked << endl
				 << "Number of days each room is booked: " << numOfDays
				 << endl << "Total cost: $" << totalRoomCost << endl
				 << "Sales tax: $" << salesTax << endl
				 << "Total billing amount: $" << billingAmount << endl << endl;
		}

		else
		{
			if (numOfDays >= 3)
				discount += THREEDAYDISCOUNT;

			totalRoomCost = roomCost * roomsBooked * numOfDays;
			totalRoomCost = totalRoomCost - (totalRoomCost * discount);
			salesTax = totalRoomCost * (salesTax / 100);
			billingAmount = totalRoomCost + salesTax;

			cout << "Cost of one room: $" << roomCost << endl
				 << "Discount on each room: " << discount * 100 << "%" << endl
				 << "Rooms booked: " << roomsBooked << endl
				 << "Number of days each room is booked: " << numOfDays
				 << endl << "Total cost: $" << totalRoomCost << endl
				 << "Sales tax: $" << salesTax << endl
				 << "Total billing amount: $" << billingAmount << endl << endl;
		}

		cout << "Do you have another booking? (y/n) ";
		cin >> yesOrNo;
		cout << endl;
	}

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

