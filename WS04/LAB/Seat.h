/***********************************************************************
// OOP244 Workshop 4 p1: tester program
//
// File	Seat.h
// Version 1.0
// Date	2022/09/27
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name Aanand Aman           Date Oct 6. 2022           Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_SEAT_H_
#define SDDS_SEAT_H_
namespace sdds
{
	class Seat
	{
 
		char* pass_name;
		char plane_letter;
   
    int plane_row;


		bool validate(int row, char letter) const;
		Seat& alAndCp(const char* str);

	public:
		Seat& reset();
		bool isEmpty() const;
		bool assigned() const;

		Seat(); //Constructor Overloading 
		Seat(const char* passengerName);
		Seat(const char* passengerName, int row, char letter);
   
		~Seat(); //Deconstructor 

		Seat& set(int row, char letter);
   
		int row() const;
		char letter() const;
		const char* passenger() const;
   
		std::ostream& display(std::ostream& coutRef = std::cout) const;  //removed the "= std::cout" part as told by professor in the .cpp file
		std::istream& read(std::istream& cinRef = std::cin);
	};

}
#endif // !SDDS_SEAT_H_
