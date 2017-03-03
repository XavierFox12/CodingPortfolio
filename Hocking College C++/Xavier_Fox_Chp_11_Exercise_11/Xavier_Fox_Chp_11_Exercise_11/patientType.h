/* Program: patientType.h
   Programmer: Xavier Fox
   Date: 30 Jan. 2015
   purpose: Establishes the members of the patientType class
*/
#ifndef H_patientType
#define H_patientType
#include "stdafx.h"
#include <iostream>
#include <string>
#include "dateType.h"
#include "doctorType.h"

using namespace std;

class patientType:public personType
{
private:
	string ID;
	doctorType physician;
	dateType dateOfBirth;
	dateType admissionDate;
	dateType dischargeDate;

public:
	void setInfo(string patientID="", string fName="", string lName="",
				 string docLname="", string docFname="", string speciality="",
				 int bDay=1, int bMonth=1, int bYear=1900, int aDay=1,int aMonth=1,
				 int aYear=1900, int disDay=1, int disMonth=1, int disYear=1900);
	void print() const;
	void setID(string);
    string getID() const;
    void setDoctorName(string docFname="", string docLname="");
    void setDoctorSpeciality(string speciality="");
    string getDoctorFname() const;
    string getDoctorLname() const;
    string getDoctorSpeciality() const;
    void setBirthDate(int bDay=1, int bMonth=1, int bYear=1900);
    int getBirthDay() const;
    int getBirthMonth() const;
    int getBirthYear() const;
    void setAdmissionDate(int aDay=1,int aMonth=1, int aYear=1900);
    int getAdmissionDay() const;
    int getAdmissionMonth() const;
    int getAdmissionYear() const;
    void setDischargeDate(int disDay=1, int disMonth=1, int disYear=1900);
    int getDischargeDay() const;
    int getDischargeMonth() const;
    int getDischargeYear() const;
	patientType(string patientID="", string fName="", string lName="",
				 string docLname="", string docFname="", string speciality="",
				 int bDay=1, int bMonth=1, int bYear=1900, int aDay=1, int aMonth=1,
				 int aYear=1900, int disDay=1, int disMonth=1, int disYear=1900);
};

#endif