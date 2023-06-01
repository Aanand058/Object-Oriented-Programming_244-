/*
Name: Aanand Aman
Email: aaman8@myseneca.ca 
Student ID: 166125211
Data: 2022/11/09
Section: ZEEL
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_VehicleBasic_H
#define SDDS_VehicleBasic_H
#include<iostream>
using namespace std;

namespace sdds
{
		class VehicleBasic {

		char m_plate[9 + 1];
		char m_address[64 + 1];
		int m_year;

	public:
		//Construtors
		VehicleBasic();
		VehicleBasic(const char* platenum,int year);

		//Deconstrutor
		~VehicleBasic();


		//Moves the vehicle to new address
		void NewAddress(const char* address);


		ostream& write(ostream& os) const;

		istream& read(istream& in);


	};
		//Helper Functions
		ostream& operator<<(ostream& os, const VehicleBasic& vB);
		istream& operator>>(istream& in, VehicleBasic& vB);


}

#endif

