
#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__
#include "Vehicle.h"

namespace sdds
{
	class Car : public Vehicle{
		bool m_carWashFlag;

	public:
		//Constructors
		Car();
		Car(const char* plate, const char* makemodel);

		//Rule of three
		Car(const Car& toCopyFrom);
		Car& operator=(const Car& toCopyFrom);
		~Car();

		//writeType
		std::ostream& writeType(std::ostream& ostr) const; 

		//Read
		std::istream& read(std::istream& istr);

		//Write
		std::ostream& write(std::ostream& ostr) const;


	};
	

}
#endif // !
