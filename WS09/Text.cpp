/* ------------------------------------------------------
Workshop 9 part 1

Filename: Text.cpp
Version 1
-----------------------------------------------------------
Name: Aanand Aman
Student ID: 166125211
EMail: aaman8@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Text.h"
#include "Utils.h"



namespace sdds
{
	const char& Text::operator[](int index) const
	{
		return this->m_content[index];
	}
	Text::Text()
	{
		this->m_content = nullptr;
	}
	Text::~Text()
	{
		setEmpty();
	}
	void Text::setEmpty()
	{
		delete[] this->m_content;
		this->m_content = nullptr;
	}
	Text::Text(const Text& toCopyFrom)
	{
		*this = toCopyFrom;
	}
	Text& Text::operator=(const Text& toCopyFrom)
	{
		if (this != &toCopyFrom ) {

			setEmpty();
			this->m_content = new char[strlen(toCopyFrom.m_content) + 1];
			strcpy(this->m_content, toCopyFrom.m_content);
		}
		
		return *this;
	}
	std::istream& Text::read(std::istream& istr)
	{
		
		setEmpty();
		
		this->m_content = new char[getFileLength(istr) + 1];

		istr.get(this->m_content, (getFileLength(istr) + 1), '\0');

		if (!istr.fail()) {
			istr.clear();
		}
		return istr;
		
	}
	std::ostream& Text::write(std::ostream& ostr) const
	{
		if (this->m_content != nullptr) {
			ostr << this->m_content;
		}
		return ostr;
	}

	unsigned Text::getFileLength(std::istream& is)
	{
		unsigned len{};
		if (is) {
			// save the current read position
			std::streampos cur = is.tellg();
			// go to the end
			is.seekg(0, std::ios::end);
			// tell what is the positions (end position = size)
			len = unsigned(is.tellg());
			// now go back to where you were.
			is.seekg(cur);
		}
		return len;
	}
	
	std::ostream& operator<<(std::ostream& ostr, const Text& t) 
	{
		t.write(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, Text& tx)
	{
		tx.read(istr);
		return istr;
	}

	
}