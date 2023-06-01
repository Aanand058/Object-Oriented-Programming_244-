/***********************************************************************
// OOP244 Workshop 8
// File: Line.h

Student Name: Aanand Aman
Student ID: 166125211
Email: aaman8@myseneca.ca


  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_LINE_H__
#define SDDS_LINE_H__

#include "LblShape.h"

namespace sdds
{
	class Line :public LblShape{

		int m_length;

	public:
		//Constuctors
		Line();
		Line(const char* lengthLine, int lenghtLine);

		////Deconstructor This class has no destructor implemented.
		//~Line();

		//Reads comma-separated specs of the Line from istream.
		void getSpecs(std::istream& is);


		//This function overrides the draw function of the base class.
		void draw(std::ostream& os) const;


	};



}
#endif // !
