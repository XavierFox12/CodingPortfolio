/* Program: Xavier_Fox_Chp_9_Exercise_1.cpp
   Programmer: Xavier Fox
   Date: 1 Dec. 2014
   Purpose:
*/

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct fruitType
{
	string fruitName;
	string color;
	int fat;
	int sugar;
	int carbohydrate;
};

int main()
{
	fruitType fruit;

	cout << "Enter the data about a fruit: " << endl;
	cout << "Name: ";
	cin >> fruit.fruitName;
	cout << "Color: ";
	cin >> fruit.color;
	cout << "Fat: ";
	cin >> fruit.fat;
	cout << "Sugar: ";
	cin >> fruit.sugar;
	cout << "Carbohydrates: ";
	cin >> fruit.carbohydrate;
	cout << endl;

	cout << "Name: " << fruit.fruitName << endl << "Color: "
		 << fruit.color << endl << "Fat: " << fruit.fat << endl
		 << "Sugar: " << fruit.sugar << endl << "Carbohydrates: "
		 << fruit.carbohydrate << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

