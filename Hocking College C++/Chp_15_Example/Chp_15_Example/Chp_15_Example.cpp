// Chp_15_Example.cpp

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int frequency(char ch, string inputString, int pos);

int main()
{
	string inputString = "ghaohoiehovoheh;HGIOENV";

	cout << "The character o appears "
		<< frequency('o', inputString, 0) << " time(s).";

	return 0;
}

int frequency(char ch, string inputString, int pos)
{
	if (pos == inputString.length())
		return 0;
	
	if (inputString[pos] == ch)
		return 1 + frequency(ch, inputString, pos+1);
	else
		return frequency(ch, inputString, pos+1);
}