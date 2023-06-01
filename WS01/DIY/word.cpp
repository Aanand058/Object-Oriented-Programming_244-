

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