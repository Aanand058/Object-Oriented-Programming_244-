/* ------------------------------------------------------
Workshop 9 part 1

Filename: HtmlText.h
Version 1
-----------------------------------------------------------
Name: Aanand Aman
Student ID: 166125211
EMail: aaman8@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

-----------------------------------------------------------*/


#ifndef SDDS_HTMLTEXT_H_
#define SDDS_HTMLTEXT_H_
#include <iostream>
#include "Text.h"

namespace sdds
{
	class HtmlText :public Text 
	{
		char* m_title = nullptr;

	public:


		//Constructor
		HtmlText();
		HtmlText(const char* title);

		//Making the class Empty
		void setEmpty();


		//Rule of three
		HtmlText(const HtmlText& toCopyFrom);
		HtmlText& operator=(const HtmlText& toCopyFrom);
		~HtmlText();


		//Text::write override
		std::ostream& write(std::ostream& ostr) const;

	};

}

#endif