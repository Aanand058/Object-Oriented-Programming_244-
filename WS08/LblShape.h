
#ifndef SDDS_LBLSHAPE_H__
#define SDDS_LBLSHAPE_H__

#include <iostream>
#include "Shape.h"


namespace sdds
{
	class LblShape : public Shape {
		char* m_label{ nullptr };

	protected:
		char* label() const;



	public:

		//Construtors 
		LblShape();
		LblShape(const char* label);


		//Deconstructor 
		~LblShape();


		//Copy and assignment copy is denied 
		LblShape(const LblShape& toCopyfrom) = delete;
		LblShape& operator=(const LblShape& toCopyFrom) = delete;

		//Reads a comma-delimited Cstring form istream:
		void getSpecs(std::istream& is);


	};


}
#endif 
