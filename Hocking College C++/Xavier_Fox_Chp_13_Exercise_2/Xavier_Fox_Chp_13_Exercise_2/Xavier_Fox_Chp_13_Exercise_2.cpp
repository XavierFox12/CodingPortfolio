/* Program: Xavier_Fox_Chp_13_Exercise_2.cpp
   Programmer: Xavier Fox
   Date: 25 Feb. 2015
   Purpose: Overloads the operators as nonmembers
*/

#include "stdafx.h"
#include <iostream>
#include "rectangleType.h"

using namespace std;

int main()
{
	rectangleType yard1, yard2, yard3, yard4;

    cout << "Enter length and width for yard1: ";
    cin >> yard1;

    cout << "Enter length and width for yard2: ";
    cin >> yard2;

    cout << "Testing (yard1)" << endl
         << "   yard1: " << yard1 << endl << endl;

    cout << "Testing (yard2)" << endl
         << "   yard2: " << yard2 << endl << endl;

    cout << "Testing (yard3 = yard1 + yard2)" << endl;

    yard3 = yard1 + yard2;

    cout << "   yard3: " << yard3 << endl << endl;

    cout << "Testing (yard4 = yard1 * yard2)" << endl;

    yard4 = yard1 * yard2;

    cout << "   yard4: " << yard4 << endl << endl;

    cout << "Testing (yard1 > yard2)" << endl;

    if (yard1 > yard2)
	{
		cout << "Area of yard1 is not less than or equal to the area of yard2."
             << endl << endl;
	}
	else
	{
        cout << "Area of yard1 is less than or equal to the area of yard2."
             << endl << endl;
	}

    cout << "Testing (yard1++)" << endl;

    yard1++;

    cout << "   New dimension of yard1: " << yard1 << endl << endl;

    cout << "Testing (yard4 == ++yard3)" << endl;

    yard3++;
    yard4 = yard3;

    cout << "   New Dimension of yard3: " << yard3 << endl
		 << "   New Dimension of yard4: " << yard4 << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

