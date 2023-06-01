
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Dumper.h"
#include "VehicleBasic.h"

using namespace std;
namespace sdds
{
	
	
	
	
	VehicleBasic::VehicleBasic()
	{
		this->m_plate[0] = '\0';
		this->m_address[0] = '\0';
		this->m_year = 0; 
	}
	VehicleBasic::~VehicleBasic()
	{
		this->m_plate[0] = '\0';
		this->m_address[0] = '\0';
		this->m_year = 0;
	}

	VehicleBasic::VehicleBasic(const char* platenum, int year)
	{
		if (platenum != nullptr && year > 0) {
			strcpy(this->m_plate, platenum);
			this->m_year = year;
			strcpy(this->m_address, "Factory");

		}
	}

	void VehicleBasic::NewAddress(const char* address)
	{
		if (strcmp(this->m_address ,address) !=0)
		{
			cout.setf(ios::right);
			cout << "|";
			cout.width(8);
			cout << this->m_plate;

			cout << "| |";
			cout.width(20);
			cout << this->m_address;

			cout << " ---> ";
			cout.width(20);
			cout.unsetf(ios::right);

			cout.setf(ios::left);
			cout << address;
			cout.unsetf(ios::left);

			cout.fill(' ');
			cout << "|" << endl;

			strcpy(this->m_address, address);

		}
	}

	ostream& VehicleBasic::write(ostream& os) const
	{
		os << "| " << this->m_year << " | " << this->m_plate << " | " << this->m_address;
		return os;
	}

	istream& VehicleBasic::read(istream& in)
	{
		

		cout << "Built year: ";
		cin >> this->m_year;
		cin.ignore(1000, '\n');

		cout << "License plate: ";
		in.getline(this->m_plate, 10, '\n');
		

		cout << "Current location: ";
		in.getline(this->m_address, 65, '\n');
		

		return in;
	}

	ostream& operator<<(ostream& os, const VehicleBasic& vB)
	{
		vB.write(os);
		return os;
	}

	istream& operator>>(istream& in, VehicleBasic& vB)
	{
		vB.read(in);
		return in; 
	}

}
