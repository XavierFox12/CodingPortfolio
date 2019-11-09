/* Program: Xavier_Fox_Chp_3_Exercise_5.cpp
   Programmer: Xavier Fox
   Date: 23 Sep. 2014
   Purpose: To determine the total number of tickets sold
   and the total sales amount.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
	double ticketPrice, saleAmount = 0;
	int numberOfTicketsSold, totalTicketsSold = 0;

	ifstream inFile;
	inFile.open("E:\\C++\\ticketData.txt");
	if (!inFile)
	{
		cout << "Cannot open the file ticketData.txt" <<endl
			 << "The program terminates" << endl << endl;
		return 1;
	}
	inFile >> ticketPrice >> numberOfTicketsSold;

	cout << setw(50) << "Football Ticket Sales" << endl << endl
		 << setw(30) << "TicketPrice" << setw(34) << "Number of tickets"
		 << endl << endl;


	while (inFile)
	{
		cout << fixed << showpoint << setprecision(2);

		cout << setw(27) << ticketPrice << setw(32) << numberOfTicketsSold
			 << endl;

		saleAmount += ticketPrice * numberOfTicketsSold;
		totalTicketsSold += numberOfTicketsSold;
		
		inFile >> ticketPrice >> numberOfTicketsSold;
	}


	cout << endl << setw(50) << "Total number of tickets sold = "
		 << totalTicketsSold << endl
		 << setw(40) << "Total sale amount = $"
		 << saleAmount << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	inFile.close();
	return 0;
}

