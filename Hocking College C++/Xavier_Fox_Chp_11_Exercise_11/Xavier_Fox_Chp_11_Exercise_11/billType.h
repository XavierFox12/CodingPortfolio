/* Program: billType.cpp
   Programmer: Xavier Fox
   Date: 30 Jan. 2015
   Purpose: Defines the members of the billType class
*/

#ifndef H_billType
#define H_billType

#include "stdafx.h"
#include <string>

using namespace std;

class billType
{
private:
	string ID;
	double pharmacyCharges;
	double doctorFee;
	double roomCharges;

public:
	void printBill() const;
	void setInfo(string billID="", double pharmacy=0.0, double doctor=0.0,
				double room=0.0);
	void setID(string billID);
	void setPharmacy(double pharmacy);
	void setDoctorFee(double doctor);
	void setRoom(double room);
	string getID() const;
	void updateID(string billID="");
	double getPharmacy() const;
	void updatePharmacy(double pharmacy=0.0);
	double getDoctorFee() const;
	void updateDoctorFee(double doctor=0.0);
	double getRoom() const;
	void updateRoom(double room=0.0);
	double getBillingAmount() const;
	billType(string billID="", double pharmacy=0.0, double doctor=0.0,
			double room=0.0);
};
#endif