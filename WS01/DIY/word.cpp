/*
*****************************************************************************
                              Workshop - 1 (DIY)
Full Name  : Aanand Aman
Student ID: 166125211
Email      : aaman8@myseneca.ca

Speaking Honestly, This part was very hard for me to understand, This work is not completly wine, some friends and classmates helped me to learn this code work. 
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "dictionary.h"

#include "word.h"


using namespace std;

namespace sdds
{
	void DisplayWord(const char* word)
	{
		Printing(word);
	}

	void AddWord(const char* word, const char* type, const char* definition)
	{
		Adding(word, type, definition);
	}
}