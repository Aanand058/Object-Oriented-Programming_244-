
#ifndef SDDS_MOTORCYCLE_H__
#define SDDS_MOTORCYCLE_H__
#include "Vehicle.h"

namespace sdds
{
	class Motorcycle :public Vehicle {
		bool m_sideCar;

	public:
		//Construtor
		Motorcycle();

		Motorcycle(const char* plate, const char* makemodel);


		//Rule of three 
		Motorcycle(const Motorcycle& toCopyFrom);
		Motorcycle& operator=(const Motorcycle& toCopyrom);
		~Motorcycle();


		//writeType
		std::ostream& writeType(std::ostream& ostr) const;


		//read
		std::istream& read(std::istream& istr);

		//write
		std::ostream& write(std::ostream& ostr) const;
	};


}
#endif // !
