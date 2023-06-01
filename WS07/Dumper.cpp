
#include<iostream>
#include "Dumper.h"
#include "VehicleBasic.h"

using namespace std;
namespace sdds
{

	
	Dumper::Dumper()
	{
		this->n_maxWeight = 0.0;
		this->n_cargoLoad = 0.0;

	}

	Dumper::~Dumper()
	{
		this->n_maxWeight = 0.0;
		this->n_cargoLoad = 0.0;

	}

								//Inherting the base class constructor VehicleBasic 
	Dumper::Dumper(const char* plate, int year, float loadCap, const char* add) : VehicleBasic(plate , year)
	{
		this->n_maxWeight = loadCap; 
		this->n_cargoLoad = 0;
		this->NewAddress(add);		//Calling the base class address method 

	}

	bool Dumper::loaddCargo(double cargo)
	{
		if (this->n_cargoLoad + cargo <= this->n_maxWeight)
 {
			this->n_cargoLoad = this->n_cargoLoad + cargo; 
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Dumper::unloadCargo()
	{
		if (this->n_cargoLoad == 0)
		{
			return false; 
		}
		else if (this->n_cargoLoad > 0) {
			this->n_cargoLoad = 0;
			return true;
		}
   else{return false;}
	}

	ostream& Dumper::write(ostream& os) const
	{
		VehicleBasic::write(os);			//Inherting base class write 
		os << " | " << this->n_cargoLoad << "/" << this->n_maxWeight;
		return os;
	}

	istream& Dumper::read(istream& in)
	{
		VehicleBasic::read(in);				//Inherting base class write 
		cout << "Capacity: ";
		in >> this->n_maxWeight;
		cout << "Cargo: ";
		in >> this->n_cargoLoad;

		return in;
	}

	
	ostream& operator<<(ostream& os, const Dumper& d) 
	{
		d.write(os);
		return os;
	}

	istream& operator>>(istream& in, Dumper& d)
	{
		d.read(in);
		return in;
	}

}

