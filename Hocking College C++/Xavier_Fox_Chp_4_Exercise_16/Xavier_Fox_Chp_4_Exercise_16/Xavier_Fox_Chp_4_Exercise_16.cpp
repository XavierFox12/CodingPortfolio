/* Program: Xavier_Fox_Chp_4_Exercise_16.cpp
   Programmer: Xavier Fox
   Date: 7 Oct. 2014
   Purpose: To determine which option will make
   the author the most money.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int copiesSold;
	double netPrice, option1, option2, option3;

	cout << "Enter the number of copies sold: ";
	cin >> copiesSold;
	cout << endl;

	cout << "Enter the net price of one book: ";
	cin >> netPrice;
	cout << endl;

	option1 = 5000 + 20000;
	option2 = (netPrice * .125) * copiesSold;

	if (copiesSold < 4000)
	{
		option3 = (netPrice * .10) * copiesSold;
	}

	else if (copiesSold >= 4000)
	{
		option3 = (netPrice * .10) * 4000;
		option3 += (netPrice * .14) * (copiesSold - 4000);
	}

	cout << fixed << showpoint << setprecision(2);

	if (option1 >= option2 && option1 >= option3)
	{
		if (option1 == option2)
		{
			cout << "Option 1 and option 2 are the same and give the "
				 << "best royalty, which is: " << option1 << endl;
		}
		else if ( option1 == option3)
		{
			cout << "Option 1 and option 3 are the same and give the "
				 << "best royalty, which is: " << option1 << endl;
		}
		else
		{
			cout << "Option 1 is the best and the royalty is: "
				 << option1 << endl;
		}
	}

	else if (option2 >= option1 && option2 >= option3)
	{
		if (option1 == option2)
		{
			cout << "Option 1 and option 2 are the same and give the "
				 << "best royalty, which is: " << option1 << endl;
		}
		else if ( option2 == option3)
		{
			cout << "Option 2 and option 3 are the same and give the "
				 << "best royalty, which is: " << option1 << endl;
		}
		else
		{
			cout << "Option 2 is the best and the royalty is: "
				 << option2 << endl;
		}
	}

	else
	{
		if (option3 == option2)
		{
			cout << "Option 2 and option 3 are the same and give the "
				 << "best royalty, which is: " << option1 << endl;
		}
		else if ( option1 == option3)
		{
			cout << "Option 1 and option 3 are the same and give the "
				 << "best royalty, which is: " << option1 << endl;
		}
		else
		{
			cout << "Option 3 is the best and the royalty is: "
				 << option3 << endl;
		}
	}

	cout << "   Royalty option 1: " << option1 << endl
		 << "   Royalty option 2: " << option2 << endl
		 << "   Royalty option 3: " << option3 << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

