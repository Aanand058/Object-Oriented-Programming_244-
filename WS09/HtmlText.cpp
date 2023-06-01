/* ------------------------------------------------------
Workshop 9 part 1

Filename: HtmlText.cpp
Version 1
-----------------------------------------------------------
Name: Aanand Aman
Student ID: 166125211 
EMail: aaman8@myseneca.ca 

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "HtmlText.h"

#include "Utils.h"



namespace sdds
{
	HtmlText::HtmlText() :Text()
	{
		this->m_title = nullptr;
	}

	HtmlText::HtmlText(const char* title) :Text()
	{
		if (title != nullptr) {
			this->m_title = new char[strlen(title) + 1];
			strcpy(this->m_title, title);
		}
		else {
			this->m_title = nullptr;
		}
	}
	HtmlText::~HtmlText()
	{
		setEmpty();
	}
	void HtmlText::setEmpty()
	{
		delete[] this->m_title;
		this->m_title = nullptr;
	}
	HtmlText::HtmlText(const HtmlText& toCopyFrom) :Text(toCopyFrom)
	{
		*this = toCopyFrom;
	}
	HtmlText& HtmlText::operator=(const HtmlText& toCopyFrom)
	{
		if (this != &toCopyFrom) 
		{
			Text::operator=(toCopyFrom);
			setEmpty();

			this->m_title = new char[strlen(toCopyFrom.m_title) + 1];
			strcpy(this->m_title, toCopyFrom.m_title);
		}
		return *this;
	}
	std::ostream& HtmlText::write(std::ostream& ostr) const
	{
		bool MS = false;

		ostr << "<html><head><title>";

		if (this->m_title != nullptr) 
		{
			ostr << this->m_title;
		}
		else 
		{
			ostr << "No Title";
		}

		ostr << "</title></head>\n<body>\n";

		if (this->m_title != nullptr) 
		{
			ostr << "<h1>" << m_title << "</h1>\n";
		}

		int i = 0;
		while (operator[](i) != '\0')
		{
			switch (operator[](i)) {
			case '<':
				ostr << "&lt;";
				MS = false;
				break;

			case '>':
				ostr << "&gt;";
				MS = false;
				break;

			case '\n':
				ostr << "<br />\n";
				MS = false;
				break;

			case ' ':
				if (MS) {
					ostr << "&nbsp;";
				}
				else {
					MS = true;
					ostr << " ";
				}
				break;
		
			default:
				MS = false;
				ostr << Text::operator[](i);
				break;
			}
			i++;

		}
		ostr << "</body>\n</html>";
		return ostr;
	}
}