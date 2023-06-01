

#ifndef SDDS_TEXT_H_
#define SDDS_TEXT_H_
#include <iostream>

namespace sdds
{
	class Text {
		char* m_content = nullptr;

	protected:
		const char& operator[](int index)const;

	public:
		//Constructor
		Text();

		
		
		//Making the class Empty
		void setEmpty();


		//Rule of three
		Text(const Text& toCopyFrom);
		Text& operator=(const Text& toCopyFrom);
		~Text();

		//read
		std::istream& read(std::istream& istr);

		//write
		virtual std::ostream& write(std::ostream& ostr) const;


		//getfileLength
		unsigned getFileLength(std::istream& is);

		
	};
	

	//Helper Funtions
	std::ostream& operator<<(std::ostream& ostr, const Text& t) ;
	std::istream& operator>>(std::istream& istr, Text& tx);
}

#endif