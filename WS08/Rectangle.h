
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
