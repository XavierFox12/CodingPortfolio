/* Program: Xavier_Fox_Chp_11_Exercise_4.cpp
   Programmer: Xavier Fox
   Date: 28 Jan. 2015
   Purpose: To determine the shipping cost and
   paint cost for a milk container or juice container
   given their radius and height.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "circleType.h"
#include "cylinderType.h"

using namespace std;

int main()
{
	cylinderType milkContainer;
	cylinderType juiceContainer;
	double radius, height, shippingCost, paintCost;

	cout << fixed << showpoint << setprecision(2);

	cout << "*** Milk Container ***" << endl << endl;

	cout << "Enter the radius of the base and the height (in feet) of the"
		 << endl << "milk container: ";
	cin >> radius >> height;
	cout << endl;

	milkContainer.setRadius(radius);
	milkContainer.setHeight(height);

	cout << "Enter milk shipping cost per liter: $";
	cin >> shippingCost;
	cout << endl;

	cout << "Enter milk container paint cost per square foot: $";
	cin >> paintCost;
	cout << endl;

	shippingCost = milkContainer.volume() * 28.32 * shippingCost;
	paintCost = milkContainer.surfaceArea() * paintCost;

	cout << "Milk shipping cost (per container): $" << shippingCost << endl;
	cout << "Milk container paint cost (per container): $" << paintCost
		 << endl << endl;

	cout << "*** Juice Container ***" << endl << endl;

	cout << "Enter the radius of the base and the height (in feet) of the"
		 << endl << "juice container: ";
	cin >> radius >> height;
	cout << endl;

	juiceContainer.setRadius(radius);
	juiceContainer.setHeight(height);

	cout << "Enter juice shipping cost per liter: $";
	cin >> shippingCost;
	cout << endl;

	cout << "Enter juice container paint cost per square foot: $";
	cin >> paintCost;
	cout << endl;

	shippingCost = juiceContainer.volume() * 28.32 * shippingCost;
	paintCost = juiceContainer.surfaceArea() * paintCost;

	cout << "Juice shipping cost (per container): $" << shippingCost << endl;
	cout << "Juice container paint cost (per container): $" << paintCost
		 << endl << endl;

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

