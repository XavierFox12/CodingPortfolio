/* Program: Xavier_Fox_Chp_4_Exercise_18.cpp
   Programmer: Xavier Fox
   Date: 9 Oct. 2014
   Purpose: To determine the body fat of a person based
   on their gender and measurements.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	char gender, yesOrNo = 'y';
	double bodyWeight, wristMeasurement, hipMeasurement,
		   waistMeasurement, forearmMeasurement, bodyFat,
		   bodyFatPercentage,answer1, answer2, answer3, answer4,
		   answer5, answer6;

	while (yesOrNo == 'y')
	{
		cout << "Are you male or female:(m/M, f/F) ";
		cin >> gender;
		cout << endl;

		if (gender == 'f' || gender == 'F')
		{
			cout << "Enter your weight (in pounds): ";
			cin >> bodyWeight;
			cout << endl;

			cout << "Enter your wrist measurement (in inches): ";
			cin >> wristMeasurement;
			cout << endl;

			cout << "Enter your waist measurement (in inches): ";
			cin >> waistMeasurement;
			cout << endl;

			cout << "Enter your hip measurement (in inches): ";
			cin >> hipMeasurement;
			cout << endl;
		
			cout << "Enter your forearm measurement (in inches): ";
			cin >> forearmMeasurement;
			cout << endl;

			answer1 = (bodyWeight * .732) + 8.987;
			answer2 = wristMeasurement / 3.14;
			answer3 = waistMeasurement * .157;
			answer4 = hipMeasurement * .249;
			answer5 = forearmMeasurement * .434;
			answer6 = answer1 + answer2 - answer3 - answer4 + answer5;
			bodyFat = bodyWeight - answer6;
			bodyFatPercentage = bodyFat * 100 / bodyWeight;

			cout << "Body fat: " << bodyFat << endl
				 << "Body fat percentage: " << bodyFatPercentage
				 << endl << endl;
		}

		else if (gender == 'm' || gender == 'M')
		{
			cout << "Enter your weight (in pounds): ";
			cin >> bodyWeight;
			cout << endl;

			cout << "Enter your wrist measurement (in inches): ";
			cin >> wristMeasurement;
			cout << endl;

			answer1 = (bodyWeight * 1.082) + 94.42;
			answer2 = wristMeasurement * 4.15;
			answer3 = answer1 - answer2;
			bodyFat = bodyWeight - answer3;
			bodyFatPercentage = bodyFat * 100 / bodyWeight;

			cout << "Body fat: " << bodyFat << endl
				 << "Body fat percentage: " << bodyFatPercentage
				 << endl << endl;
		}

		else
			cout << gender << " is not an acceptable gender" << endl << endl;

		cout << "Do you want to continue? (y/n) ";
		cin >> yesOrNo;
		cout << endl;
	}

	cout << "Program by: Xavier Fox" << endl << endl;

	return 0;
}

