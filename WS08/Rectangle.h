/***********************************************************************
// OOP244 Workshop 8
// File: Rectangle.h

Student Name: Aanand Aman
Student ID: 166125211
Email: aaman8@myseneca.ca


  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_RECTANGLE_H__
#define SDDS_RECTANGLE_H__

#include <iostream>
#include "LblShape.h"

namespace sdds
{
	class Rectangle:public LblShape {
		int m_width;
		int m_height;
	public:

		//Constructors
		Rectangle();
		Rectangle(const char* label, int width, int height);

		////Descontrutor This class has no destructor implemented.
		//~Rectangle();


		//Reads comma-separated specs of the Rectangle from istream.
		void getSpecs(std::istream& is);

		//This function overrides the draw function of the base class.
		void draw(std::ostream& os) const;



	};



}
#endif // !
