/***********************************************************************
// OOP244 Workshop 8
// File: Shape.cpp

Student Name: Aanand Aman
Student ID: 166125211
Email: aaman8@myseneca.ca


  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Shape.h"
using namespace std;

namespace sdds {


	std::ostream& operator<<(std::ostream& os, const Shape& s)
	{
		s.draw(os);
		return os;
	}

	std::istream& operator>>(std::istream& is, Shape& a)
	{
		a.getSpecs(is);
		return is;
	}

	//Empty Deconsturctor
	Shape::~Shape()
	{
	}

}
