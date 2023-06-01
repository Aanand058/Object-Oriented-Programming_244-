/***********************************************************************
// OOP244 Workshop 8
// File: Rectangle.cpp

Student Name: Aanand Aman
Student ID: 166125211
Email: aaman8@myseneca.ca


  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////
***********************************************************************/


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Rectangle.h"
#include "Utils.h"

using namespace std;

namespace sdds {



	Rectangle::Rectangle() : LblShape()
	{
		this->m_height = 0;
		this->m_width = 0;

	}

	Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label)
	{
		
			this->m_height = height;
			this->m_width = width;

            if (this->m_height < 3 || this->m_width < (strlen(label) + 2) )
            {
                this->m_height = 0;
                this->m_width = 0;
            }

		
	}

	void Rectangle::getSpecs(std::istream& is)
	{
		LblShape::getSpecs(is);
        is >> this->m_width;
        is.ignore();
        is>> this->m_height;
        is.ignore(1000, '\n');
       

	}

	void Rectangle::draw(std::ostream& os) const
	{
		if (this->m_height > 0 && this->m_width > 0) {
            //First line 
            os << "+";
            os.width(this->m_width - 1);
            os.fill('-');
            os << "+";
            os.fill(' ');
            os << endl;


            //Second Line
            os << "|";
            os.setf(ios::left);
            os.width(this->m_width - 2);
            os << label();
            os.unsetf(ios::left);
            os << "|";
            os << endl;

            //Third Blank Lines 3 n 4
            for (int i = 0; i < this->m_height - 3; i++)
            {
                os << "|";
                os.width(this->m_width - 1);
                os.fill(' ');
                os << "|";
                os << endl;
            }


            //Last Line
            os << "+";
            os.width(this->m_width - 1);
            os.fill('-');
            os << "+";
            os.fill(' ');
            
		}
	}

}