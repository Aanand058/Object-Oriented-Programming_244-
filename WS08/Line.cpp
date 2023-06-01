/***********************************************************************
// OOP244 Workshop 8 
// File: Line.cpp

Student Name: Aanand Aman
Student ID: 166125211
Email: aaman8@myseneca.ca


  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////
***********************************************************************/



#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "Line.h"
#include "Utils.h"

using namespace std; 

namespace sdds {
	Line::Line() : LblShape()
	{
		this->m_length = 0;
	}

	Line::Line(const char* lengthLine, int lenghtLine): LblShape(lengthLine)
	{
		this->m_length = lenghtLine;
	}

	void Line::getSpecs(std::istream& is) 
	{
		LblShape::getSpecs(is);
		is >> this->m_length;
		is.ignore(1000, '\n');

	}

	void Line::draw(std::ostream& os) const 
	{
		
		if (this->m_length > 0 && LblShape::label() != nullptr) {
			os << LblShape::label();
			for (int i = 0; i < this->m_length - strlen(LblShape::label()); i++) {
				os << "=";
			}
		}
	}
}
