

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
