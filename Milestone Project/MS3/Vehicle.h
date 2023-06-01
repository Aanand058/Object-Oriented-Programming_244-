


#ifndef SDDS_VEHICLE_H__
#define SDDS_VEHICLE_H__

#include <iostream>
#include "ReadWritable.h"


namespace sdds
{
	class Vehicle : public ReadWritable {
		char m_plate[8 + 1];
		char* m_makeModel;
		int m_pSpotNum;


	protected:                                     //learnt from milestone 3 overview video by professor fardard
		void setEmpty();

		bool isEmpty() const;

		

		void setMakeModel(const char* value);

		

		

	public:
		//Constructors
		Vehicle();
		Vehicle(const char* plate, const char* makemodel);

		//Copy constructor and assignment 
		Vehicle(const Vehicle& toCopyFrom);
		Vehicle& operator=(const Vehicle& toCopyFrom);

		//Deconstuctor
		~Vehicle();

	
		const char* getLicensePlate() const;

		char* getMakeModel() const;
		void setParkingSpot(int value);
		int getParkingSpot() const;

		bool operator==(const char* plateValue);

		

		std::istream& read(std::istream& is);


		//writeType (Pure virtual)
		virtual std::ostream& writeType(std::ostream& ostr) const = 0;


		std::ostream& write(std::ostream& ostr) const;


	};
	//Comapring two vehilce license plate 
	bool operator==(const Vehicle& v1,const Vehicle& v2);

	



}
#endif // !
