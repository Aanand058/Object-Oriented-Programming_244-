/*
Name: Aanand Aman
Email: aaman8@myseneca.ca
Student ID: 166125211
Data: 2022/11/09
Section: ZEEL
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_Dumper_H
#define SDDS_Dumper_H
#include <iostream>
#include "VehicleBasic.h"

using namespace std;

namespace sdds
{
	//Inheriting from base class VehicleBasic 
	class Dumper : public VehicleBasic {
		float n_maxWeight;
		float n_cargoLoad;
	public:

		//Construtors
		Dumper();
		Dumper(const char* plate, int year, float loadCap, const char* add);


		//Deconstrutor 
		~Dumper();


		bool loaddCargo(double cargo);

		bool unloadCargo();

		ostream& write(ostream& os) const;

		istream& read(istream& in);

	};

	//Helper Funtions 
	ostream& operator<<(ostream& os, const Dumper& d);
	istream& operator>>(istream& in, Dumper& d);
}
#endif
