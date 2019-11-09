/* Program: Xavier_Fox_Chp_11_Exercise_11.cpp
   Programmer: Xavier Fox
   Date: 30 Jan. 2015
   Purpose: To print out the total hopital bill
*/

#include "stdafx.h"
#include <string>
#include <iostream>
#include <iomanip>
#include "doctorType.h"
#include "billType.h"
#include "patientType.h"

using namespace std;

int main()
{
	billType hospitalBill;
	patientType patient;

	string ID, fName, lName, speciality;
	int month, day, year;
	double pharmacyCharge, roomCharge, doctorCharge;

	cout << setw(50) << "County Hospital Billing System" << endl;
	cout << setw(50) << "      By: Xavier Fox          " << endl << endl;

	cout << "Enter patient's ID: ";
	cin >> ID;
	patient.setID(ID);

	cout << "Enter patient's first name: ";
	cin >> fName;

	cout << "Enter patient's last name: ";
	cin >> lName;
	patient.setName(fName, lName);

	cout << "Enter patient's admission date (mm dd yyyy): ";
	cin >> month >> day >> year;
	patient.setAdmissionDate(month, day, year);

	cout << "Enter patient's discharge date (mm dd yyyy): ";
	cin >> month >> day >> year;
	cout << endl;
	patient.setDischargeDate(month, day, year);

	cout << "Enter doctor's first name: ";
	cin >> fName;

	cout << "Enter doctor's last name: ";
	cin >> lName;
	patient.setDoctorName(fName, lName);

	cout << "Enter doctor's speciality: ";
	cin >> speciality;
	cout << endl;
	patient.setDoctorSpeciality(speciality);

	cout << "Enter total pharmacy charges: ";
	cin >> pharmacyCharge;
	hospitalBill.setPharmacy(pharmacyCharge);

	cout << "Enter total room charges: ";
	cin >> roomCharge;
	hospitalBill.setRoom(roomCharge);

	cout << "Enter total doctor charge: ";
	cin >> doctorCharge;
	cout << endl << endl;
	hospitalBill.setDoctorFee(doctorCharge);

	patient.print();
	hospitalBill.printBill();

	return 0;
}

