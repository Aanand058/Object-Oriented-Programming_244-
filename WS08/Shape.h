
#ifndef SDDS_SHAPE_H__
#define SDDS_SHAPE_H__
#include <iostream>
namespace sdds
{
	class Shape {
	public:
		//Pure virtual functions 
		virtual void draw(std::ostream& os) const = 0;

		virtual void getSpecs(std::istream& is) = 0;

	
		//Virtual empty Destructor
		virtual ~Shape() ;
	
	};
	
	//Helper Funtions 
	std::ostream& operator<<(std::ostream& os, const Shape& s);
	std::istream& operator>>(std::istream& is, Shape& a);
}
#endif // !
