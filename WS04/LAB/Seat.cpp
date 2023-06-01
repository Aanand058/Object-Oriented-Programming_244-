/***********************************************************************
// OOP244 Workshop 4 p1: tester program
//
// File	Seat.cpp
// Version 1.0
// Date	2022/09/27
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name Aanand Aman           Date Oct 6. 2022           Reason
//
During this assignment I got help from two person. One from my professor about the memory leak problem and Another
help from my friend RUbal Preet Singh email(nrubalpreet-singh@myseneca.ca). My friend help me in this function: 
Seat::Seat(const char *passengerName, int row, char letter)
	{
		
		
			if (validate(row, letter)) 
      {
			  set(row, letter);
				alAndCp(passengerName);  
			}
			else 
      {
				this->plane_row = 0;
				this->plane_letter = '\0';
			}

	}
 Here I was not calling this alAndCp(passengerName); as it was not clear in the instruction so my friend told me to write this line and the code 
 statred reading the files correctly. Before that I was not getting the correct Output. 
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include <fstream>
#include "Utils.h"
#include "Seat.h"

using namespace std;

namespace sdds{

	bool Seat::validate(int row, char letter) const
	{
		if (row > 0 && row < 5)
		{
			if (letter == 'A' || letter == 'B' || letter == 'E' || letter == 'F')
			{
				return true;
			}

			else
			{
				return false;
			}
		}

		if ((row > 6 && row < 16))
		{
			if (letter == 'A' || letter == 'B' || letter == 'C' || letter == 'D' || letter == 'E' || letter == 'F')
			{
				return true;
			}

			else
			{
				return false;
			}
		}

		if ((row > 19 && row < 39))
		{
			if (letter == 'A' || letter == 'B' || letter == 'C' || letter == 'D' || letter == 'E' || letter == 'F')
			{
				return true;
			}

			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	Seat& Seat::alAndCp(const char *str)
	{

		this->pass_name = nullptr;

		if (str != nullptr)
		{
			if(strlen(str)> 1)
			{
				int stringLength = 0;
				stringLength = strlen(str);

				this->pass_name = new char[stringLength + 1];

				strcpy(this->pass_name, str);
			}
				
			
		}

		return *this;
	}

	Seat& Seat::reset()
	{
		delete[] pass_name;
		this->pass_name = nullptr;
		this->plane_row = 0;
		this->plane_letter = '\0';

		return *this;
	}

	bool Seat::isEmpty() const
	{
		if (this->pass_name == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Seat::assigned() const
	{
		if (validate(this->plane_row, this->plane_letter))
		{
			return true; 
		}
		else
		{
			return false;
		}
	}

	Seat::Seat()  //constructor which sets the object to null state 
	{
		
		this->pass_name = nullptr;
		this->plane_row = 0;
		this->plane_letter = '\0';
	}

	Seat::Seat(const char *passengerName)
	{
		if (passengerName != NULL)
		{
			if (strlen(passengerName) > 1)
			{
				alAndCp(passengerName);
				this->plane_row = 0;
				this->plane_letter = '\0';
			}
				

		}
	}

	Seat::Seat(const char *passengerName, int row, char letter)
	{
		
		
			if (validate(row, letter)) 
      {
			  set(row, letter);
				alAndCp(passengerName);  
			}
			else 
      {
				this->plane_row = 0;
				this->plane_letter = '\0';
			}

	}

	Seat::~Seat()  //Deconstructor deallocating the dynamic memory which are created in the code 
	{
		delete[] pass_name;
		
	}

	Seat &Seat::set(int row, char letter)
	{
		if (validate(row, letter))
		{
			this->plane_row = row;
			this->plane_letter = letter;
		}
		else
		{
			this->plane_row = 0;
			this->plane_letter = '\0';
		}
		return *this;
	}

	int Seat::row() const
	{
		return this->plane_row;
	}

	char Seat::letter() const
	{
		return this->plane_letter;
	}

	const char *Seat::passenger() const
	{
		return this->pass_name;
	}

	std::ostream &Seat::display(std::ostream &coutRef) const
	{
		if (this->pass_name)
		{
			char temp_Name[41];
			strcpy(temp_Name, this->pass_name, 40);  //truncating the name to length of 40 and using local variable to display  
      
			coutRef.width(40);
			coutRef.fill('.');
			coutRef.setf(ios::left);
			coutRef << temp_Name;
      
      coutRef.fill(' ');
			coutRef.unsetf(ios::left);
      
			if (this->plane_row == 0)
			{
				coutRef << " ___";
			}
			else
			{
				coutRef << " " << this->plane_row << this->plane_letter;
			}
		}
		else
		{
			cout << "Invalid Seat!";
		}

		return coutRef;
	}

	std::istream &Seat::read(std::istream &cinRef)
	{
		reset();
   
		char ls_name[70 + 1];
		char ls_letter;
   
    int ls_row = 0;

		cinRef.getline(ls_name, 71, ',');  //learn this from previous workshop 3 
		cinRef >> ls_row;
		cinRef.get(ls_letter);
		cinRef.ignore(); 
   
		if(!cinRef.fail())
    {
			alAndCp(ls_name);
			set(ls_row, ls_letter);
		}
			
		
		return cinRef;
	}
}