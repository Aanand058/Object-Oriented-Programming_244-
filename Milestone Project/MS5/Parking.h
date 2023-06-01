

#ifndef SDDS_PARKING_H__
#define SDDS_PARKING_H__

#include <iostream>
#include "Menu.h"

#include "Vehicle.h"



const int MAX_NO_OF_PARKING_SPOTS = 100;

namespace sdds
{
	class Parking {

		char* p_filename;

		Menu p_parkingMenu{ "Parking Menu, select an action:", 0 };      //initializing the two parameter constructor of Menu

		Menu p_vehicleSelection{ "Select type of the vehicle:", 1 };


		bool isEmpty() const;

		void parkStatus()const;

		void parkVehicle();

		void returnVehicle();

		void parkListVehicle()const;

		void findVehicle();

		bool closeParking();

		bool exitParking()const;

		bool loadDataFile();

		void savaDataFile()const;



		//MS5 Additional Mandotory Attributes
		int p_noOfPSpots=0;

		Vehicle* p_parkingSpots[MAX_NO_OF_PARKING_SPOTS]{};

		int p_noOfParkedVehicles = 0; 


	public:
		//Construtors 
		Parking();
		Parking(const char* filename, int noOfSpots);


		//Deconstrutor 
		~Parking();

		//copy constructor and assignment is denied 
		Parking(const Parking& toCopyFrom) = delete;
		Parking operator=(const Parking& toCopyFrom) = delete;


		int run();


	};




}
#endif // !
