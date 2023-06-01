

#ifndef SDDS_PARKING_H__
#define SDDS_PARKING_H__

#include <iostream>
#include "Menu.h"
 


namespace sdds
{
	class Parking {

		char* p_filename;

		Menu p_parkingMenu{"Parking Menu, select an action:", 0};      //initializing the two parameter constructor of Menu

		Menu p_vehicleSelection{"Select type of the vehicle:", 1};


		bool isEmpty() const;

		void parkStatus()const;

		void parkVehicle()const;

		void returnVehicle()const;

		void parkListVehicle()const;

		void findVehicle()const;

		bool closeParking()const;

		bool exitParking()const;

		bool loadDataFile()const;

		void savaDataFile()const;


		//Extre metho created for validation for close and exit parking as both have same implimentation
		bool closeOrExit() const;

	public:
		//Construtors 
		Parking();
		Parking(const char* filename);


		//Deconstrutor 
		~Parking();

		//copy constructor and assignment is denied 
		Parking(const Parking& toCopyFrom) = delete;
		Parking operator=(const Parking& toCopyFrom) = delete;


		int run();


	};
	

	

}
#endif // !
